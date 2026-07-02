
from contextlib import redirect_stdout

with open('logi.txt', 'w') as f:
    with redirect_stdout(f):
        for i in range(1, 101):
            print(i)
