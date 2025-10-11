
def operate(a,b,m):
	
	if m == 'M':
		return a*b
	elif m == 'O':
		return b-a
	elif m == 'D':
		return a+b

def calc(n):
	
	operacje = {'M','O','D'}
	
	stack = []
	
	w = 0
	
	for i in n:
		
		if i in operacje:
			
			first = stack.pop()
			second = stack.pop()
				
			stack.append(operate(first,second,i))
				
		else:
			stack.append(int(i))

	w = stack[0]

	return w

def Main():

	n = int(input())

	for i in range(n):
		
		inp = input().split()
		
		print(calc(inp))
		

Main()		
