import sys;

def main():

	inp = sys.stdin.readline()
	n,k = map(int,inp.split())
	
	szereg = (sys.stdin.readline()).split()

	# przyjęcie wejścia

	dziewczynki = [i for i, x in enumerate(szereg) if x == '0']
	
	S = len(dziewczynki)

	# tablica dziewczynek

	if k > S:
		print("NIE")
		return
		
	# gdy nie ma wystarczająco dziewczynek

	min_1 = 1000001

	for i in range(S - k + 1):
		
		first = dziewczynki[i]
		last = dziewczynki[i + k - 1]
		
		current = (last - first + 1) - k
		
		if current < min_1:
			min_1 = current
			if min_1 == 0:
				break
		

	print(min_1)

main()

# np
# 8 3
# 0 1 1 0 1 0 1 0
# OUTPUT: 2

# 0 dziewczynka, 1 chłopiec

