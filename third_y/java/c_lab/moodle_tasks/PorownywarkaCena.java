public class PorownywarkaCena implements Porownywarka {
    @Override public int porownajPojazdy(Pojazd a, Pojazd b) { return a.pobierzCene() - b.pobierzCene(); }
}
 