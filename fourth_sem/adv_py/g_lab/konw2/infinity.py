
class PotegiDwojki:

    def __init__(self):
        self.n = 1

    def __iter__(self):
        return self

    def __next__(self):
        val = self.n
        self.n *= 2
        return val


def main():
    for i in PotegiDwojki():
        print(i)
        if i >= 512:
            break    


if __name__ == "__main__":
    main()
