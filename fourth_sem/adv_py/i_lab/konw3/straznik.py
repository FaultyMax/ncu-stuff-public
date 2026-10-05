
def straznik(dane):
    for row in dane:
        match row:
            case {"rola": r, "wiek": w} if w >= 18 and r == "admin":
                print(r)
            case {"rola": r, "wiek": w} if w < 18 and r == "admin":
                print("admin za mały wiek")
            case _:
                print("nie admin")


test_users = [
    {"rola": "admin", "wiek": 25},  # Powinien przejść (Admin >= 18)
    {"rola": "admin", "wiek": 15},  # Powinien trafić w drugi case (Admin < 18)
    {"rola": "user", "wiek": 30},   # Powinien trafić w default case (Nie admin)
    {"rola": "gość", "wiek": 10},   # Powinien trafić w default case
]

straznik(test_users)
