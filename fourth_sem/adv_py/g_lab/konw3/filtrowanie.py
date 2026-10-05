
produkty = {"chleb": 5, "masło": 8, "ser": 15, "woda": 2}

for i, v in produkty.items():
    if v > 7:
        print(i)

#  or better

print([k for k, v in produkty.items() if v > 7])
