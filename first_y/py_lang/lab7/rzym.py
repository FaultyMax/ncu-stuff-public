
def func(n,napis):
	
	for x in rzymskie:
		if n >= x:
			napis += rzymskie[x]
			n -= x
			break
			
	
			
	return (napis,n)


n = int(input())

rzymskie = {

	1000: 'M',
	
	900: 'CM',
	
	500: 'D',
	
	400: 'CD',
	
	100: 'C',

	90: 'XC',

	50: 'L',
		
	40: 'XL',
		
	10: 'X',
	
	9: 'IX',
		
	5: 'V',
		
	4: 'IV',
		
	1: 'I'
		
}

liczba_r = ""

#liczba_r = func(n,liczba_r)[0]


while(n >= 1):
	#print(n)
	res = func(n,liczba_r)
	liczba_r = res[0]
	n = res[1]
	

print(liczba_r)

	
