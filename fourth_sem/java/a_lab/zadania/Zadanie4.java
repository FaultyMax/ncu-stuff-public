public class Zadanie4 {

		public static void main(String[] args){
			Figura kolo = new Figura();
			kolo.ustaw("Kolo");
			kolo.ustaw(5);
			
			System.out.println(kolo.czyPunktJestWewnątrz(2,2));
			System.out.println(kolo.czyPunktJestWewnątrz(3,4));
			System.out.println(kolo.czyPunktJestWewnątrz(2,5));
			
		}
	}

