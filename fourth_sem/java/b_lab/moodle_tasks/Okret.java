
public class Okret{

    private double dlugosc_bocznego_boku;
    private double dlugosc_przedniego_boku;
    private int pasazerowie;
    private double pole_okretu;
    private double wypornosc;
    static private int counter;
    private int id;

    public Okret(){

        dlugosc_bocznego_boku = 1;
        dlugosc_przedniego_boku = 1;
        pasazerowie = 0;
        wypornosc = 0;
        id = counter;
        counter = counter + 1;
        pole_okretu = ObliczPole();

    }

    public Okret(int val){

        dlugosc_bocznego_boku = val;
        dlugosc_przedniego_boku = val;
        pasazerowie = val;
        wypornosc = val;
        id = counter;
        counter = counter + 1;
        pole_okretu = ObliczPole();

    }

    public Okret(double a, double b, int pas, double wyp){

        dlugosc_bocznego_boku = a;
        dlugosc_przedniego_boku = b;
        pasazerowie = pas;
        wypornosc = wyp;
        id = counter;
        counter = counter + 1;
        pole_okretu = ObliczPole();

    }

    public double ObliczPole(){
        return dlugosc_bocznego_boku*dlugosc_przedniego_boku;
    }

    public String toString() {
        String opis = 
        "Okret #" + id
        + "\nWymiary: " + dlugosc_bocznego_boku + " x " + dlugosc_przedniego_boku
        + "\nPasazerowie: " + pasazerowie
        + "\nWypornosc: " + wypornosc
        + "\nPole: " + ObliczPole();
        return opis;
    }

    public int getPasazerowie(){
        return pasazerowie;
    }

}