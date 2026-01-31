from volmc import MonteCarlo, Heston, QE
import time

n_paths = 500_000
repeat = 10

elapsed = 0




for t in range(repeat+1):
    heston = Heston(0.02, 2.0, 0.04, 0.3, 0.0)
    mc1 = MonteCarlo(QE(heston))
    mc1.configure(1, 1)

    t0 = time.perf_counter()
    mc1.generate(100, 252, 1, n_paths, 0.2)

    t1 = time.perf_counter()
    if t != 0:
        print(f"No MT run {t} : {t1-t0}")

        elapsed += t1 - t0
    else:
        print(f"warmup : {t1-t0}")
print(f"No mt : {(elapsed/repeat):.6f} s")
##########################################

elapsed = 0
for t in range(repeat):
    heston = Heston(0.02, 2.0, 0.04, 0.3, 0.0)
    mc2 = MonteCarlo(QE(heston))
    mc2.configure(1, -1)

    t0 = time.perf_counter()
    mc2.generate(100, 252, 1, n_paths, 0.2)

    t1 = time.perf_counter()
    print(f"MT run {t} : {t1-t0}")

    elapsed += t1 - t0
print(f"With mt : {(elapsed/repeat):.6f} s")