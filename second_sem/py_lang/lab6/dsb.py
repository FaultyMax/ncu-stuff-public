
def stern_broc(n):
	
	wynik = []
	
	def oblicz(l_licznik,l_mianownik,p_licznik,p_mianownik,poziom):
		
		if poziom == 0:
			return
			
		nowy_licznik = l_licznik + p_licznik
		nowy_mianownik = l_mianownik + p_mianownik
		
		oblicz(l_licznik,l_mianownik,nowy_licznik,nowy_mianownik,poziom-1)
		wynik.append((nowy_licznik, nowy_mianownik))
		oblicz(nowy_licznik,nowy_mianownik,p_licznik,p_mianownik,poziom-1)
	
	wynik.append((0,1))
	oblicz(0,1,1,0,n)
	wynik.append((1,0))
	
	return wynik



def main():
	
	inp = int(input())
	
	out = stern_broc(inp)
	
	wynik = ""
	
	for i in out:
		wynik += f"{i[0]}/{i[1]} "
		#print(i)
	
	wynik = wynik.rstrip();
	
	#print(out)
	print(wynik)
	
	
main()
