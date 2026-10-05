
def oblicz_lokate(kwota_poczatkowa, oprocentowanie, lata):
    '''Oblicz lokate o danym stałym oprocentowaniu przez określoną liczbe lat.

    Args:
        kwota_poczatkowa (float): początkowy kapitał.
        oprocentowanie (float): stała wartość oprocentowania.
        lata (int): ilość lat.

    Returns:
        float: końcowa wartość lokaty.

    Raises:
        ValueError: Jeśli `lata` są ujemne.

    
    '''
    if lata < 0:
        raise ValueError("Lata nie mogą być ujemne.")
    kwota_koncowa = kwota_poczatkowa * (1 + oprocentowanie) ** lata
    return kwota_koncowa


oblicz_lokate(100, 0.10, 3)
help(oblicz_lokate)
