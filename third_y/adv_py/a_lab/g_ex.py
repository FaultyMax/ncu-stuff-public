
def rozw_kwadratowe(a,b,c):
	
	delta = b*b - 4*a*c
	
	if delta > 0:
		print(f"x1 = {((-b)-(delta**0.5))/(2*a)} x2 = {((-b)+(delta**0.5))/2*a}")	
	elif delta == 0 :
		print(f"x0 = {-b/2*a}")
	else:
		print("Brak rozwiązań")

#x = input()

x = "numbers.txt"

with open(x,"rt") as f:
	for w in f:
		a,b,c = w.rsplit(' ')
		#print(f"{a}xx {b}x {c}")
		a = int(a)
		b = int(b)
		c = int(c)
		
		rozw_kwadratowe(a,b,c)
