public class Prostokat extends Figura{
	
	private double bok_a;
	private double bok_b;

	public Prostokat(double bok_a, double bok_b){

		this.bok_a = bok_a;
		this.bok_b = bok_b;
		this.ustaw("Prostokat");
		this.ustaw(obliczPole(),obliczObwod());

	}

	private double obliczPole(){
		return bok_a*bok_b;
	}

	private double obliczObwod(){
		return bok_a * 2 + bok_b * 2;
	}

	public void powieksz(int i){
		bok_a = bok_a * i;
		bok_b = bok_b * i;
		this.ustaw(obliczPole(),obliczObwod());
	}

}