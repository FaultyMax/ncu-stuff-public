
class DziwnaLiczba(int):

	def __init__(self,val = 1):
		if val == 0:
			raise Exception("Proba uzycia liczby 0")
		self.val = val

	def __add__(self, DziwnaLiczba2):
		if self.val + DziwnaLiczba2.val == 0:
			raise Exception("Proba uzycia liczby 0")
		return DziwnaLiczba(self.val + DziwnaLiczba2.val)

	def __mul__(self, DziwnaLiczba2):
		return DziwnaLiczba(self.val * DziwnaLiczba2.val)

	def __getitem__(self, key):
		it = str(self.val)
		return it[key]


x = DziwnaLiczba()
y = DziwnaLiczba(6)

z = x + y

a = DziwnaLiczba(-3)
b = DziwnaLiczba(3)

print(isinstance(a,int))

t = DziwnaLiczba(123)
print(t[1])
t = t[1:10:2]
print(t)

print(z.val)
print((y*y).val)




# 123
# str(123) = "123" return [0]