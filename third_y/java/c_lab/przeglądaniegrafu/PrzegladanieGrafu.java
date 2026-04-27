import java.util.LinkedList;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

abstract public class PrzegladanieGrafu {

	public static void main (String[] args) {

		Scanner input = new Scanner(System.in);

		String[] vertices = input.nextLine().trim().split("\\s");
		int n = vertices.length;

		Map<String, Integer> vertexIndexes = new HashMap<>();
		for (int i = 0 ; i < n ; i++) {
			vertexIndexes.put(vertices[i], i);
		}

		// Adjacency matrix
		int[][] adjencyMatrix = new int[n][n];

		for (int i = 0 ; i < n ; i++) {
			String[] neighbours = input.nextLine().trim().split("\\s");
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

	abstract void put(int vertex);
	abstract int getFirst();
	abstract void addNeighbour(int current);

	public void search(int start) {
		put(start);

		while (!toVisit.isEmpty()) {
			int current = getFirst();

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
	void put(int vertex) {
		toVisit.addFirst(vertex);
	}

	@Override
	int getFirst() {
		return toVisit.removeFirst();
	}

	@Override
	protected void addNeighbour(int current) {
		for (int i = adjencyMatrix.length - 1 ; i >= 0 ; i--) {
			if (adjencyMatrix[current][i] == 1 && !visited[i]) {
				put(i);
			}
		}
	}

}

class BFS extends PrzegladanieGrafu {

	public BFS(int[][] adjencyMatrix, String[] vertices) {
		super(adjencyMatrix, vertices);
	}

	@Override
	void put(int vertex) {
		toVisit.addLast(vertex);
	}

	@Override
	int getFirst() {
		return toVisit.removeFirst();
	}

	@Override
	protected void addNeighbour(int current) {
		for (int i = 0 ; i < adjencyMatrix.length ; i++) {
			if (adjencyMatrix[current][i] == 1 && !visited[i]) {
				put(i);
			}
		}
	}

}
