import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Date;

/*

Napisac klase ProstyShell, której zadaniem jest wczytywanie kolejnych komend pobieranych
z klawiatury w postaci linii. W przypadku wczytania słowa ’quit’ lub ’exit’ program powinien
zakonczyc działanie. Wykorzystujac rozwiazanie zadania 1 i 2 nalezy zaimplementowac reakcje na
polecenie ’ls’ i ’cp’.

*/

public class ProstyShell {

    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("ProstyShell – wpisz 'help' aby zobaczyć komendy.");

        while (true) {
            System.out.print("$ ");
            try {
                String line = reader.readLine();
                if (line == null) break;
                line = line.trim();

                if (line.equals("quit") || line.equals("exit")) {
                    System.out.println("Do widzenia!");
                    break;

                } else if (line.equals("ls")) {
                    listDirectory(".");

                } else if (line.startsWith("ls ")) {
                    String path = line.substring(3).trim();
                    listDirectory(path);

                } else if (line.startsWith("cp ")) {
                    String[] parts = line.substring(3).trim().split("\\s+");
                    if (parts.length != 2) {
                        System.out.println("Użycie: cp <źródło> <cel>");
                    } else {
                        copyFile(parts[0], parts[1]);
                    }

                } else if (line.equals("help")) {
                    System.out.println("Dostępne komendy:");
                    System.out.println("\tls [katalog]   – wypisuje zawartość katalogu");
                    System.out.println("\tcp <src> <dst> – kopiuje plik");
                    System.out.println("\tquit / exit    – zamyka program");

                } else if (line.isEmpty()) {
                    // w tym wypadku przyjmuje pustą linie jako koniec
                    break;
                } else {
                    System.out.println("Nieznana komenda: '" + line + "'. Wpisz 'help' aby zobaczyć dostępne komendy.");
                }

            } catch (Exception ex) {
                System.out.println("Błąd: " + ex.getMessage());
            }
        }
    }

    static void listDirectory(String nazwaKatalogu) {
        File katalog = new File(nazwaKatalogu);
        if (!katalog.exists() || !katalog.isDirectory()) {
            System.out.println("Nie ma takiego katalogu: " + nazwaKatalogu);
            return;
        }
        File[] pliki = katalog.listFiles();
        if (pliki == null || pliki.length == 0) {
            System.out.println("(katalog jest pusty)");
            return;
        }
        for (File f : pliki) {
            String k = f.isDirectory() ? "/" : "";
            System.out.println(f.getName() + k
                    + "\t" + f.length() + " b"
                    + "\t" + new Date(f.lastModified()));
        }
    }

    static void copyFile(String from, String to) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(from));
            BufferedWriter bw = new BufferedWriter(new FileWriter(to));

            String linia = br.readLine();
            while (linia != null) {
                bw.write(linia);
                bw.newLine();
                linia = br.readLine();
            }

            bw.flush();
            bw.close();
            br.close();
            System.out.println("Skopiowano: " + from + " -> " + to);
        } catch (Exception ex) {
            System.out.println("Błąd kopiowania: " + ex.getMessage());
        }
    }
}