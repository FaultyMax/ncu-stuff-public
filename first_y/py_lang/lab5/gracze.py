import random

print("wygenerować nowe dane? (Y/N)")

inp = input()

def func(file1,file2):
	
	x = zip(file1.readlines(),file2.readlines())
	
	wynik1 = 0
	wynik2 = 0
	
	for i in x:
		
		if int(i[0]) > int(i[1]):
			wynik1 += 1
		elif int(i[0]) < int(i[1]):
			wynik2 += 1
			
	print(f"wynik gracza1: {wynik1}")		
	print(f"wynik gracza2: {wynik2}")		
	
	if wynik1 > wynik2:
		print("gracz1 wygrywa.")
	elif wynik1 == wynik2:
		print("REMIS")
	else:
		print("gracz2 wygrywa")
		
	

if inp == "Y":
	
	print("OK")

	gracze1 = open("gracze1.txt","w",encoding='utf8')
	gracze2 = open("gracze2.txt","w",encoding='utf8')

	for num in range(50):
		t1 = random.randrange(1,101)
		t2 = random.randrange(1,101)
		
		gracze1.write(str(t1))
		gracze2.write(str(t2))
		gracze1.write("\n")
		gracze2.write("\n")
		
	gracze1.close()
	gracze2.close()
	
	gracze1 = open("gracze1.txt","r",encoding='utf8')
	gracze2 = open("gracze2.txt","r",encoding='utf8')
	func(gracze1,gracze2)
	gracze1.close()
	gracze2.close()
	
elif inp == "N":
	gracze1 = open("gracze1.txt","r",encoding='utf8')
	gracze2 = open("gracze2.txt","r",encoding='utf8')
	print("Kontynuuje z danymi z pliku.")
	func(gracze1,gracze2)
	gracze1.close()
	gracze2.close()
else:
	print("(Y/N)")


