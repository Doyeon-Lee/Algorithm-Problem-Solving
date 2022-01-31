import java.util.Scanner;

public class Main {
	public static double calcDistance(int x1, int y1, int x2, int y2) {
		return Math.sqrt((Math.pow(x1-x2, 2) + Math.pow(y1-y2, 2)));
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		
		for (int t = 0; t < testCase; t++) {
			int x1, y1, x2, y2, n;
			int answerCnt = 0;
			
			x1 = sc.nextInt(); y1 = sc.nextInt();
			x2 = sc.nextInt(); y2 = sc.nextInt();
			n = sc.nextInt(); //행성계의 개수
			int a, b, c;
			
			for (int i = 0; i < n; i++) {
				a = sc.nextInt();
				b = sc.nextInt();
				c = sc.nextInt();
				
				//0 1 혹은 1 0이어야 성립
				if((calcDistance(a, b, x1, y1) < c) ^ (calcDistance(a, b, x2, y2) < c)){
					answerCnt++;	
				}	
			}
			
			System.out.println(answerCnt);
		}
		
	}
}