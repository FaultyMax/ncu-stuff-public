from collections import deque

def matrix_print(matrix,n):
	for i in range(n):
		for j in range(n):
			print(matrix[i][j], end=" ")
		print()
	
def matrix_mul(m1,m2,n):
	return 1

def matrix_power(matrix,n,power):
	
	ID_matrix = [[int(col == row) for col in range(n)] for row in range(n)]
	#matrix_print(ID_matrix,n)
	
	if power == 0:
		return ID_matrix 
	else:
		return matrix * matrix_power(matrix,n,power-1)
	

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


graph = {}

graph_m = []

with open("dane.txt","rt") as f:
	
	n = int(f.readline())
	
	graph_m = [[0 for _ in range(n)] for _ in range(n)]
	
	while True:
		
		line = (f.readline()).strip()
		
		if not line:
			break
		
		x = line.split()
		l = int(x[0])
		r = int(x[1])
		
		graph_m[l-1][r-1] = 1
		
		if graph.get(l) == None:
			#print("y")
			graph[l] = [r]
		else:
			graph.get(l).append(r)
			#print("n")
			
		
#print(graph)
#print(graph_m)
			

			
print(DFS(graph,1))
print(BFS(graph,1))

print(matrix_power(graph_m,n,1))
