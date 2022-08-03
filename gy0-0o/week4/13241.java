import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long A = scan.nextInt();
		long B = scan.nextInt();
		lcm(A,B);
		scan.close();
	}
	public static long gcd(long A, long B) {
		if (B == 0) return A;
		return gcd(B, A % B);
	}
	public static void lcm(long A, long B) {
		System.out.println(A*B/gcd(A,B));
	}

}