class Kabelek:
    def __init__(self, x, y):
        self.wytrzymalosc = x
        self.napiecie = y
    
    def __repr__(self):
        return f"Kabelek(x={self.wytrzymalosc}, y={self.napiecie})"

def znajdz_maksymalne_kolo(kabelki):
    kabelki.sort(key=lambda k: (k.napiecie, k.wytrzymalosc))
    
    suma_wytrzymalosci = 0
    suma_napiec = 0
    maks_liczba = 0
    
    for kabelek in kabelki:
        suma_wytrzymalosci += kabelek.wytrzymalosc
        suma_napiec += kabelek.napiecie
        
        if suma_wytrzymalosci >= suma_napiec:
            maks_liczba += 1
        else:
            # Jeśli warunek nie jest spełniony, cofamy ostatnią operację
            suma_wytrzymalosci -= kabelek.wytrzymalosc
            suma_napiec -= kabelek.napiecie
    
    return maks_liczba

n = int(input())
kabelki = []
for _ in range(n):
    x, y = map(int, input().split())
    kabelki.append(Kabelek(x, y))

print(znajdz_maksymalne_kolo(kabelki))
