
from infinity import PotegiDwojki


def wypisz_trzy(kolekcja):
    for e in kolekcja:
        print(e[:3])


wypisz_trzy(([1, 2, 7, 0, 1010], "napis", PotegiDwojki))
