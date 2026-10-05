
class Kwadraty:

    def __init__(self, n=0):
        self.n = n

    def __len__(self):
        return self.n

    def __getitem__(self, idx):
        if idx < 0 or idx >= self.n:
            raise IndexError("index out of bounds!")
        return idx*idx


kwadraty_do_osiem = Kwadraty(8)

for kwadrat in kwadraty_do_osiem:  # type: ignore[attr-defined]
    print(kwadrat)
