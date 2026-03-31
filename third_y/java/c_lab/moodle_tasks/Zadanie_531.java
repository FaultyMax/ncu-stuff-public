public class Zadanie_531 {
    public static void main(String[] args) {
        Pojazd[] pojazdy = {
            new Rower(1,2,433,12),
            new Rower(2,2,1133,16),
            new Samochod(5,4,30000,1200),
            new Samochod(2,4,74000,1000),
            new Samochod(7,4,96000,1800),
            new Lodz(6,0,70040,700),
            new Lodz(12,0,31040,2700),
            new Lodz(4,1,21040,500)
        };
 
        System.out.println("Sortowanie kola");
        MaszynaSortujaca ms1 = new MaszynaSortujaca(new PorownywarkaKola());
        for (Pojazd p : pojazdy) ms1.dodajPojazd(p);
        ms1.sortuj(); ms1.wypisz();
 
        System.out.println("\nSortowanie cena");
        MaszynaSortujaca ms2 = new MaszynaSortujaca(new PorownywarkaCena());
        for (Pojazd p : pojazdy) ms2.dodajPojazd(p);
        ms2.sortuj(); ms2.wypisz();
 
        System.out.println("\nSortowanie waga");
        MaszynaSortujaca ms3 = new MaszynaSortujaca(new PorownywarkaWaga());
        for (Pojazd p : pojazdy) ms3.dodajPojazd(p);
        ms3.sortuj(); ms3.wypisz();
 
        System.out.println("\nSortwanie miejsca");
        MaszynaSortujaca ms4 = new MaszynaSortujaca(new PorownywarkaMiejsca());
        for (Pojazd p : pojazdy) ms4.dodajPojazd(p);
        ms4.sortuj(); ms4.wypisz();
    }
}