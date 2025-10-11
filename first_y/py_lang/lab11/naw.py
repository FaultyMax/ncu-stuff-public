
def rozwiaz(s):
		stack = []
		op = {'(', '[', '{', '<'}
		mapping = {')': '(', '}': '{', ']': '[', '>': '<'}
		
		for char in s:
			if char in op: 
				stack.append(char)
			elif char in mapping.keys(): 
				if not stack or stack.pop() != mapping[char]:
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
