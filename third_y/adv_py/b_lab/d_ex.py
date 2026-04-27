
def ksiegowosc(stan_konta,kwota):
	
	def wplata(stan_konta,kwota):
		print(f"\n{locals()}\n")
		print(f"\n{globals()}\n")
		return stan_konta + kwota
	def wyplata(stan_konta,kwota):
		print(f"\n{locals()}\n")
		print(f"\n{globals()}\n")
		return wplata(stan_konta,-kwota)
	print(f"\n{locals()}\n")
	print(f"\n{globals()}\n")
	return wplata(stan_konta,kwota), wyplata(stan_konta,kwota)


x = ksiegowosc(1000,250)
print(x)


# modyfikacja wypłaty wpływa na zmienne lokalne
# 
