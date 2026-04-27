import java.util.LinkedList;

public abstract class PrzegladanieGrafu {

    public int[][] macierzSasiedztwa;
    public String[] wierzcholki;
    public int n;

    public PrzegladanieGrafu(int[][] macierz, String[] wierzcholki) {
        this.macierzSasiedztwa = macierz;
        this.wierzcholki = wierzcholki;
        this.n = wierzcholki.length;
    }

    public abstract void wstaw(int numerWierzcholka);
    public abstract int pobierz();
    public abstract boolean czyPusta();

    public void przegladaj(String start) {
        boolean[] odwiedzone = new boolean[n];
        int startIdx = znajdzIndeks(start);

        if (startIdx == -1){
            System.out.println("niepoprawny indeks");
            return;
        }

        wstaw(startIdx);
        odwiedzone[startIdx] = true;

        String wynik = new String();

        while (!czyPusta()) {
            int v = pobierz();
            if (wynik.length() > 0){ wynik += " "; }
            wynik += wierzcholki[v];

            for (int i = 0; i < n; i++) {
                if (macierzSasiedztwa[v][i] == 1 && !odwiedzone[i]) {
                    odwiedzone[i] = true;
                    wstaw(i);
                }
            }
        }

        System.out.println(wynik);
    }

    public int znajdzIndeks(String nazwa) {
        for (int i = 0; i < n; i++)
            if (wierzcholki[i].equals(nazwa)) { return i; }
        return -1;
    }
}