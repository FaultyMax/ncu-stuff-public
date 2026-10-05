
public class Lotniskowiec extends Niszczyciel{

    private int ilosc_samolotow;

    public Lotniskowiec(){
        super();
        ilosc_samolotow = 0;
    }

    public Lotniskowiec(int val){
        super(val);
        ilosc_samolotow = val;
    }

    public Lotniskowiec(double a, double b, int pas, double wyp, double sila, int dziala, int samoloty){
        super(a,b,pas,wyp,sila,dziala);
        ilosc_samolotow = samoloty;
    }

    public String toString() {
        String opis = 
        "Lotniskowiec - " + super.toString()
        + "\nilosc samolotow: " + ilosc_samolotow;
        return opis;
    }

}