public class Samochod extends Pojazd {

    public Samochod(int miejsca, int kola, int cena, int waga) {
        ustawIloscMiejsc(miejsca); ustawIloscKol(kola); ustawCene(cena); ustawWage(waga);
    }
    
    @Override public boolean czyToWieloslad() { return true; }
    @Override public boolean czyUtonie() { return false; }
    @Override public boolean czyMaDach() { return true; }
}