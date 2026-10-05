
import math

def Sito(limit):
	
	pierwsza = [True] * (limit + 1)
	p = 2
	while p * p <= limit:
		if pierwsza[p]:
			for i in range(p * p, limit + 1, p):
				pierwsza[i] = False
		p += 1
	return [p for p in range(2, limit + 1) if pierwsza[p]]

def znajdz_np(n):
	
	if n < 6:
		limit = 15
	else:
		limit = int(n * (math.log(n) + math.log(math.log(n))))
		
	primes = Sito(limit)
	
	return primes[:n]

n = int(input())

n_liczb = znajdz_np(n)

for p in n_liczb:
    print(p)
