# stopnie

inp = int(input())

def conv(n):
	return (5/9) * ( n - 32 )

num = conv(inp)

print(f"{num:0.2f}")
