
def suma_iteratywna(x):
    my_sum = 0
    for i in range(x+1):
        my_sum += i
        print(f"\n{locals()}\n")
        print(f"\n{globals()}\n")
    return my_sum

def suma_rekurencyjna(x):
	if x == 0:
		return 0
	else:
		print(f"\n{locals()}\n")
		print(f"\n{globals()}\n")
		return x + suma_rekurencyjna(x-1)
	
	

a = suma_iteratywna(10)
b = suma_rekurencyjna(10)
print(f"{a} i {b}")



# W jaki sposób zmieniają się zmienne lokalne i globalne w zależności od sposobu implementacji (rekurencja kontra iteracja)?
# iteratywny sposób pozwala nam zobaczyć wynik w każdej iteracji, znajduje sie w zmiennych lokalnych.
# Pod koniec wynik znajduje sie w zmiennych globalnych
# rekurencyjny sposób nie ma takiego dostępu, jest dostępny tylko wynik końcowy pod koniec rekurencji w zmiennych globalnych

def sum2(x):
	return sum(range(x + 1))
	
print(sum2(10))
	
	
# Podobno rekurencja ma więcej ramek
# PamięćO(1) dla iteracji
# PamięćOn(n) dla rekurencji
	
