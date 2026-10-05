
with open("inp.txt","rt") as f:
	for line in f:
		print(line.strip()[0:10])
