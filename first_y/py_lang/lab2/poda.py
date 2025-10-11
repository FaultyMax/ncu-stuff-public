
def is_prime(n):
	
	if(n <= 1):
		return False
	if(n == 2 or n == 3):
		return True
	if(n % 2 == 0 or n % 3 == 0):
		return False
	i = 5
	while( i*i <= n):
		if(n % i == 0 or n % (i + 2) == 0):
			return False
		i += 6
			
	return True

inp = int(input())

if(inp % 2 == 0 and inp != 2):
	# z hipotezy goldbacha.
	print(2)
elif(is_prime(inp)):
	print(1)
else:
	#znajdz liczbe pierwsza
	x = 1
	for i in range(inp-1,0,-1):
		if(is_prime(i)):
			x = inp-i
			break
	if(x == 2):
		print(2)
	else:
		# również z hipotezy goldenbacha ( 1 + 2 )
		print(3)
	
	
