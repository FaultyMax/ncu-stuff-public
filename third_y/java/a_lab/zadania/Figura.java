
public class Figura {
	
	private double pole;
	private double obwod;
	public double wymiar;
	public String nazwa;
	
	private static int licznik;
	private int id;
	
	public Figura(){
	
		pole = 0;
		obwod = 0;
		wymiar = 0;
		nazwa = "";
		id = pobierzLicznik();
		ustawLicznik(id+1);
		
	}
	
	public Figura(int wymiar){
	
		pole = 0;
		obwod = 0;
		this.wymiar = wymiar;
		nazwa = "";
		id = pobierzLicznik();
		ustawLicznik(id+1);
		
	}
	
	public void ustaw(double pole, double obwod){
		this.pole = pole;
		this.obwod = obwod;
	}
	
	public void ustaw(double wymiar){
		this.wymiar = wymiar;
	}
	
	public void ustaw(String nazwa){
		this.nazwa = nazwa;
	}

	public void ustaw(double value, boolean isPole){
		if (isPole) {
			this.pole = value;
		} else {
			this.obwod = value;
		}
	}
	
	public boolean czyPunktJestWewnątrz(double x, double y){
		if ((wymiar*wymiar) >= (x*x) + (y*y)){ return true; }
		else return false;
	}
	
	public int pobierzLicznik(){ return licznik; }
	public void ustawLicznik(int I){ licznik = I; }
	
	public String toString(){
		String opis = "Figura: " + nazwa + " nr " + id + "\n";
		if ( pole > 0 ) opis += "Pole: " + pole + "\n";
		if ( obwod > 0 ) opis += "Obwod: " + obwod + "\n";
		return opis;
	}
	
	public void wypisz(){
		System.out.printf("Figura: %s %nPole: %f, Obwod %f %n", nazwa, pole, obwod);
	}
	
}
