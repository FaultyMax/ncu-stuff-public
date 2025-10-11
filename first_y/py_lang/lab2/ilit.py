# Litery w liczbie

inp = int(input())

h_inp = hex(inp)

str_inp = str(h_inp)

def a_letter(f_inp):
	
	leng = len(f_inp)
	
	for i in range(leng-2):
		
		#print(f_inp[i+2])
		
		if(f_inp[i+2] == "a" or f_inp[i+2] == "b" or f_inp[i+2] == "c" or f_inp[i+2] == "d" or f_inp[i+2] == "e" or f_inp[i+2] == "f"):
			return "TAK"
			
	
	return "NIE"


print(a_letter(str_inp))

