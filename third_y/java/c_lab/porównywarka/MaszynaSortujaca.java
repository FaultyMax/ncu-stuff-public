public class MaszynaSortujaca {
    
    private Porownywarka porownywarka;
    private Pojazd[] tablica;
    private int rozmiar;
 
    public MaszynaSortujaca(Porownywarka p) {
        this.porownywarka = p;
        this.tablica = new Pojazd[100];
        this.rozmiar = 0;
    }
 
    public void dodajPojazd(Pojazd p) { tablica[rozmiar++] = p; }
 
    public void sortuj() {
        for (int i = 0; i < rozmiar - 1; i++)
            for (int j = 0; j < rozmiar - 1 - i; j++)
                if (porownywarka.porownajPojazdy(tablica[j], tablica[j+1]) > 0) {
                    Pojazd tmp = tablica[j];
                    tablica[j] = tablica[j+1];
                    tablica[j+1] = tmp;
                }
    }
 
    public void wypisz() {
        for (int i = 0; i < rozmiar; i++) System.out.println(tablica[i]);
    }
}