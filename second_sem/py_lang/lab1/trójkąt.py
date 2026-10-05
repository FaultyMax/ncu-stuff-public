# trójkąt

inp = input()

#a,b,c = inp.split()

a,b,c = map( int, inp.split() )

def obw(a,b,c):
	return (a+b+c)

print(obw(a,b,c))
