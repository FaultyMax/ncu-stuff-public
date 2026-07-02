import java.util.*;

/*

Stwórz klase generyczna MaszynaLosujaca przechowujaca dowolne elementy i umozliwiajaca
losowanie ich za pomoca metody losujElement() (bez powtórzen). Stwórz metode zwracajaca
wszystkie przechowywane elementy na liscie (ArrayList) w losowej kolejnosci (losujListe()).
• tylko elementów typu Koło,
• elemntów typu Figura.

*/

public class MaszynaLosujaca<E> {

	public static void main(String[] args) {

		MaszynaLosujaca<Circle> CircleMachine = new MaszynaLosujaca<>();

		CircleMachine.add(new Circle(5));
		CircleMachine.add(new Circle(2));
		CircleMachine.add(new Circle(9));
		CircleMachine.add(new Circle(16));

		System.out.println("Random list (Circles):");
		for (Figure f : CircleMachine.losujListe()) {
			System.out.println(" " + f);
		}

		System.out.println("Drawing elements...");
		while (CircleMachine.size() > 0) {
			System.out.println(" I got: " + CircleMachine.losujElement());
		}

		MaszynaLosujaca<Figure> figureMachine = new MaszynaLosujaca<>();

		figureMachine.add(new Circle(5));
		figureMachine.add(new Circle(2));
		figureMachine.add(new Square(6));
		figureMachine.add(new Square(7));
		figureMachine.add(new EquilateralTriangle(3));

		System.out.println("Random list:");
		for (Figure f : figureMachine.losujListe()) {
			System.out.println(" " + f);
		}

		System.out.println("Drawing elements...");
		while (figureMachine.size() > 0) {
			System.out.println(" I got: " + figureMachine.losujElement());
		}

	} 

	private ArrayList<E> elements;

	public MaszynaLosujaca() {
		elements = new ArrayList<>();
	}

	
	public void add(E element) {
		elements.add(element);
	}

	public E losujElement() {
		if (elements.isEmpty()) {
			throw new java.util.NoSuchElementException("Machine is empty");
		}
		int index = (int) (Math.random() * elements.size());
		return elements.remove(index);
	}

	public ArrayList<E> losujListe() {
		ArrayList<E> copy = new ArrayList<>(elements);
		Collections.shuffle(copy);
		return copy;
	}

	public int size() {
		return elements.size();
	}

}

abstract class Figure implements Comparable<Figure> {
 
    public abstract double getArea();
    public abstract String getType();
 
    @Override
    public int compareTo(Figure other) {
        return Double.compare(this.getArea(), other.getArea());
    }
}

class Circle extends Figure {

    private double radius;
 
    public Circle(double radius) {
        this.radius = radius;
    }
 
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
 
    @Override
    public String getType() { return "C"; }
 
    @Override
    public String toString() {
        return String.format("C %.4f", getArea());
    }
}

class Square extends Figure {

    private double side;
 
    public Square(double side) {
        this.side = side;
    }
 
    @Override
    public double getArea() {
        return side * side;
    }
 
    @Override
    public String getType() { return "S"; }
 
    @Override
    public String toString() {
        return String.format("S %.4f", getArea());
    }
}

class EquilateralTriangle extends Figure {

    private double side;
 
    public EquilateralTriangle(double side) {
        this.side = side;
    }
 
    @Override
    public double getArea() {
        return (Math.sqrt(3) / 4) * side * side;
    }
 
    @Override
    public String getType() { return "T"; }
 
    @Override
    public String toString() {
        return String.format("T %.4f", getArea());
    }
}
