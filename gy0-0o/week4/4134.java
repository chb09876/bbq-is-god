import java.util.Scanner;
import java.math.BigInteger;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int	n = scan.nextInt();
		for (int i = 0; i < n; i++) {
			long num = scan.nextLong();
			next_prime(num);
		}
		scan.close();
	}
	
	public static void next_prime(long num) {
		BigInteger nextnum = new BigInteger(String.valueOf(num));
		
		if (nextnum.isProbablePrime(10)) {
			System.out.println(nextnum);
		} else {
			System.out.println(nextnum.nextProbablePrime());
		}
	}
}
