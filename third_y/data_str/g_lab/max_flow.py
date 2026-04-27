from collections import deque

graph = dict()

def BFS(residual, start, dest):
    queue = deque([start])
    visited = {start}
    parent = {start: None}

    while queue:
        node = queue.popleft()

        for neigh, cap in residual.get(node, []):
            if neigh not in visited and cap > 0:
                visited.add(neigh)
                parent[neigh] = node

                if neigh == dest:
                    path = []
                    cur = dest
                    while cur is not None:
                        path.append(cur)
                        cur = parent[cur]
                    return path[::-1], parent

                queue.append(neigh)

    return None, None


def build_residual(graph):
    residual = {}

    for u in graph:
        for v, w in graph[u]:

            residual.setdefault(u, []).append([v, w])

            residual.setdefault(v, []).append([u, 0])

    return residual


def find_capacity(residual, path):
    flow = float("inf")

    for i in range(len(path) - 1):
        u = path[i]
        v = path[i + 1]

        for neigh, cap in residual[u]:
            if neigh == v:
                flow = min(flow, cap)

    return flow


def update_residual(residual, path, flow):
    for i in range(len(path) - 1):
        u = path[i]
        v = path[i + 1]

        for edge in residual[u]:
            if edge[0] == v:
                edge[1] -= flow

        for edge in residual[v]:
            if edge[0] == u:
                edge[1] += flow


def max_flow(graph, source, sink):
    residual = build_residual(graph)
    flow = 0

    while True:
        path, parent = BFS(residual, source, sink)

        if path is None:
            break

        bottleneck = find_capacity(residual, path)
        update_residual(residual, path, bottleneck)

        flow += bottleneck

    return flow


with open("dane2.txt","rt") as f:
	
	T = f.readline().strip()
	
	if T == "L":
		
		V = int(f.readline())
		for line in f:
			line = line.strip()
			if not line:
				continue

			l, r, w = line.split()
			w = int(w)

			graph.setdefault(l, []).append((r, w))
			graph.setdefault(r, [])
			
	else:
		
		
		graph_conv = []
		
		rows, columns = map(int, f.readline().split())
		
		for line in f:
			line = line.strip().replace(" ", "")
			row = []
			for num in line:
				row.append(int(num))
			graph_conv.append(row)
		
		for i,row in enumerate(graph_conv, 1):
			for j,column in enumerate(row,rows+1):
				if column == 1:
					graph.setdefault(str(i), []).append((j, 1))
					graph.setdefault(str(j), [])
		
			
			
		


print("Graph:", graph)
print("Max flow:", max_flow(graph, "S", "T"))
