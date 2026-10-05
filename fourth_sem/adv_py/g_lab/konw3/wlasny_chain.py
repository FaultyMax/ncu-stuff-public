
from itertools import chain

a = [1, 2, 3]
b = (5, 8)


class WlasnyChain:

    def __init__(self, *args):
        self.iters = args
        self.index = 0
        self.current = 0
        self.elements = len(self.iters)

    def __iter__(self):
        return self

    def __next__(self):
        while self.current < self.elements:
            if self.index < len(self.iters[self.current]):
                val = self.iters[self.current][self.index]
                self.index += 1
                return val
            self.index = 0
            self.current += 1
        raise StopIteration


for i in WlasnyChain(a, b):
    print(i)

#  for i in chain(a, b):
#    print(i)
