
/*

	
Dopisać przeciążony, jednoargumentowy konstruktor klasy Figura, który będzie przyjmował początkową wartość własności wymiaru.
Dodać metodę o nazwie czyPunktJestWewnątrz (-,-) sprawdzającą czy dany punkt znajduje się wewnątrz figury. 
Metoda powinna zwracać wartość boolowską, a przyjmować współrzędne punktu na płaszczyźnie. Należy założyć, że:
• figura będzie reprezentować koło,
• środek tego koła znajduje się zawsze w początku układu współrzędnych, 
• wymiar będzie reprezentował promień koła.
Następnie, zaimplementować drugą klasę MonteCarlo, w której należy utworzyć obiekt klasy Figura o wymiarze równym 1. 
W metodzie main(-) losujemy 1000 razy współrzędne punktu z przedziału [0,1]x[0,1].
Do tego celu należy wykorzystać klasę java.util.Random i metodę Random.nextDouble(). 
W kolejnym kroku zliczamy liczbę punktów znajdujących się wewnątrz figury. 
Otrzymany wynik przemnożyć przez 4 i podzielić przez liczbę losowań. Co przypomina otrzymana wartość? Eksperyment powtórzyć dla 10000.

*/

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

