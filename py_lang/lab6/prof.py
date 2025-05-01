
lista = []

def staironacci(n,out):
		
	#print(n,out)	
	#if out != "":	
		#lista.append(out)
	if(n < 1):
		lista.append(out)
		return 1
	if(n == 1): 
		lista.append(out + " 1")
		return 1
	
	return staironacci(n-1, out + " 1") + staironacci(n-2, out + " 2")
	

def main():
	
	n = int(input())
	
	staironacci(n,"")
	
	print(len(lista))
	
	for i in lista:
		print(i.lstrip())
	
	#print(staironacci(n,"-1"))
	

main()
