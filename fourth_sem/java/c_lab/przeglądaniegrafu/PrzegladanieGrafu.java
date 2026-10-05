import java.util.LinkedList;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

/*


Utworzyć klasę abstrakcyjną PrzegladanieGrafu realizującą algorytm przeglądania grafu. 
Do przechowywania kolejnych do odwiedzenia wierzchołków wykorzystać klasę LinkedList.
Jako metody abstrakcyjne utworzyć metody wstaw(-) oraz pobierz() numer wierzchołka.
Prosty graf zakodować w postaci macierzy sąsiedztwa (np. podawanej w konstruktorze klasy), 
a następnie utworzyć klasy DFS oraz BFS realizujące algorytmy przeglądania grafu w głąb oraz wszerz. Pobierz dane ze standardowego wejścia:
• linia 1: lista N wierzchołków grafu oddzielona spacjami (każdy wierzchołek to litera
• linie 2-N+1: listy sąsiedztwa oddzielone spacjami (wierzchołek lista sąsiadów)
• linia N+2: wierzchołek startowy
• linia N+3: algorytm (DFS lub BFS)
Wyświetl wierzchołki w kolejności odwiedzin.

*/

abstract public class PrzegladanieGrafu {

	public static void main (String[] args) {

		Scanner input = new Scanner(System.in);

		String[] vertices = input.nextLine().trim().split(" ");
		int n = vertices.length;

		Map<String, Integer> vertexIndexes = new HashMap<>();
		for (int i = 0 ; i < n ; i++) {
			vertexIndexes.put(vertices[i], i);
		}

		// Adjacency matrix
		int[][] adjencyMatrix = new int[n][n];

		for (int i = 0 ; i < n ; i++) {
			String[] neighbours = input.nextLine().trim().split(" ");
			int u = vertexIndexes.get(neighbours[0]);

			for (int j = 1 ; j < neighbours.length ; j++) {
				int v = vertexIndexes.get(neighbours[j]);
				adjencyMatrix[u][v] = 1;
			}
		}

		String source = input.nextLine().trim();
		int sourceIndex = vertexIndexes.get(source);

		String algorithm = input.nextLine().trim();
		input.close();

		PrzegladanieGrafu graph;
		if (algorithm.equals("DFS")) {
			graph = new DFS(adjencyMatrix, vertices);
		} else if (algorithm.equals("BFS")) {
			graph = new BFS(adjencyMatrix, vertices);
		} else {
			System.out.println("Nieznany algorytm");
			return;
		}

		graph.search(sourceIndex);

	}

	protected LinkedList<Integer> toVisit;
	protected int[][] adjencyMatrix;
	protected String[] vertices;
	protected boolean[] visited;

	public PrzegladanieGrafu(int[][] adjencyMatrix, String[] vertices) {
		this.adjencyMatrix = adjencyMatrix;
		this.vertices = vertices;
		this.toVisit = new LinkedList<>();
		this.visited = new boolean[vertices.length];
	}

	abstract void wstaw(int vertex);
	abstract int pobierz();
	abstract void addNeighbour(int current);

	public void search(int start) {
		wstaw(start);
		
		while (!toVisit.isEmpty()) {
			int current = pobierz();

			if (!visited[current]) {
				visited[current] = true;
				System.out.print(vertices[current] + " ");
				addNeighbour(current);
			}
		}
		System.out.println();
	}

}

class DFS extends PrzegladanieGrafu {
	public DFS(int[][] adjencyMatrix, String[] vertices) {
		super(adjencyMatrix, vertices);
	}

	@Override
	void wstaw(int vertex) {
		toVisit.addFirst(vertex);
	}

	@Override
	int pobierz() {
		return toVisit.removeFirst();
	}

	@Override
	protected void addNeighbour(int current) {
		for (int i = adjencyMatrix.length - 1 ; i >= 0 ; i--) {
			if (adjencyMatrix[current][i] == 1 && !visited[i]) {
				wstaw(i);
			}
		}
	}

}

class BFS extends PrzegladanieGrafu {

	public BFS(int[][] adjencyMatrix, String[] vertices) {
		super(adjencyMatrix, vertices);
	}

	@Override
	void wstaw(int vertex) {
		toVisit.addLast(vertex);
	}

	@Override
	int pobierz() {
		return toVisit.removeFirst();
	}

	@Override
	protected void addNeighbour(int current) {
		for (int i = 0 ; i < adjencyMatrix.length ; i++) {
			if (adjencyMatrix[current][i] == 1 && !visited[i]) {
				wstaw(i);
			}
		}
	}

}
