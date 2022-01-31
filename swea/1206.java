import java.util.Scanner;

public class Solution {
	public static int testCaseCnt = 10;
	
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		for (int t = 1; t <= testCaseCnt;t++) {
			int buildingCnt = sc.nextInt();
			int[] buildingHeight = new int[buildingCnt];
			int answer = 0;
			
			//빌딩 높이 입력받기
			for (int i = 0; i < buildingCnt; i++)
				buildingHeight[i] = sc.nextInt();

			//세대수 계산하기
			for (int i = 2; i < buildingCnt-2; i++) { //양 옆 2칸은 비어있음
				int leftMax = Math.max(buildingHeight[i-2], buildingHeight[i-1]);
				int rightMax = Math.max(buildingHeight[i+2], buildingHeight[i+1]);
				int nearMax = Math.max(leftMax, rightMax);
				answer += Math.max(buildingHeight[i] - nearMax, 0);
			}
			System.out.printf("#%d %d\n", t, answer);
		}
	}
}