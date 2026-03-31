
n = int(input())
m = int(input())

for i in range(1,m+1):
	tmp = n * i
	if tmp < m:
		print(tmp)
