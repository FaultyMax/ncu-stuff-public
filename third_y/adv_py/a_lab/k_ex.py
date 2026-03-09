import sys

def wyswietl():
	n = len(sys.argv)
	print(f"{sys.argv[0]} \n{n} \n{sys.argv}")
	
	
def operacje(a,b):
	print(a+b)
	print(a-b)
	print(a*b)
	if b != 0:
		print(a/b)
	
wyswietl()

a = int(sys.argv[1])
b = int(sys.argv[2])

operacje(a,b)
