
from itertools import zip_longest


#  Nigdy bym na to nie wpadł
def przeplatacz(*kontenery):
    
    for grupa in zip_longest(*kontenery, fillvalue=None):

        for x in grupa:
            if x is not None:
                yield x


gen = przeplatacz([1, 2, 3], ["A", "B"])
for i in gen:
    print(i)


# 1 A 2 B 3
