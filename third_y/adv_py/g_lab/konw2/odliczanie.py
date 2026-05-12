
class odliczanie:

    def __init__(self, start=0):
        self.start = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.start >= 0:
            val = self.start
            self.start -= 1
        else:
            raise StopIteration
        return val


odl = odliczanie(5)
for i in odl:
    print(i)