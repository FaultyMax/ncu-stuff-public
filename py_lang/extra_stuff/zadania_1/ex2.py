
inp = map(int,input().split())

lista = [0]*2038

#print(lista)

tmaximum = 0

for i in inp:
	
	if i >= 0:
		
		lista[i] += 1
				
		if lista[i] > tmaximum:
			tmaximum += 1
			
	if i < 0:
		
		lista[abs(i)+1018] += 1
		
		if lista[abs(i)+1018] > tmaximum:
			tmaximum += 1
		
	
win = []	

for j in range(len(lista)):
	
	if lista[j] == tmaximum:
		if j <= 1018:
			win.append(j)
		else:
			print(j)
			win.append(-j+1018)
		
	

		
print(sorted(win)[len(win)-1])
	
	
