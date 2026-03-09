
count = 0;
n_nobody_uid = 0;

with open("/etc/passwd","rt") as f:
	for line in f:
		#print(line.strip())
		x = (line.strip()).split(":")
		print(f"{x[0]} {x[6]}")
		if x[0] == "nobody":
			n_nobody_uid = x[2]
		count = count + 1


print(f"UID NOBODY : {n_nobody_uid}")
print(count)
