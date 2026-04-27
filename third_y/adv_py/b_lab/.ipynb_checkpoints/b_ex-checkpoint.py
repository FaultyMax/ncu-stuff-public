
def silnia_it(x):
	res = 1
	for i in range(1,x+1):
		res *= i
		print(f"\n{locals()}\n")
		print(f"\n{globals()}\n")
	return res

def silnia_rek(x):
	if x == 0:
		return 1
	else:
		print(f"\n{locals()}\n")
		print(f"\n{globals()}\n")		
		return x * silnia_rek(x-1)
	

print(silnia_it(2))
print(silnia_rek(2))

# nie widze różnicy
