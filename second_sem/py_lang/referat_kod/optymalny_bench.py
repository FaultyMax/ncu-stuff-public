import time 

start_t = time.perf_counter()

u = list(map(int,input().split()))
v = list(map(int,input().split()))

n = len(u)

if len(u) != len(v):
	exit

def optymalny(u,v):
	
	i = -1
	j = -1
	
	while True:
		
		if i > n-1 or j > n-1:
			return False
		k = 1
		
		while u[(i+k) % n] == v[(j+k) % n] and k <= n:
			k += 1
			
		if k > n:
			return True

		if u[(i+k) % n] > v[(j+k) % n]:
			i += k
		else:
			j += k
			
print(optymalny(u,v))

end_t = time.perf_counter()

print(f"Czas wykonania: {end_t-start_t:.8f} sekund")



