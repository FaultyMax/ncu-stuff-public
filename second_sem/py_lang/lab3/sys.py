
cyfry = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#a = input()
#b = int(input())
#c = int(input())

inp1 = input()

a,b,c = inp1.split()

b = int(b)
c = int(c)

def konwerter(x,y,z):
	
	tmp = x
	
	if(y != 10):
		tmp = x_to_dec(x,len(x),y);
	
	napis = []
	
	tmp = int(tmp)
	
	while(tmp != 0):
		
		
		r = tmp % z
		napis.append(r)
		tmp = tmp // z
	
	
	napis.reverse()
	
	result = ""
	
	for i in range(len(napis)):
		
		napis[i] = cyfry[napis[i]]
		result += napis[i]
		
	
	print(result)
	
	

# schemat hornera

def x_to_dec(wielomian,n,x):

	plchldr = []

	for i in range(n):
		plchldr.append(wielomian[i])
		plchldr[i] = cyfry.index(plchldr[i])

	wynik = plchldr[0]

	for i in range(1, n):
 
		wynik = wynik*x + plchldr[i]
        
  
  
	return wynik


konwerter(a,b,c)
