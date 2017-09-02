package small_exe;

public class PrintEven {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long starTime = System.currentTimeMillis();
		method3(10000);
		long endTime = System.currentTimeMillis();
		long Time = endTime - starTime;
		System.out.println(Time);
	}
	private static void method0 (int MAX) {
		int cntr=1;
		while(cntr<=MAX) {
			if (cntr%2==0) {
				System.out.println("NUM="+cntr);
			}
			cntr++;
		}
	}


	private static void method1 (int MAX) {
		int cntr=1;
		boolean is_even=false;
		while(cntr<=MAX) {
			if (is_even) {
				System.out.println("NUM="+cntr);
			}
			cntr++;
			is_even=!is_even;
		}
	}

	private static void method2 (int MAX) {
		int cntr=1;
		while(cntr<=MAX/2) {
			System.out.println("NUM="+cntr*2);
			cntr++;
		}
	}
	private static void method3 (int MAX) {
		int cntr=1;
		String ans="";
		while(cntr<=MAX/2) {
//			System.out.println("NUM="+cntr*2);
			ans+=cntr*2+",";
			cntr++;
		}
		System.out.println(ans);
	}
}
