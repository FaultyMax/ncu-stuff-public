import java.util.LinkedList;
 
public class DFS extends PrzegladanieGrafu {
 
    private LinkedList<Integer> stos = new LinkedList<>();
 
    public DFS(int[][] macierz, String[] wierzcholki) {
        super(macierz, wierzcholki);
    }
 
    @Override
    public void wstaw(int v) { stos.addFirst(v); }
 
    @Override
    public int pobierz() { return stos.removeFirst(); }
 
    @Override
    public boolean czyPusta() { return stos.isEmpty(); }
}
 