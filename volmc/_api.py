from ._volmc import _State
from ._volmc import _Path
from ._volmc import _Model, _BlackScholes, _Heston
from ._volmc import _EulerHeston, _EulerBlackScholes, _QE, _Scheme
from ._volmc import _MonteCarlo


class State:
    def __init__(self, cpp_State):
        """
        State of the spot and the volatility at a time t.

        Returns
        -------
        State
        """
        self._s = cpp_State

    def __repr__(self):
        return f"State(S={self._s._spot():.4f}, V = {self._s._vol():.4f})"
    
    def __str__(self):
        return f"State(S={self._s._spot():.4f}, V = {self._s._vol():.4f})"
    
    def spot(self):
        """
        Returns the spot value of the current state.
        """
        self._s.spot()
    
    def vol(self):
        """
        Returns the vol value of the current state.
        """

        self._s.vol()

class Path:
    def __init__(self, cpp_Path):
        """
        Path followed by the spot and volatility over time t.

        Returns
        -------
        Path : list of State
        """
        self._p = cpp_Path
    
    def end_state(self):
        """
        Returns the end state of the path. 

        Returns
        -------
        State
        """
        s = self._p.end_state()
        return State(s)

        


class Model(_Model):
    pass

class BlackScholes(_BlackScholes):
    def __init__(self, mu:float, sigma:float):
        """
        Creates a BlackScholes model.

        Parameters
        ----------
        mu : float
            The drift of the asset.
        sigma : float 
            The volatility.
        """

        super().__init__(mu = mu, sigma = sigma)

class Heston(_Heston):
    def __init__(self, 
                mu:float, 
                kappa:float,
                theta: float,
                epsilon: float,
                rho: float):
        """
        Creates a Heston model.

        Parameters
        ----------
        mu : float
            The drift.
        kappa : float
            Mean-reversion speed.
        theta : float
            Long-term variance.
        epsilon : float
            Vol-of-vol.
        rho : float
            Spot/Vol brownian correlation
        """

        super().__init__(mu = mu, kappa=kappa, theta=theta, epsilon=epsilon, rho=rho)

    def feller_condition(self):
        return self._feller_condition()
    
class Scheme(_Scheme):
    pass


class EulerBlackScholes(_EulerBlackScholes):
    
    def __init__(self, Model):
        """
        Scheme 
        """
        super().__init__()


class EulerHeston(_EulerHeston):

    def __init__(self, Model):
        super().__init__(Model)

class QE(_QE):
    def __init__(self, Model):
        super().__init__()

class MonteCarlo(_MonteCarlo):

    def __init__(self, scheme):
        super().__init__(scheme)

    def simulate(self, S0: float, n: int, T: float, v0: float | None):
        cpp_path = super()._simulate(S0, n, T, v0)
        return Path(cpp_path)

