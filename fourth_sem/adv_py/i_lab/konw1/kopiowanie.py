
#  naiwne
def kopiuj(plik_a, plik_b):

    with open(plik_a, "r") as f1, open(plik_b, "w") as f2:
        f2.write(f1.read())


#  lepsze
def lepszy_kopiuj(plik_a, plik_b):
    with open(plik_a, "rb") as f1, open(plik_b, "wb") as f2:

        while chunk := f1.read(8192):
            f2.write(chunk)
