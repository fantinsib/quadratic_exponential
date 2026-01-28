import pytest
from volmc import BlackScholes, Heston


def test_black_scholes_constructor_valid():

    bs = BlackScholes(0.01, 0.2)
    assert(isinstance(bs, BlackScholes))

    bs_zero = BlackScholes(0.01, 0.0)
    assert(isinstance(bs_zero, BlackScholes))


def test_black_scholes_constructor_invalid_sigma():

    with pytest.raises(ValueError):
        BlackScholes(0.01, -0.0001)


def test_heston_constructor_valid_params():

    h = Heston(0.02, 1.5, 0.04, 0.3, -0.7)
    assert(isinstance(h, Heston))

    Heston(0.02, 1.0, 0.04, 0.3, -1.0)
    Heston(0.02, 1.0, 0.04, 0.3, 1.0)


def test_heston_constructor_invalid_params():

    with pytest.raises(ValueError):
        Heston(0.02, 0.0, 0.04, 0.3, 0.0)

    with pytest.raises(ValueError):
        Heston(0.02, 1.0, 0.0, 0.3, 0.0)

    with pytest.raises(ValueError):
        Heston(0.02, 1.0, 0.04, 0.0, 0.0)

    with pytest.raises(ValueError):
        Heston(0.02, 1.0, 0.04, 0.3, -1.1)

    with pytest.raises(ValueError):
        Heston(0.02, 1.0, 0.04, 0.3, 1.1)


def test_heston_feller_condition_flags():

    h_ok = Heston(0.02, 2.0, 0.04, 0.3, 0.0)
    h_bad = Heston(0.02, 0.5, 0.01, 1.0, 0.0)

    assert(h_ok.feller_condition() == True)
    assert(h_bad.feller_condition() == False)
