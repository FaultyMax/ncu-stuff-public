
input_list = []


def take_input():
    return input()


for i in iter(take_input, "KONIEC"):
    if i == "KONIEC":
        break
    input_list.append(i)


txt = "\t".join(input_list)
print(txt)
