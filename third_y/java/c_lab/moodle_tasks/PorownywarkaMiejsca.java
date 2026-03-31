public class PorownywarkaMiejsca implements Porownywarka {
    @Override public int porownajPojazdy(Pojazd a, Pojazd b) { return a.pobierzMiejsca() - b.pobierzMiejsca(); }
}