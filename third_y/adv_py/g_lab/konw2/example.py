import itertools


class ParaIter:
    def __init__(self, para):
        self.para = para
        self.idx = -1

    def __iter__(self):
        return self

    def __next__(self):
        self.idx += 1
        if self.idx == 0:
            return self.para.a
        if self.idx == 1:
            return self.para.b
        
        raise StopIteration


class Para:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __iter__(self):
        return ParaIter(self)


'''
p = Para(1, 2)
for i in p:
    print(i)
'''


class Para2:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        
    def __len__(self):
        return 2

    def __getitem__(self, idx):
        if idx == 0:
            return self.a
        if idx == 1:
            return self.b
        raise IndexError("index != 0,1")


'''
p = Para2(4, 7)
for i in p:
    print(i)
'''


class Fib:
    def __init__(self):
        self.x, self.y = 0, 1

    def __iter__(self):
        return self

    def __next__(self):
        self.x, self.y = self.y, self.x + self.y
        return self.x


'''
f = Fib()
for i in range(13):
    print(next(f), end=", ")
'''


print(list(itertools.islice(Fib(), 15)))
