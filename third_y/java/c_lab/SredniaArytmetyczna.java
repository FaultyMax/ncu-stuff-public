
public class SredniaArytmetyczna implements Srednia {

	@Override
	public double obliczSrednia(double[] t){
		double suma = 0;
		for( int i = 0; i < t.length ; i++){
			suma += t[i];
		}
		return suma/t.length;
	}

}