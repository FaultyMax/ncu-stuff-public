
example_list = [3, 5, 8, 10]


def szescian(x):
    return x**3


szesciany = [wynik for x in example_list if (wynik := szescian(x)) > 100]
print(szesciany)
