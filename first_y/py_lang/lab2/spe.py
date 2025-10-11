
import math

def lcm(a,b):
	return (a*b)/math.gcd(a,b)
	
inp = int(input()) # skrzyzowania

czasy = []

for t in range(inp):
	czasy.append(int(input()))
	

tmp = lcm(czasy[0]+1,czasy[1]+1)

for i in range(2,inp,1):
	
	a = lcm(int(tmp),czasy[i]+1)
	tmp = a;


print(int(tmp)-1)

# a*b / gdc(a,b)
# lcm(a+1,b+1)-1
