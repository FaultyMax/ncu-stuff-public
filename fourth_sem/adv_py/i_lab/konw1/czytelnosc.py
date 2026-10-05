
def sum_to_n(n):
    s = 0
    i = 0
    while (i := i + 1) <= n:
        s += i
    return s


print(sum_to_n(10))

'''
matematycznie najbardziej poprawne
def sum_to_n(n):
    return n * (n + 1) // 2

najbardziej pythonowe
def sum_to_n(n):
    return sum(range(1, n + 1))
'''
