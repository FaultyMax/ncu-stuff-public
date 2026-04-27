
public class Calkowanie{
	
	public double obliczKwadratowe(double a, double b, double c, double x1, double x2){
		return (a/3) * (Math.pow(x2,3)-Math.pow(x1,3))
		+ (b/2) * (Math.pow(x2,2)-Math.pow(x1,2)) 
		+ c * (x2-x1);
	}
	
	public static void main(String[] args){
		
		Calkowanie t = new Calkowanie();
		
		if (args.length == 5){
			try {
				double a = Double.parseDouble(args[0]);
				double b = Double.parseDouble(args[1]);
				double c = Double.parseDouble(args[2]);
				double x = Double.parseDouble(args[3]);
				double y = Double.parseDouble(args[4]);

				System.out.println("" + t.obliczKwadratowe(a,b,c,x,y));

			} catch (NumberFormatException ex) {
				System.out.println("Error: Wszystkie argumenty muszą być liczbami");
			}
		} else {
			System.out.println("Podaj 5 argumentów: a b c x1 x2");
		}
		
	}
}
