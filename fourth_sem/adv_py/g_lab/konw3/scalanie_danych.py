
imiona = ["Anna", "Jan", "Ewa"]
nazwiska = ["Kowalska", "Nowak", "Wiśniewska"]
wiek = [25, 30, 28]

for imie, nazwisko, w in zip(imiona, nazwiska, wiek):
    print(f"{imie} {nazwisko} ma {w} lat.")
