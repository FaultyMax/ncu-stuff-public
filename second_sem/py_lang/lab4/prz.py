
inp = int(input())

prz = []

for i in range(inp):
	
	row = list(map(int, input().split()))
	prz.append(row)	
	
	
prz.sort(reverse=False)
	
odp = max(prz[1][0]-prz[0][1],0)

print(odp)



