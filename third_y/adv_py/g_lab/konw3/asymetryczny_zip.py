
from itertools import zip_longest

a = [1, 2, 3]
b = ["A", "B"]

for x, y in zip_longest(a, b, fillvalue="Nieznane"):
    print(f"{x}{y}")
