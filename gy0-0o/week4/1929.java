import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int M = scan.nextInt();
		int N = scan.nextInt();
		find_prime(M,N);
		scan.close();
	}
	
	public static void find_prime(int M, int N) {
		for (int i = M; i <= N; i++) {
			if (i < 2) {
				continue;
			}
			
			if (i == 2) {
				System.out.println("2");
				continue;
			}
			
			if (check(i) == 1) {
				continue;
			}
			System.out.println(i);
		}
	}
	
	public static int check(int i) {
		for (int num = 2; num <= Math.sqrt(i); num++) {
			if (i % num == 0) {
				return (1);
			}
		}
		return (0);
	}
}
