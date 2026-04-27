public class PorownywarkaWaga implements Porownywarka {
    @Override public int porownajPojazdy(Pojazd a, Pojazd b) { return a.pobierzWage() - b.pobierzWage(); }
}