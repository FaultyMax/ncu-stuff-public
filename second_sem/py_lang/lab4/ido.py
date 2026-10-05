
inp = input()

L,R = map(int,inp.split())

isknown = [0]*L



for i in range(R):
	inp = input()
	A,B = map(int,inp.split())
	
	isknown[A-1] = isknown[A-1] - 1 
	isknown[B-1] = isknown[B-1] + 1 
	
	#print(isknown)
	
	
	
	
	
mx = 0;

l = []

for i in range(len(isknown)):
	
	if (isknown[i] > mx):
		mx = isknown[i]

for i in range(len(isknown)):
	
	if (isknown[i] == mx):
		l.append(i+1)



	
print(f"{max(l)} {mx}")
	
