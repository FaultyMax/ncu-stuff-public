
tekst = open("tekst.txt","r")
zmieniony = open("zmieniony.txt","w")


s,t = input().split()

for l in tekst:
	l = l.rstrip()
	
	new_l = l.replace(s,t)
	
	#print(new_l)
	
	zmieniony.write(new_l)
	zmieniony.write("\n")
	

tekst.close()
zmieniony.close()


# function -> funkcja
