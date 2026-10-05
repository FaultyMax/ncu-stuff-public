
#  example dict
produkty = {"chleb": 5, "masło": 8, "ser": 15, "woda": 2}

nowy = {v: k for k, v in produkty.items()}
print(nowy)
