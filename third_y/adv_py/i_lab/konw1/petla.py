
# usual approach
'''
a = input()
while a != "koniec":
    print(a)
    a = input()
'''

# walrus operator
'''
while a := input():
    if a == "koniec":
        break
    print(a)
'''

# even better
while (a := input()) != "koniec":
    print(a)
