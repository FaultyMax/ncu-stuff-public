
#u = list(map(int,input().split()))
#v = list(map(int,input().split()))

u = [1,2,3,4]
v = [3,4,1,2]

if len(u) != len(v):
	exit

n = len(u)

def optymalny(u,v):
	
	i = -1
	j = -1
	
	while True:
		
		if i > n-1 or j > n-1:
			return False
			
		k = 1
		
		while u[(i+k) % n] == v[(j+k) % n] and k <= n:
			print(f"u[({i}+{k}) % {n}] == v[({j}+{k}) % {n}]")
			print(f"{u[(i+k) % n]} == {v[(j+k) % n]}")
			k += 1
			
		if k > n:
			return True

		print(f"u[({i}+{k}) % {n}] == v[({j}+{k}) % {n}]")
		print(f"{u[(i+k) % n]} == {v[(j+k) % n]}")

		if u[(i+k) % n] > v[(j+k) % n]:
			print(f"nowe i: {i} + {k} = {i+k}")
			i += k
		else:
			print(f"nowe j: {j} + {k} = {j+k}")
			j += k
			
print(optymalny(u,v))
