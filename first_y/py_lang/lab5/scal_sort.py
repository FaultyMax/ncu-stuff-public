
dane1 = open("dane1.txt","r")
dane2 = open("dane2.txt","r")
wynik = open("wynik.txt","w")

list1 = dane1.readlines()
list2 = dane2.readlines()

cap1 = len(list1)
cap2 = len(list2)

i1 = 0
i2 = 0

while i1 < cap1 and i2 < cap2:
	
	if int(list1[i1]) > int(list2[i2]):
		wynik.write(list2[i2])
		i2 += 1
	else:
		wynik.write(list1[i1])
		i1 += 1
		
while i1 < cap1:
	wynik.write(list1[i1])
	i1 += 1
	
while i2 < cap2:
	wynik.write(list2[i2])
	i2 += 1

dane1.close()
dane2.close()
wynik.close()
