public class MonteCarlo {

		public static double metodaMonteCarlo(int n) {

			Figura kolo = new Figura(1);
			kolo.ustaw("Kolo");

			java.util.Random rand = new java.util.Random();
			
			double counter = 0;
			
			for(int i = 0 ; i < n ; i++){
				double x = rand.nextDouble();
				double y = rand.nextDouble();
				if (kolo.czyPunktJestWewnątrz(x,y)){ counter++; }
			}
			
			counter = (counter * 4) / n;

			return counter;

		}

		public static void main(String[] args){
			
			System.out.println(metodaMonteCarlo(1000));
			System.out.println(metodaMonteCarlo(10000));
			
		}
	}

