package cter;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Counter extends Thread{

	public static void main(String[] args) { 

		Counter c1 = new Counter();
		c1.start();

		Counter c2 = new Counter();
		

	}

	int ident;
	static int licznik;

	public Counter() {
		ident = licznik++;
	}

	@Override
	public void run() {
		for (int i=1 ; i<=100 ; i++){
			try{
				System.out.println("Wątek " + ident + ": " + i);
				Random r = new Random();
				int milisekundy = r.nextInt(101);
				Thread.sleep(milisekundy)
			} catch (InterruptedException x) {
				Logger.getLogger(Counter.class.getName()).log(Level.SEVERE, null);
			}
		}
	}
}