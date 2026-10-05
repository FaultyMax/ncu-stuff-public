
class CoDrugi:

    def __init__(self, lista):
        self.lista = lista
        self.index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.index >= len(self.lista):
            raise StopIteration

        val = self.lista[self.index]
        self.index += 2
        return val


for e in CoDrugi([1, 5, "a", 6, 7, "b"]):
    print(e)
