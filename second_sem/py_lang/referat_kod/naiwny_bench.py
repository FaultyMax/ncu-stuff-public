import time 

start_t = time.perf_counter()

u = list(map(int,input().split()))
v = list(map(int,input().split()))

def naiwny(u,v):
	
	n = len(u)

	if len(u) != len(v):
		print("unequal length!")
		return False
	
	for k in range(n):

		if (v == u[k:] + u[:k]):
			
			return True
	
	return False

print(naiwny(u,v))
end_t = time.perf_counter()
print(f"Czas wykonania: {end_t-start_t:.8f} sekund")

# inputem są dwa ciagi całkowitoliczbowe
