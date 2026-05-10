
/*

Utworzyć klasę ONP obliczającą wartość wyrażenia podanego w odwrotnej notacji polskiej. 
W tym celu należy wykorzystać strukturę stosu utworzoną w zadaniu 3. Klasa powinna mieć metodę main(-),
która odczyta wyrażenie z argumentu podanego w lini poleceń podczas uruchamiania programu.
Następnie przekaże zainicjuje instancję klasy ONP z wykorzystaniem jedynego konstruktora przyjmującego jako parametr obiekt String
zawierający wyrażenie. Ponadto klasa powinna posiadać metodę wyznaczWartosc(), która zwróci wartość wyrażenia.
Należy założyć, że w wyrażeniu będą tylko liczby całkowite, jeden operator jednoargumentowy - zmieniający znak liczby oraz 
dwa operatory dwuargumentowe + i * reprezentujące dodawanie i mnożenie.

*/

public class ONP {
    private String input;

    public ONP(String input) {
        this.input = input;
    }

    public int wyznaczWartosc() {
        Stos stos = new Stos();
        String[] wartosci = input.trim().split(" ");

        for (String w : wartosci) {
            switch (w) {
                case "+" -> {
                    int b = (int) stos.pobierz();
                    int a = (int) stos.pobierz();
                    stos.wstaw(a + b);
                }
                case "x" -> {
                    int b = (int) stos.pobierz();
                    int a = (int) stos.pobierz();
                    stos.wstaw(a * b);
                }
                case "-" -> {
                    int a = (int) stos.pobierz();
                    stos.wstaw(-a);
                }
                default -> {
                    stos.wstaw(Integer.parseInt(w));
                }
            }
        }

        return (int) stos.pobierz();
    }

    public static void main(String[] args) {

        if (args.length == 0) {
            System.out.println("Należy podać jakieś wyrażenie np. 2 3 + 5 x");
            return;
        }

        String arg = "";

        for(int i = 0; i < args.length ; i++){
            arg += args[i] + " ";
        }

        ONP onp = new ONP(arg);

        System.out.println("Wejscie: " + arg);
        System.out.println("Wynik: " + onp.wyznaczWartosc());
    }
}