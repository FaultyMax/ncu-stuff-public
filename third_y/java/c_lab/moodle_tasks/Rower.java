public class Rower extends Pojazd {

    public Rower(int miejsca, int kola, int cena, int waga) {
        ustawIloscMiejsc(miejsca); ustawIloscKol(kola); ustawCene(cena); ustawWage(waga);
    }
    
    @Override public boolean czyToWieloslad() { return false; }
    @Override public boolean czyUtonie() { return true; }
    @Override public boolean czyMaDach() { return false; }
}