
def FF(n):
	
	if n == 0:
		return 2
	else:
		return (n+1) * FF(n-1)

def GG(n):
	if n == 0:
		return 3
	elif n == 1:
		return 5
	elif n == 2:
		return 7
	else:
		return GG(n-3) + (n-1)*GG(n-2) + GG(n-1)

n = abs(int(input()))

print(FF(n))
print(GG(n))



