import java.util.LinkedList;
 
public class BFS extends PrzegladanieGrafu {
 
    private LinkedList<Integer> kolejka = new LinkedList<>();
 
    public BFS(int[][] macierz, String[] wierzcholki) {
        super(macierz, wierzcholki);
    }
 
    @Override
    public void wstaw(int v) { kolejka.addLast(v); }
 
    @Override
    public int pobierz() { return kolejka.removeFirst(); }
 
    @Override
    public boolean czyPusta() { return kolejka.isEmpty(); }
}