
baza = dict()

n = int(input())

for i in range(n):
	
	nazwa = input()
	
	if nazwa in baza:
		baza[nazwa] += 1
		print(nazwa + str(baza[nazwa]))
	else:
		baza[nazwa] = 0
		print("OK")
