
n = int(input())

new_dict = dict()

for x in range(n):
	inp = int(input())
	
	if inp in new_dict:
		print("N")
	else:
		print("T")
		new_dict[inp] = 1
	
	

