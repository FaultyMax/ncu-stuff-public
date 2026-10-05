def koduj(s):

	numbers = ("ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE")

	s = s.replace(" ","")
	s = s.upper()
	
	for i in range(len(s)):
		
		if(ord(s[i]) >= 48 and ord(s[i]) <= 57):
			print("is number")
			print(int(s[i]))
			s = s.replace(s[i],numbers[int(s[i])])
	
	s = s.replace(".","STOP")
	
	return s
	
def cezar(text,key,enc):
	
	text = koduj(text)
	
	if(enc == True):
		
		wynik = ""
		
		for i in range(len(text)):
			
			char = text[i]
			
			wynik += chr((ord(char) + key-65) % 26 + 65)

		return wynik
		
	else:
		
		return cezar(text,26-key,True)



