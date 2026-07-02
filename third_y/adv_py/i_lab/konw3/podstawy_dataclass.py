
import dataclasses


@dataclasses.dataclass
class Produkt:

    nazwa: str
    cena: float


test_data = [
    Produkt("Klawiatura mechaniczna", 299.99), # Poprawne dopasowanie
    Produkt("Myszka gamingowa", 150.00),      # Poprawne dopasowanie
    "Nie jestem produktem",                    # Błąd typu (trafi w _)
    {"nazwa": "Laptop", "cena": 4000}          # Błąd
]

for p in test_data:
    match p:
        case Produkt():
            print(f"mamy produkt {p.nazwa}")
        case _:
            print("nie produkt")
