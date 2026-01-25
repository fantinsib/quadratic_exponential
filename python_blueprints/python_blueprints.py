
from qtools.numerical import correlated_brownians
import numpy as np
from dataclasses import dataclass


class Model:
    pass

@dataclass
class BlackScholes(Model):
    """
    Class for the Black Scholes Model
    """
    mu: float
    sigma: float
    

@dataclass
class Heston(Model):
    """
    Class for the Heston Model

    Parameters
    ----------
    mu : drift
    kappa : mean-reversion speed
    theta : long-term variance
    epsilon : vol of vol
    rho : brownian correlation
    """
    mu: float
    kappa: float
    theta: float
    epsilon: float
    rho: float
#----------------------------------------
class Scheme:

    pass

    

class EulerBlackScholes(Scheme):
    def __init__(self, bs: BlackScholes):
        self.bs = bs

    def init_state(self, S0:float, v0: float | None = None):
        return S0

    def step(self, St, dt):
        """
        Returns the incremented St
        """
        r=  self.bs.mu * dt + self.bs.sigma * (dt**0.5) * np.random.normal(0,1)
        return St*(1+r)

class EulerHeston(Scheme):
    def __init__(self, h):
        self.h = h

    def init_state(self, S0: float, v0: float | None = None):
        if v0 is None : raise ValueError("EurlerHeston.step : error - vt must be specified")
        return [S0, v0]

    def step(self, state, dt: float):
        """
        One Euler step for Heston with full truncation.
        Returns (S_{t+dt}, v_{t+dt}).
        """
        St, vt = state

        v_plus = max(vt, 0.0)

        z1 = np.random.normal()
        z2 = np.random.normal()
        dW1 = np.sqrt(dt) * z1
        dW2 = np.sqrt(dt) * (self.h.rho * z1 + np.sqrt(1.0 - self.h.rho**2) * z2)

        dv = self.h.kappa * (self.h.theta - v_plus) * dt + self.h.epsilon * np.sqrt(v_plus) * dW2
        v_next = vt + dv

        dS = self.h.mu * St * dt + np.sqrt(v_plus) * St * dW1
        S_next = St + dS

        return [S_next, v_next]

class QE(Scheme):
    def __init__(self, h:Heston):
        self.h = h

    def init_state(self, S0: float, v0: float | None = None):
        return [S0, v0]
    
    def step(self, state, dt):
        S, v = state
        exp_sp = np.exp(-self.h.kappa * dt)
        EX = self.theta + (S- self.h.theta) * exp_sp
        VARX_1 = (S * (self.h.epsilon**2) * exp_sp)*(1-exp_sp)/self.h.kappa
        VARX_2 = ((self.h.theta * self.h.epsilon**2)*(1-exp_sp)**2)/(2*self.h.kappa)
        VARX = VARX_1 + VARX_2

        psi = VARX/EX**2

        if psi >= 1.5:
            


#----------------------------------------


class Engine:
    pass

class MonteCarlo(Engine):
    def __init__(self, scheme: Scheme):
        self.scheme = scheme

    def simulate(self, S0: float, n: int, T: float, v0: float | None = None, return_full_path: bool = False):
        dt = T / n
        state = self.scheme.init_state(S0, v0)

        if return_full_path:
            path = [state]
            for _ in range(n):
                state = self.scheme.step(state, dt)
                path.append(state)
            return path

        for _ in range(n):
            state = self.scheme.step(state, dt)
        return state