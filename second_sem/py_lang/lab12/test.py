
class klasa:
	a = 10
	b = "napis"
	def wypisz(self):
		print(self.a)
	def __str__(self):
		return str(self.a)+":)"
	
print(klasa.b)

o = klasa()
print(o)
