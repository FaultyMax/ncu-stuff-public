

def szukaj_w_logach(nazwa_pliku, slowo_klucz):
    with open(nazwa_pliku, "r") as f:
        for line in f:
            if slowo_klucz in line:
                yield line


for line in szukaj_w_logach("zen.txt", "idea"):
    print(line)
