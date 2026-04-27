
import org.apache.commons.lang3.StringUtils;

import java.util.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;

public class Synonimy {

	@SuppressWarnings("deprecation")
	public static void main(String[] args) {

		if (args.length != 1) {
			System.out.println("java Synonimy <słowo>");
			return;
		}

		String searchWord = args[0];
		String filePath = "slownik.txt";

		Map<String, List<String>> dictionary = new HashMap<>();

		try {
			List<String> lines = Files.readAllLines(Paths.get(filePath));

			for (String line: lines) {
				if (line.trim().isEmpty()) continue;

				String[] parts = line.split(":\\s");

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
			System.out.println("Error while reading file, message: " + e.getMessage());
			return;
		}

		if (dictionary.isEmpty()) {
			System.out.println("Słownik jest pusty");
			return;
		}

		if (dictionary.containsKey(searchWord)) {
			System.out.println("Znaleziono słowo: " + searchWord);
			System.out.println("Synonimy: " + dictionary.get(searchWord));
		} else {

			String closestWord = null;
			int minDistance = Integer.MAX_VALUE;

			for (String key : dictionary.keySet()) {

				int distance = org.apache.commons.lang3.StringUtils.getLevenshteinDistance(searchWord, key);

				if (distance < minDistance) {
					minDistance = distance;
					closestWord = key;
				}
			}

			if (closestWord != null) {
                System.out.println("Nie znaleziono słowa: '" + searchWord + "' w słowniku.");
                System.out.println("Najbliższe dopasowanie to: '" + closestWord + "' (odległość Levenshteina: " + minDistance + ")");
                System.out.println("Synonimy: " + dictionary.get(closestWord));
            }

		}

	}
}