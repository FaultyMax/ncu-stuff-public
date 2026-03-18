
public class Argumenty
{
	public static void main(String[] args)
	{
		for(int i = 0; i < args.length ; i++){
			System.out.printf("Argument %d : '%s'\n",(i+1),args[i]);
		}
	}
}
