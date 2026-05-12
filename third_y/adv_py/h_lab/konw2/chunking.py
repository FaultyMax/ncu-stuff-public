
def podziel_na_paczki(iterable, size):
    
    container = []

    for item in iterable:
        container.append(item)

        if len(container) == size:
            yield tuple(container)
            container = []
    if container:
        yield tuple(container)


t = podziel_na_paczki([1, 2, 3, 6, 7, 9, 100], 3)

for i in t:
    print(i)
