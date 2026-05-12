
from itertools import combinations
import math

my_list = [1, 2, 3, 4, 5]

for a, b in combinations(my_list, 2):
    print(f"{a}{b}", end=", ")

print(f"Długość: {math.comb(len(my_list), 2)}")
