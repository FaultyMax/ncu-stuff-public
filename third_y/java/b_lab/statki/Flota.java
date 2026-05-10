
/*

Zdefiniować klasę Okret zawierającą długości boków, ilość pasażerów, wyporność, unikalny numer okrętu, 
trzy wersje konstruktora przeciążonego, metodę obliczającą pole powierzchni (należy założyć, że jest w kształcie prostokąta). 
Następnie zdefiniować klasy:
• Niszczyciel dziedziczącą z klasy Okret i uzupełnioną o informację o sile rażenia i ilość dział, 
• Lotniskowiec dziedziczącą z klasy Niszczyciel i uzupelnioną o dane dotyczące ilości samolotów, które może pomieścić.
Do obu klas (Niszczyciel i Lotniskowiec) dodać metodę toString() wypisującą odpowiednie informacje o statkach.
Na koniec, zdefiniować klasę Flota zawierającą:
• tablicę z elementami typu Okret, która będzie wypelniana dynamicznie poprzez utworzoną do tego celu metodę dodajDoFloty(Okret),
• konstruktory umożliwiające określenie ilości obiektów typu Niszczyciel i Lotniskowiec, 
• funkcję main(-) inicjalizującą obiekt typu Flota i wypisującą informacje o jej składzie z wykorzystaniem utworzonej do tego celu metody toString(),
• metodę silaFloty() zliczającą siłę rażenia, ilość pasażerów i dział w całej flocie.

*/

public class Flota{

    private int ilosc_statkow;
    private Okret[] statki;
    private int indx;

    Flota(){

        ilosc_statkow = 10;
        statki = new Okret[ilosc_statkow];
        indx = 0;

    }

    Flota(int ilosc){

        ilosc_statkow = ilosc;
        statki = new Okret[ilosc_statkow];
        indx = 0;

    }

    public void dodajDoFloty(Okret ship){
        if ( indx < ilosc_statkow ){
            statki[indx] = ship;
            indx++;
        }
    }

    public int policzNiszczyciele() {
        int licznik = 0;
        for (int i = 0; i < indx; i++) {
            if (statki[i] instanceof Niszczyciel) { 
                licznik++;
            }
        }
        return licznik;
    }

    public int policzLotniskowce() {
        int licznik = 0;
        for (int i = 0; i < indx; i++) {
            if (statki[i] instanceof Lotniskowiec) {
                licznik++;
            }
        }
        return licznik;
    }

    public String toString(){
        String opis = 
        "Ilosc okretow: " + ilosc_statkow
        + "\nIlosc niszczycieli: " + (policzNiszczyciele() - policzLotniskowce())
        + "\nIlosc lotniskowców: " + policzLotniskowce();
        return opis;
    }

    public void silaFloty(){

        int suma_pas = 0;
        double suma_raz = 0;
        int suma_dzial = 0;

        for (int i = 0; i < indx; i++) {
            suma_pas += statki[i].getPasazerowie();
            if (statki[i] instanceof Niszczyciel n) {
                suma_raz += n.getRazenie();
                suma_dzial += n.getDziala();
            }
        }

        String opis = "Pasazerowie: " + suma_pas + "\nsila razenia: " + suma_raz + "\nsuma dzial: " + suma_dzial;

        System.out.println(opis);

    }

    public static void main(String[] args){

        Flota mojaFlota = new Flota(15);

        Niszczyciel t1 = new Niszczyciel();
        System.out.println(t1);

        Niszczyciel t2 = new Niszczyciel(3);
        System.out.println(t2);

        Lotniskowiec t3 = new Lotniskowiec(3,5,13,499,25.2,7,12);
        System.out.println(t3);

        mojaFlota.dodajDoFloty(t1);
        mojaFlota.dodajDoFloty(t2);
        mojaFlota.dodajDoFloty(t3);

        System.out.println(mojaFlota);

        mojaFlota.silaFloty();

    } 

}