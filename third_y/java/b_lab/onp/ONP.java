
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