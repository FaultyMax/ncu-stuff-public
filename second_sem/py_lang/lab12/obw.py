class Kabelek:
	def __init__(self,o,n):
		self.wytrzymalosc = o
		self.napiecie = n
	def __str__(self):
		print(f"napiecie: {self.napiecie},wytrzymalosc: {self.wytrzymalosc}")

def find_max_cir(kabelki):
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
			suma_wytrzymalosci -= kabelek.wytrzymalosc
			suma_napiec -= kabelek.napiecie
			
	return maks_liczba

n = int(input())
kable = []
for _ in range(n):
	x,y = map(int, input().split())
	kable.append(Kabelek(x,y))
	
print(find_max_cir(kable))
