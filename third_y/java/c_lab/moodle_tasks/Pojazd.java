public abstract class Pojazd {
    private int miejsca;
    private int kola;
    private int cena;
    private int waga;
 
    public void ustawIloscMiejsc(int m) { miejsca = m; }
    public void ustawIloscKol(int k) { kola = k; }
    public void ustawCene(int c) { cena = c; }
    public void ustawWage(int w) { waga = w; }
 
    public int pobierzMiejsca() { return miejsca; }
    public int pobierzKola() { return kola; }
    public int pobierzCene() { return cena; }
    public int pobierzWage() { return waga; }
 
    public abstract boolean czyToWieloslad();
    public abstract boolean czyUtonie();
    public abstract boolean czyMaDach();
 
    @Override
    public String toString() {
        return this.getClass().getSimpleName()
            + " [miejsca=" + miejsca 
            + ", kola=" + kola
            + ", cena=" + cena 
            + ", waga=" + waga + "]";
    }
}