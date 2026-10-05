import java.util.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;

/*
Utwórz program Synonimy, który:
. Wczytuje plik tekstowy zawierający słownik w formacie:
dobry: wspaniały,świetny,znakomity
szybki: prędki,błyskawiczny,ekspresowy
. Przechowuje dane w Map<String, List>.
. Umożliwia użytkownikowi podanie słowa jako argumentu programu.
. Wyszukuje i wypisuje jego synonimy.
. Jeśli słowo nie istnieje, wypisuje najbliższe słowo (według odległości Levenshteina).
*/

public class Synonimy {

    private static int levenshtein(String a, String b) {
        int m = a.length(), n = b.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j - 1],
                                    Math.min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Użycie: java Synonimy <słowo>");
            return;
        }
        String searchWord = args[0];
        String filePath = "slownik.txt";
        Map<String, List<String>> dictionary = new HashMap<>();

        try {
            List<String> lines = Files.readAllLines(Paths.get(filePath));
            for (String line : lines) {
                if (line.trim().isEmpty()) continue;
                String[] parts = line.split(":\\s*");
                if (parts.length == 2) {
                    String key = parts[0].trim();
                    String[] synonymArray = parts[1].split(",");
                    List<String> synonymList = new ArrayList<>();
                    for (String syn : synonymArray) {
                        synonymList.add(syn.trim());
                    }
                    dictionary.put(key, synonymList);
                }
            }
        } catch (IOException e) {
            System.out.println("Błąd odczytu pliku: " + e.getMessage());
            return;
        }

        if (dictionary.isEmpty()) {
            System.out.println("Słownik jest pusty.");
            return;
        }

        if (dictionary.containsKey(searchWord)) {
            System.out.println("Znaleziono słowo: " + searchWord);
            System.out.println("Synonimy: " + dictionary.get(searchWord));
        } else {
            String closestWord = null;
            int minDistance = Integer.MAX_VALUE;
            for (String key : dictionary.keySet()) {
                int distance = levenshtein(searchWord, key);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestWord = key;
                }
            }
            if (closestWord != null) {
                System.out.println("Nie znaleziono słowa: '" + searchWord + "' w słowniku.");
                System.out.println("Najbliższe dopasowanie: '" + closestWord + "' (odległość Levenshteina: " + minDistance + ")");
                System.out.println("Synonimy: " + dictionary.get(closestWord));
            }
        }
    }
}