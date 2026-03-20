public class Zadanie3 {
	public static void main(String[] a){
		Stos s = new Stos();
		s.wstaw(new Kwadrat(1));
		s.wstaw(new Kolo(1));
		s.wstaw(new Prostokat(1,2));
		while(!s.czyPusty()){
			System.out.println(s.pobierz());
		}
	}
}