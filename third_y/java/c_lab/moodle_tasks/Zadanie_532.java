import java.util.Scanner;

public class Zadanie_532 {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        String[] wierzcholki = sc.nextLine().trim().split("\\s+");
        int n = wierzcholki.length;

        java.util.Map<String, Integer> indeks = new java.util.HashMap<>();
        for (int i = 0; i < n; i++) indeks.put(wierzcholki[i], i);

        int[][] macierz = new int[n][n];
        for (int i = 0; i < n; i++) {
            String[] linia = sc.nextLine().trim().split("\\s+");
            for (int j = 1; j < linia.length; j++) {
                int sasiad = indeks.get(linia[j]);
                macierz[i][sasiad] = 1;
            }
        }

        String start = sc.nextLine().trim();

        String algorytm = sc.nextLine().trim();

        PrzegladanieGrafu pg;
        if (algorytm.equalsIgnoreCase("BFS")) {
            pg = new BFS(macierz, wierzcholki);
        } else {
            pg = new DFS(macierz, wierzcholki);
        }

        pg.przegladaj(start);
    }
}