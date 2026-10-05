
public abstract class Pojazd implements Comparable<Pojazd> {

	private int miejsca;
	private int kola;
	private int cena;
	private int waga;

	public void ustawIloscMiejsc(int m){ miejsca = m; }
	public void ustawIloscKol(int k){ kola = k; }
	public void ustawCene(int c){ cena = c; }
	public void ustawWage(int w){ waga = w; }

	public abstract boolean czyToWieloslad();
	public abstract boolean czyUtonie();
	public abstract boolean czyMaDach();

	@Override
	public int compareTo(Pojazd o){
		return this.miejsca - o.miejsca;
	}

	@Override
	public String toString(){
		return this.getClass().getName() + " [Miejsca: " + miejsca + "]";
	}

}