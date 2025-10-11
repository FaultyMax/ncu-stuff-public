
inp = int(input())

def fib(n):
	
	i = 0
	
	a = 1
	b = 0
	
	while(i<n):
		b += a
		a = b-a
		i += 1
		
	print(b)


fib(inp)
