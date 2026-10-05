
def rozwiaz(inp):
	
	stack = []
	
	otwarcia = {'(', '{', '[', '<'}

	nawiasy = {

	')': '(',
	'}': '{',
	']': '[',
	'>': '<'
		
	}

	for char in inp:
		
		if char in otwarcia:
			
			stack.append(char)
			
		elif char in nawiasy.keys():
			if not stack or stack.pop() != nawiasy[char]:
				return "N"
	
	if not stack:
		return "T"
	else:
		return "N"

def Main():
		
	n = int(input())	
	
	for i in range(n):

		print(rozwiaz(input()))

Main()
	
	
# () {} [] <>

# ())
# (]
# (()
