
plik = open("imiona.txt","r",encoding='utf8')
p1 = open("panie.txt","w",encoding='utf8')
p2 = open("panowie.txt","w",encoding='utf8')

def func():
	count1 = 0
	count2 = 0

	for l in plik:
	
		l = l.rstrip()
	
		if(l[len(l)-1] == 'a'):
			#print(f"żeńskie: {l}")
			count1 += 1
			#print(count1);
			p1.write(l)
			p1.write("\n")
		else:
			#print(f"męskie: {l}")
			count2 += 1
			#print(count2);
			p2.write(l)
			p2.write("\n")

	p1.write(str(count1))
	p1.write("\n")
	p2.write(str(count2))
	p2.write("\n")

func()

plik.close()
p1.close()
p2.close()
