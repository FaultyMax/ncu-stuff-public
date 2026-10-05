
import time


class Timer:

    def __init__(self):
        self.time = 0

    def __enter__(self):
        self.time = time.perf_counter()

    def __exit__(self, exc_type, exc_value, traceback):
        print(time.perf_counter() - self.time)


with Timer() as t:

    # sztucznie ciężkie obliczenia

    result = 0

    for i in range(50_000_000):
        result += (i ** 2) % 1234567

    print(result)
