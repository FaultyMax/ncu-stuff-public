
public class TabliczkaMnozenia {
	public void wypiszTabliczkeMnozenia(int n){
		for (int i = 1 ; i <= n ; i++){
			for (int j = 1 ; j <= n ; j++){
				System.out.printf("%d\t",i*j);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args){
		
		TabliczkaMnozenia t = new TabliczkaMnozenia();
		
		if (args.length == 1){
			t.wypiszTabliczkeMnozenia(Integer.parseInt(args[0]));
		}
	}	
	
}


