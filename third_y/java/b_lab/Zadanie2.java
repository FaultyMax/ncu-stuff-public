public class Zadanie2 {
	public static void main(String[] args) {
		Figura[] tablica = new Figura[5];
		tablica[0] = new Prostokat(5,6);
		tablica[1] = new Kwadrat(5);
		tablica[2] = new Kwadrat(11);
		tablica[3] = new Kolo(11);
		tablica[4] = new Prostokat(2,1);

		for(int i = 0 ; i < tablica.length ; i++){
			tablica[i].powieksz(4);
			System.out.println(tablica[i]);
		}
	}
}