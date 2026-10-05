
def FF(n):
	print(f"\n{locals()}\n")
	if n == 0:
		return 2
	else:
		return (n+1) * FF(n-1)

def GG(n):
	if n == 0:
		print(f"\n{locals()}\n")
		return 3
	elif n == 1:
		print(f"\n{locals()}\n")
		return 5
	elif n == 2:
		print(f"\n{locals()}\n")
		return 7
	else:
		print(f"\n{locals()}\n")
		return GG(n-3) + (n-1) * GG(n-2) + GG(n-1)


#FF(6)
GG(4)

# bardzo duża ilość ramek dla rekurencji
