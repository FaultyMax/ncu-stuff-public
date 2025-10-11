# czekolada

inp1 = input()

a,b = map(int,inp1.split())

c = int(input())

#print(a,b,c)

if((c%a == 0 or c%b == 0) and (a*b > c)):
	print("TAK")
else:
	print("NIE")

