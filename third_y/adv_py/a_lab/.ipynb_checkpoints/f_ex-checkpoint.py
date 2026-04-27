from math import sqrt

def rozw_kwadratowe(a,b):
	
	delta = b*b - 4*a 
	if delta > 0:
		print(f"x1 = {((-b)-sqrt(delta))/2*a} x2 = {((-b)+sqrt(delta))/2*a}")	
	elif delta == 0 :
		print(f"x0 = {-b/2*a}")
	else:
		print("Brak rozwiązań")

def trojkat(a,b):
	if(a <= 0 or b <= 0):
		print("ujemna długość")
	else:
		print(f"Pole: {a*b/2} Obwód: {a+b+b}")
		

a = int(input())
b = int(input())

print(f"suma: {a+b} iloczyn: {a*b} ")

if(b != 0):
	print(f"dzielenie: {a/b}")
else:
	print("dzielenie przez zero jest niemożliwe")

rozw_kwadratowe(a,b)
trojkat(a,b)
