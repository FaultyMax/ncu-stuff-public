
nowy_dict = dict()

k = input()
l = input()

def anagram():
	for i in nowy_dict:
		if nowy_dict[i] % 2 == 1:
			return "NIE"
		return "TAK"

for litera in k:
	if litera in nowy_dict:
		nowy_dict[litera] += 1
	else:
		nowy_dict[litera] = 1
		
for litera in l:
	if litera in nowy_dict:
		nowy_dict[litera] += 1
	else:
		nowy_dict[litera] = 1	
		
		
print(anagram())
