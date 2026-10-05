
class OdliczanieIter:
    def __init__(self, limit, start, rev=False):
        self.limit = limit
        self.start = start
        self.rev = rev

    def __iter__(self):
        return self

    def __next__(self):
        if self.rev is False:
            if self.limit >= 0:
                val = self.limit
                self.limit -= 1
            else:
                raise StopIteration
        else:       
            if self.limit <= self.start:
                val = self.limit
                self.limit += 1
            else:
                raise StopIteration
        return val


class Odliczanie:

    def __init__(self, start=0):
        self.start = start

    def __iter__(self):
        return OdliczanieIter(start=0, limit=self.start)

    def __reversed__(self):
        return OdliczanieIter(start=self.start, limit=0, rev=True)


for i in reversed(Odliczanie(5)):
    print(i)
