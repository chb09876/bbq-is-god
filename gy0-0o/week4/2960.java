import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static boolean[] arr;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int K = scan.nextInt();
		func_prime(N,K);
		scan.close();
	}
	
	public static void func_prime(int N, int K) {
		if (N < 2) return;
		arr = new boolean[N + 1];
		Arrays.fill(arr, false);
		arr[0] = arr[1] = true;
		int cnt = 0;
		for (int i = 2; i <= N; i++) {
			for (int j = i; j < arr.length; j = j+i) {
				if (arr[j]) continue;
				arr[j] = true;
				cnt++;
				if (cnt == K) {
					System.out.println(j);
				}
			}
		}
	}
}
