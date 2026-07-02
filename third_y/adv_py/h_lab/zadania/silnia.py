
import itertools


def silnia():
    res, i = 1, 1
    while True:
        yield res
        res *= i 
        i += 1


# wariant 1
gen1 = silnia()
suma1 = sum(itertools.islice(gen1, 0, 21, 2))

# wariant 2
gen2 = silnia()
suma2 = 0
for i, val in enumerate(gen2):
    if i > 20:
        break
    
    if i % 2 == 0:
        suma2 += val

print(f"{suma1} {suma2}")
