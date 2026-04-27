from collections import deque

INF = 10000000

def matrix_print(matrix,n):
	for i in range(n):
		for j in range(n):
			print(matrix[i][j], end=" ")
		print()

def matrix_mul(matrix1,matrix2,n):
	
	new_m = [[0] * n for _ in range(n)]
		
	for i in range(n):
		for j in range(n):
			m_sum = 0
			for k in range(n):
				m_sum += matrix1[i][k] * matrix2[k][j]				
			new_m[i][j] = m_sum
			
	return new_m

def matrix_power(matrix,n,power):
	
	ID_matrix = [[int(col == row) for col in range(n)] for row in range(n)]
	
	if power == 0:
		return ID_matrix 
	else:
		return matrix_mul(matrix,matrix_power(matrix,n,power-1),n)
	

def DFS(graph,v):
	
	stack = [v]
	visited = {v}
	
	res = []
	
	while stack:
		node = stack.pop()
		res.append(node)
		edges = graph.get(node, [])
		for edge in reversed(edges):
			if edge not in visited:
				visited.add(edge)
				stack.append(edge)
	
	return res
	
def BFS(graph,v):
	
	queue = deque()
	visited = {v}
	
	queue.append(v)
	res = []
	
	while queue:
		node = queue.popleft()
		res.append(node)
		edges = graph.get(node, [])
		for edge in edges:
			if edge not in visited:
				visited.add(edge)
				queue.append(edge)
	
	return res

def Dijkstra(Graph,start):
	
	dist = {}
	prev = {}
	visited = {}
	
	for v in Graph.keys():
		dist[v] = INF
		prev[v] = None
		visited[v] = False
		
	dist[start] = 0
	Q = []
	Q.append((0,start))
	
	while Q:
		d,u = min(Q)
		Q.remove((d,u))
		
		if visited[u]:
			continue
		
		visited[u] = True
		
		for edge in Graph[u]:
			new_dist = dist[u] + Graph[u][edge]
			if new_dist < dist[edge]:
				dist[edge] = new_dist
				prev[edge] = u
				Q.append((new_dist,edge))
				
	return dist, prev
	

graph = {}

graph_m = []

graph_weighted = {}

with open("dane.txt","rt") as f:
	
	n = int(f.readline())
	
	graph_m = [[0 for _ in range(n)] for _ in range(n)]
	
	for i in range(1, n + 1):
		graph[i] = []
		graph_weighted[i] = {}
	
	for line in f:
		
		line = line.strip()
		
		if not line:
			continue
		
		l,r = map(int, line.split())
		#l = int(x[0])
		#r = int(x[1])
		
		weight = ((l+r) % 5) + 1
		
		graph_m[l-1][r-1] = 1
		graph[l].append(r)
		graph_weighted[l][r] = weight	
			
print(DFS(graph,1))
print(BFS(graph,1))

t = matrix_power(graph_m,n,4)
matrix_print(t,n)

# dla grafów ważonych wykorzystam słownik słówników

print(graph_weighted)

dis,pre = Dijkstra(graph_weighted,1)

print(dis,pre)
