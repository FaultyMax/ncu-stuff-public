
class Parzyste:

    def __init__(self, limit=0):
        self.limit = limit
        self._start = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self._start <= self.limit:
            val = self._start
            self._start += 2
        else:
            raise StopIteration
        return val


liczby_parzyste = Parzyste(32)

for parzysta in liczby_parzyste:
    print(parzysta)
