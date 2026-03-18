
public class Calkowanie{
	
	public double obliczKwadratowe(double a, double b, double c, double x1, double x2){
		return (a/3)*(Math.pow(x2,3)-Math.pow(x1,3)) + (b/2)*(Math.pow(x2,2)-Math.pow(x1,2)) + c*(x2-x1);
	}
	
	public static void main(String[] args){
		
		Calkowanie t = new Calkowanie();
		
		if (args.length == 5){
			double a = Float.parseFloat(args[0]);
			double b = Float.parseFloat(args[1]);
			double c = Float.parseFloat(args[2]);
			double x = Float.parseFloat(args[3]);
			double y = Float.parseFloat(args[4]);
			
			System.out.printf("%f\n",t.obliczKwadratowe(a,b,c,x,y));
		}
		
	}
}
