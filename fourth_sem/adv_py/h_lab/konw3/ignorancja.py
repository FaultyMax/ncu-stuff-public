
class Zignoruj:

    def __init__(self, wyjatek):
        self.ignorowany = wyjatek

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, traceback):

        #  if exc_type == self.ignorowany: 
        #  that's not good enough 
        if exc_type and issubclass(exc_type, self.ignorowany):
            print("ignored...")
            return True

        return False


x = 0

with Zignoruj(ValueError) as z:
    
    for _ in range(10):
        x += 1
        if x > 7:
            raise ValueError
        print(x)
