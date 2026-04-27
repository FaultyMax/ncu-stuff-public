
public class Rower extends Pojazd {

	@Override
	public boolean czyToWieloslad() {
		return false;
	}

	@Override
	public boolean czyUtonie() {
		return true;
	}

	@Override
	public boolean czyMaDach() {
		return false;
	}

	public Rower(int x){
		ustawIloscMiejsc(x);
	}

	public Rower(){
		ustawIloscMiejsc(1);
	}

}