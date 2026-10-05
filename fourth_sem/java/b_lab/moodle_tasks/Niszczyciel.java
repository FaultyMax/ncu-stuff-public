
public class Niszczyciel extends Okret{

    private double sila_razenia;
    private int ilosc_dzial;

    public Niszczyciel(){
        super();
        sila_razenia = 0;
        ilosc_dzial = 0;
    }

    public Niszczyciel(int val){
        super(val);
        sila_razenia = val;
        ilosc_dzial = val;
    }

    public Niszczyciel(double a, double b, int pas, double wyp, double sila, int dziala){
        super(a,b,pas,wyp);
        sila_razenia = sila;
        ilosc_dzial = dziala;
    }

    public String toString() {
        String opis = 
        "Niszczyciel - " + super.toString()
        + "\nSila razenia: " + sila_razenia
        + "\nilosc dzial: " + ilosc_dzial;
        return opis;
    }

    public double getRazenie(){
        return sila_razenia;
    }

    public int getDziala(){
        return ilosc_dzial;
    }

}