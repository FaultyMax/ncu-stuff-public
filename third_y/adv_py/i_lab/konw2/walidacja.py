
zdarzenia = [
    ["login", "user1"],
    ["purchase", "user2", "item1"],
    ["logout", "user1", "timestamp"],
    ["invalid"],
    ["show", "user3", "ordered_products"]
]

# add time

for komenda in zdarzenia:
    match komenda:
        case ["login", u]:
            print(f"zalogowano {u}")
            logged = u
        case ["purchase", u, i]:
            if u == logged:
                print("udany zakup")
        case ["logout", u, t]:
            if logged == u:
                print(f"wylogowano {u}")
                logged = ""
        case ["show", u, p]:
            if u == logged:
                print("show items of {u}")
        case _:
            print("INVALID")