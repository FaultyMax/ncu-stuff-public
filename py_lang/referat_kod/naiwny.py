
#u = list(map(int,input().split()))
#v = list(map(int,input().split()))

u = [1,2,3,4]
v = [3,4,1,2]

def naiwny(u,v):
	
	n = len(u)

	if len(u) != len(v):
		return False
	
	for k in range(n):

		#print(u[k+1:] + u[:k+1])

		if (v == u[k:] + u[:k]):
			print(f"tak! {k}")
			return True
		
	print("nie!")
	return False

naiwny(u,v)

# inputem są dwa ciagi całkowitoliczbowe

