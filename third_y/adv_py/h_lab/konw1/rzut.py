
from random import randint

my_results = []


for i in iter(lambda: randint(1, 6), 6):
    my_results.append(i)

print(my_results)
