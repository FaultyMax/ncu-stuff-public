
def fib_generator(n):
    x, y = 1, 1
    while x <= n:
        yield x
        x, y = y, x + y
    return


print(list(fib_generator(50)))
