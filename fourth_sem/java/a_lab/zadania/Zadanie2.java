public class Zadanie2 {

		public static void main(String[] args){
			Figura kolo = new Figura();
			kolo.nazwa = "Kolo";
			kolo.wymiar = 1;
			kolo.ustaw(3.14,6.28);
			
			Figura kwadrat = new Figura();
			kwadrat.nazwa = "Kwadrat";
			kwadrat.wymiar = 1;
			kwadrat.ustaw(1,4);
			
			System.out.println(kolo);
			System.out.println(kwadrat);
		}
	}
