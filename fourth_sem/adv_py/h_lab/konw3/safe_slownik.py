
import copy


class BezpiecznySlownik:

    def __init__(self, dane):
        self.slownik = dane

    def __enter__(self):

        self._backup = copy.deepcopy(self.slownik)

        return self._backup

    def __exit__(self, exc_type, exc_value, traceback):
        
        if exc_type:
            print("Wyjątek. Rollback.")
            return False

        self.slownik.clear()
        self.slownik.update(self._backup)

        print("Zmiany zapisane.")


dane = {"a": 1, "b": {"c": 2}}

with BezpiecznySlownik(dane) as roboczy:
    roboczy["a"] = 100
    roboczy["b"]["c"] = 999

print(dane)


dane = {"a": 1}

try:
    with BezpiecznySlownik(dane) as roboczy:
        roboczy["a"] = 999
        raise ValueError

except ValueError:
    pass

print(dane)