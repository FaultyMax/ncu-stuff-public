
from itertools import permutations
import math

for i, j, k in permutations("ABCD", 3):
    print(f"{i}{j}{k}", end=", ")

print(math.perm(4, 3))
