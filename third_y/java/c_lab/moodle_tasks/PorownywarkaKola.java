public class PorownywarkaKola implements Porownywarka {
    @Override public int porownajPojazdy(Pojazd a, Pojazd b) { return a.pobierzKola() - b.pobierzKola(); }
}