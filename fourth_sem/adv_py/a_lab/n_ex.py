
def is_palindrome_rec(left,right,s):
	
	if left >= right:
		return 1
		
	if s[left] != s[right]:
		print(f"{s[left]} {s[right]}")
		return 0
		
	return is_palindrome_rec(left + 1,right - 1,s)

def is_palindrome(s):
	left = 0
	right = len(s) - 1
	return is_palindrome_rec(left,right,s)

test = "Kobyła ma mały bok"

print(is_palindrome(test.casefold()))
