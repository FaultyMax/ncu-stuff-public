from collections import Counter
import string

counter = Counter()

with open("count_this.txt","rt") as f:
	
	text = f.readline().casefold()
	text = text.translate(str.maketrans('', '', string.punctuation))
	text = text.split()
	
	for word in text:
		for letter in word:
			if letter not in counter:
				counter[letter] = 0
			counter[letter] += 1
		#print(word)

print(counter.most_common(5))
