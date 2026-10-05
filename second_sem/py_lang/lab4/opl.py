
a,b = map(int, input().split())
c,d = map(int, input().split())

il = a*b*c*d

A,B = map(int,input().split())

#tab = [list(map(int, input().split())) for _ in range(A)]

count = 0

row = list(map(int, input().split()))

prdcts = [row[j] * row[j + 1] for j in range(B - 1)]

for i in range(A - 1):
	
	curr_row = list(map(int, input().split()))
	
	curr_products = [curr_row[j] * curr_row[j + 1] for j in range(B - 1)]
	
	for j in range(B - 1):
		if prdcts[j] * curr_products[j] == il:
			count += 1

	row = curr_row
	prdcts = curr_products

print(count)
