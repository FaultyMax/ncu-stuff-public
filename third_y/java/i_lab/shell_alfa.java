import java.io.*;
import java.nio.file.*;
import java.util.Scanner;

public class ProstyShell {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("> ");
            String line = scanner.nextLine().trim();

            if (line.equalsIgnoreCase("quit") || line.equalsIgnoreCase("exit")) {
                System.out.println("Zamykanie programu...");
                break;
            }

            if (line.isEmpty()) continue;

            String[] parts = line.split("\\s+");
            String command = parts[0];

            switch (command) {
                case "ls":
                    handleLs(parts);
                    break;
                case "cp":
                    handleCp(parts);
                    break;
                default:
                    System.out.println("Nieznane polecenie: " + command);
            }
        }

        scanner.close();
    }

    public void handleLs(String[] args) {
        File dir;

        if (args.length == 1) {
            dir = new File("."); // bieżący katalog
        } else {
            dir = new File(args[1]);
        }

        if (!dir.exists()) {
            System.out.println("Katalog nie istnieje.");
            return;
        }

        if (!dir.isDirectory()) {
            System.out.println("To nie jest katalog.");
            return;
        }

        File[] files = dir.listFiles();
        if (files != null) {
            for (File f : files) {
                System.out.println(f.getName());
            }
        }
    }

    private static void handleCp(String[] args) {
        if (args.length < 3) {
            System.out.println("Użycie: cp <źródło> <cel>");
            return;
        }

        Path source = Paths.get(args[1]);
        Path target = Paths.get(args[2]);

        try {
            Files.copy(source, target, StandardCopyOption.REPLACE_EXISTING);
            System.out.println("Skopiowano plik.");
        } catch (IOException e) {
            System.out.println("Błąd kopiowania: " + e.getMessage());
        }
    }
}