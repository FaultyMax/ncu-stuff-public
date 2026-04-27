import math

def is_perfect_naive(n):
	
	result = 0
	
	for i in range(1,n):
	
		if n % i == 0:
			result += i
	
	if result == n and n != 0:
		return True
	else:
		return False
	# moja implementacja, O(n)

def is_perfect(n):
	if n < 2:
		return False

	result = 1
	
	for i in range(2, int(math.sqrt(n)) + 1):
		if n % i == 0:
			result += i
			if i != n // i:
				result += n // i

	return result == n
	# implementacja O(sqrt(n))


n = int(input())

for i in range(n+1):
	
	if is_perfect(i):
		print(i)
