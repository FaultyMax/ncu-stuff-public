
graph = []

INF = 99999999

def BellmanFord(V,Graph,source):
	
	dis = [INF] * V
	prev  = [None] * V
	dis[source] = 0
	
	cycle = set()
	cycle_entry = None
	
	for i in range(V):
		for edge in Graph:
			u,v,w = edge
			if dis[v] > dis[u] + w:					
				
				dis[v] = dis[u] + w
				prev[v] = u
				
				if i == V - 1:
					cycle_entry = v
	
	has_cycle = cycle_entry is not None
	
	if has_cycle:
		x = cycle_entry
		for _ in range(V):
			x = prev[x]
		
		start = x
		cycle.add(start + 1)
		x = prev[x]
		while x != start:
			cycle.add(x + 1)
			x = prev[x]
	
	prev_ret = [x+1 if x is not None else x for x in prev]
	cycle_list = [x for x in cycle]
	
	if has_cycle:
		print("wykryto cykl ujemny!")
		return cycle_list,prev_ret
	else:
		return dis,prev_ret
	

with open("dane.txt","rt") as f:
	
	V = int(f.readline())
	
	for line in f:
		
		line = line.strip()
		
		if not line:
			continue
		
		l,r,w = map(int, line.split())
		
		l -= 1 #
		r -= 1 #
		
		edge = [l,r,w]
		
		graph.append(edge)


source = 0 # 1

d,p = BellmanFord(V,graph,source)

print(d,p)

