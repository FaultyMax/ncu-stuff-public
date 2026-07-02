
def przetworz(data):

    for row in data:
        match row:
            case {"id": dict_id, **rest}:
                print(f"SUCKES {dict_id}")
            case _:
                print("no id")


data_samples = [
    {"id": 1, "name": "Jan Kowalski", "role": "Admin"},
    {"id": 2, "name": "Anna Nowak", "role": "User"},
    {"name": "Nieznajomy", "role": "Guest"},
    {"status": "active", "last_login": "2023-10-01"},
]

przetworz(data_samples)