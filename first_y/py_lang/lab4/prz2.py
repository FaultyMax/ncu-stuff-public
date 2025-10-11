n = int(input())
intervals = [tuple(map(int, input().split())) for _ in range(n)]

# Sortowanie przedziałów
intervals.sort()

min_diff = float('inf')

# Przetwarzanie przedziałów
for i in range(1, n):
	if intervals[i][0] <= intervals[i-1][1]:
		min_diff = 0
		break
		
	diff = intervals[i][0] - intervals[i-1][1]
	
	if diff < min_diff:
		min_diff = diff
		if min_diff == 1:
			break

print(min_diff)
