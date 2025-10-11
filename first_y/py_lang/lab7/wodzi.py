
n,m = map(int,input().split())

new_dict = {i+1: [] for i in range(n)}

#print(new_dict)

for x in range(m):
	
	u,v = map(int,input().split())

	new_dict[v].append(u)
	new_dict[u].append(v)
	
	'''
	if v in new_dict:
		new_dict[v].append(u)
	else:
		new_dict[v] = []
		new_dict[v].append(u)
	
	if u in new_dict:
		new_dict[u].append(v)
	else:
		new_dict[u] = []
		new_dict[u].append(v)	
	'''

temp = 1;

for key in new_dict:
	if len(new_dict[temp]) < len(new_dict[key]):
		temp = key
		
print(temp)
print(*sorted(new_dict[temp]))
