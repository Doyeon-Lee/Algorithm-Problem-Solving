import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long minInput = sc.nextLong();
		long maxInput = sc.nextLong();
		int answer = 0;
		
		long maxVal = (int)Math.sqrt(maxInput);
		int arrLength = (int) (maxInput - minInput + 1);
		boolean[] primeYesNumber = new boolean[arrLength]; //최대 범위
		
		for (long i = 2; i <= maxVal; i++) {
			long squareNum =  i * i;
			long start = (minInput % squareNum == 0) ? minInput : (minInput / squareNum + 1) * squareNum;
			for (long j = start; j <= maxInput; j += squareNum) {
				int idx = (int) (j - minInput);
				primeYesNumber[idx] = true;
			}
		}
		
		for (boolean flag : primeYesNumber) {
			if(!flag) answer++;
		}
		System.out.println(answer);
		sc.close();
	}
}