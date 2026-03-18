public class Kolo extends Figura{

	private double wymiar;

	public Kolo(double wymiar){
		this.wymiar = wymiar;
		this.ustaw("Kolo");
	}

	private double obliczPole(){
		return 3.14159 * wymiar * wymiar; 
	}

	private double obliczObwod(){
		return 2 * 3.14159 * wymiar;
	}

	public void powieksz(int i){
		wymiar = wymiar * i;
		this.ustaw(obliczPole(),obliczObwod());
	}

}