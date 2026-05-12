
from random import randint
import sys

milion_lista = [randint(1, 50) for x in range(1_000_000)]

kwadraty_lista = [x*x for x in milion_lista]
kwadraty_generator = (x * x for x in milion_lista)

print(f"Lista: {sys.getsizeof(kwadraty_lista)}")
print(f"Generator: {sys.getsizeof(kwadraty_generator)}")
