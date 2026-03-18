public class MonteCarlo {

		public static void main(String[] args){
			Figura kolo = new Figura();
			kolo.ustaw("Kolo");
			kolo.ustaw(1);
			
			int n = 10000;
			
			java.util.Random rand = new java.util.Random();
			
			double counter = 0;
			
			for(int i = 0 ; i < n ; i++){
				double x = rand.nextDouble();
				double y = rand.nextDouble();
				if (kolo.czyPunktJestWewnątrz(x,y)){ counter++; }
			}
			
			counter = (counter * 4)/ n;
			
			System.out.println(counter);
			
			//System.out.println(kolo.czyPunktJestWewnątrz(2,2));
			//System.out.println(kolo.czyPunktJestWewnątrz(3,4));
			//System.out.println(kolo.czyPunktJestWewnątrz(2,5));
			
		}
	}

