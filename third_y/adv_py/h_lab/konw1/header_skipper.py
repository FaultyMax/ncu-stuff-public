
import csv

# Przykładowe dane
dane_csv = """id,imie,nazwisko,wiek,stanowisko
1,Jan,Kowalski,34,Programista
2,Anna,Nowak,28,Analityk
3,Piotr,Zieliński,45,Kierownik
4,Maria,Wiśniewska,31,Tester"""

# iterator_linii = iter(dane_csv.splitlines())

it = iter(dane_csv.splitlines())

header = next(it)
print(header)

reader = csv.reader(it, delimiter=",")
for row in reader:
    print(', '.join(row))
    # dodatkowo
