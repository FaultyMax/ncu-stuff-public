import random

a = 1
b = 30

print("Wymysl liczbe od 1 do 30! Czy jestes gotowy?")

n = input()

while True:
	
	x = random.randint(a,b)
	
	print(f"Czy ta liczba to: {x}? [Y|N]")
	
	n = input()
	
	if n == "Y" or n == "y":
		print("Dobra gra!")
		break
	elif n == "N" or n == "n":
		print("Czy liczba była większa czy mniejsza? [>|<]")
		
		n = input()
		
		if n == ">":
			a = x+1
		elif n == "<":
			b = x-1
	else:
		break
	
	if a == b:
		print(f"Przegrałem! liczba musi wynosić {a}")
		break;
	
	#print(f"kontrolne a : {a} b : {b}")
