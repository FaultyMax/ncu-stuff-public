public class Lodz extends Pojazd {

    public Lodz(int miejsca, int kola, int cena, int waga) {
        ustawIloscMiejsc(miejsca); ustawIloscKol(kola); ustawCene(cena); ustawWage(waga);
    }
    
    @Override public boolean czyToWieloslad() { return false; }
    @Override public boolean czyUtonie() { return false; }
    @Override public boolean czyMaDach() { return false; }
}