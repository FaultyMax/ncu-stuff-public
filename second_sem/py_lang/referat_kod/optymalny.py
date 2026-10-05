
#u = list(map(int,input().split()))
#v = list(map(int,input().split()))

u = [1,2,3,4]
v = [3,4,1,2]

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
