
from math import isqrt


def primes():
    n = 2

    while True:
        is_prime = True

        for i in range(2, isqrt(n) + 1):
            if n % i == 0:
                is_prime = False
                break

        if is_prime:
            yield n

        n += 1


pr = primes()

print([next(pr) for _ in range(8)])
