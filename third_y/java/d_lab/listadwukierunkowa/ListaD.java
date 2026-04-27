import java.util.*;

public class ListaD<E> {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n = Integer.parseInt(input.nextLine().trim());

		ListaD<Figure> figureList = new ListaD<>();
		ListaD<Figure> circleList = new ListaD<>();

		for (int i = 0 ; i < n+1 ; i++) {

			String line = input.nextLine().trim();
			String[] parts = line.split(" ");
			String type = parts[0];
			double dim = Double.parseDouble(parts[1]);

			Figure figure;

			if (type.equals("C")) {
				Circle k = new Circle(dim);
				figure = k;
				circleList.addElement(k);
			} else if (type.equals("S")) {
				figure = new Square(dim);
			} else if (type.equals("T")) {
				figure = new EquilateralTriangle(dim);
			} else {
				System.err.println("Nieznany typ: " + type);
				continue;
			}
			figureList.addElement(figure);
		}

		input.close();

		figureList.bubbleSort();

		System.out.println(figureList);

	} 

	private class Node {

		E data;
		Node next;
		Node prev;

		Node(E data) {
			this.data = data;
			this.next = null;
			this.prev = null;
		}
	}

	private Node head;
	private Node tail;
	private int size;

	public ListaD() {
		head = null;
		tail = null;
		size = 0;
	}

	public E getNextElement(E element) {
		Node current = head;
		while (current != null) {
			if (current.data.equals(element) && current.next != null) {
				return current.next.data;
			}
			current = current.next;
		}
		return null;
	}

	public E getPrevElement(E element) {
		Node current = head;
		while (current != null) {
			if (current.data.equals(element) && current.prev != null) {
				return current.prev.data;
			}
			current = current.next;
		}
		return null;
	}

	public void addElement(E element) {
		Node newElement = new Node(element);
		if (tail == null) {
			head = newElement;
			tail = newElement;			
		} else {
			newElement.prev = tail;
			tail.next = newElement;
			tail = newElement;
		}
		size++;
	}

	public E getFirstElement() {
		if (head == null) { return null; }
		return head.data;
	}

	public E getLastElement() {
		if (tail == null) { return null; }
		return tail.data;
	}

	public void insertElement(E element, int index) {
		if (index <= 0) {
			Node newElement = new Node(element);
			if (head == null) {
				head = newElement;
				tail = newElement;
			} else {
				newElement.next = head;
				head.prev = newElement;
				head = newElement;
			}
			size++;
		} else if (index >= size) {
			addElement(element);
		} else {
			Node current = head;
			for (int i = 0 ; i < index ; i++) {
				current = current.next;
			}
			Node newElement = new Node(element);
			newElement.prev = current.prev;
			newElement.next = current;
			current.prev.next = newElement;
			current.prev = newElement;
			size++;
		}
	}

	public void insertList(ListaD<E> list) {
		Node current = list.head;
		while (current != null) {
			addElement(current.data);
			current = current.next;
		}
	}

	public ListaD<E> concatList(ListaD<E> list) {
		ListaD<E> newList = new ListaD<>();
		newList.insertList(this);
		newList.insertList(list);
		return newList;
	}

	public int getSize() {
		return size;
	}

	@SuppressWarnings("unchecked")
	public void bubbleSort() {
		if (size <= 1) { return; }
		boolean changed;
		do {
			changed = false;
			Node current = head;
			while (current != null && current.next != null) {
				Comparable<E> a = (Comparable<E>) current.data;
				if (a.compareTo(current.next.data) > 0) {
					E tmp = current.data;
					current.data = current.next.data;
					current.next.data = tmp;
					changed = true;
				}
				current = current.next;
			}
		} while (changed);
	}

	@Override
	public String toString() {
		String desc = "";
		Node current = head;
		while (current != null) {
			desc = desc + current.data + "\n";
			current = current.next;
		}
		return desc;
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
