
import java.util.ArrayList;

public class ListaObiektow {

	public static void main(String[] args) {

		ListaObiektow lista = new ListaObiektow();
		lista.dodajObiekt("kwadrat");
		lista.dodajObiekt("trójkąt");
		lista.dodajObiekt("koło");
		System.out.println("Lista: " + lista);

		try {
			System.out.println("Pierwszy: " + lista.pierwszyObiekt());
			System.out.println("Indeks 2: " + lista.pobierzObiekt(2));
			System.out.println("Indeks kwadrat: " + lista.indeksObiektu("kwadrat"));
			lista.usunObiekt(0);
			System.out.println("Lista: " + lista);
		} catch (Exception e) {
			System.out.println("Błąd: " + e.getMessage());
		}

		
		
	}

	private ArrayList<Object> list;

	public ListaObiektow() {
		list = new ArrayList<>();
	}

	public Object pobierzObiekt(int index) throws ZlyIndeksException, PustaListaException {
		if (list.isEmpty()) {
			throw new PustaListaException();
		}
		if (index < 0 || index >= list.size()) {
			throw new ZlyIndeksException(index, list.size());
		}
		return list.get(index);
	}

	public Object pierwszyObiekt() throws PustaListaException {
		if (list.isEmpty()) {
			throw new PustaListaException();
		}
		return list.get(0);
	}

	public int indeksObiektu(Object o) throws BrakObiektuException {
		int index = list.indexOf(o);
		if (index == -1) {
			throw new BrakObiektuException("Obiekt \"" + o + "\" nie znajduje się na liście.");
		}
		return index;
	}

	public void dodajObiekt(Object o) {
		list.add(o);
	}

	public void usunObiekt(int index) throws ZlyIndeksException, PustaListaException {
		if (list.isEmpty()) {
			throw new PustaListaException();
		}
		if (index < 0 || index >= list.size()) {
			throw new ZlyIndeksException(index, list.size());
		}
		list.remove(index);
	}

	@Override
	public String toString() {
		return list.toString();
	}

}

class ZlyIndeksException extends Exception {
	public ZlyIndeksException(int indeks, int rozmiar) {
		super("Zly indeks: " + indeks + ". Lista ma " + rozmiar + " elementow (indeksy 0-" + (rozmiar - 1) + ").");
	}
}

class BrakObiektuException extends Exception {
	public BrakObiektuException(String komunikat) {
		super(komunikat);
	}
}

class PustaListaException extends BrakObiektuException {
	public PustaListaException() {
		super("Lista jest pusta.");
	}
}