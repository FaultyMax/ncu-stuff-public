import java.io.File;

public class ZawartoscKatalogu {

	public static void main(String[] args) {
		list(".");
	}

	public static void list(String catalogueName) {
		File catalogue = new File(catalogueName);
		for (File f: catalogue.listFiles()) {
			System.out.println(f.getName());
		}
	}

}