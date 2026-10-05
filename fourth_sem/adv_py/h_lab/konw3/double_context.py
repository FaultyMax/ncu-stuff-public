
with open("wejscie.txt", "r") as fin, open("wyjscie.txt", "w") as fout:

    for line in fin:
        fout.write(line.upper())
