
tab = [0] * 500

dane = open("dane.txt","r")
testuj = open("testuj.txt","w");

for l in dane:
	n = int(l.rstrip())
	tab[n-1] += 1
	
# liczba zapisywana jest w indeksie o jeden mniejszym od niej np: 1 -> tab[0]
	
for i,v in enumerate(tab):
	if v == 1:
		testuj.write(str(i+1))
		testuj.write("\n")
		
		
dane.close()
testuj.close()
	
