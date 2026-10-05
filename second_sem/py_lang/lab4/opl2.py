
a,b = map(int, input().split())
c,d = map(int, input().split())

il = a*b*c*d

rozm = input()

A,B = map(int,rozm.split())

tab = [list(map(int, input().split())) for _ in range(A)]

count = 0

if A >= 2 and B >= 2:
	for i in range(A - 1):
		for j in range(B - 1):
			per = tab[i][j] * tab[i][j + 1] * tab[i + 1][j] * tab[i + 1][j + 1]
			if il == per:
				count += 1


print(count)
