import java.util.Arrays;

public class Zadanie3 {
	public static void main(String[] args) {
		Pojazd[] tablica = new Pojazd[6];

		tablica[0] = new Rower(48);
		tablica[1] = new Rower();
		tablica[2] = new Rower(88);
		tablica[3] = new Rower(2);
		tablica[4] = new Rower();
		tablica[5] = new Rower(12);

		Arrays.sort(tablica);

		for(int i = 0; i < tablica.length ; i++){
			System.out.println(tablica[i]);
		}

	}
}