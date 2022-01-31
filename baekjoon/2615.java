import java.io.FileNotFoundException;
import java.util.Scanner;

/*
 가장 왼쪽에 있는 바둑알의 좌표를 그때마다 찾는 것은 쉽지 않다. 따라서, 내가 현재 보고 있는 바둑알이 가장 왼쪽이 되도록 한다.
 왼쪽 위부터 아래로,오른쪽으로 탐색하면 4개의 방향만 탐색하면 된다. (오른쪽으로,아래로 탐색하면 6알이 성립함)
 참고 블로그: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kerochuu&logNo=221792539488
 */

public class Main {
	public static int omokSize = 21; // 범위 검사 안해도 되도록 padding 설정
	public static int[][] omokMap = new int[omokSize][omokSize];
	public static int[][][] memo = new int[omokSize][omokSize][4]; // 4개의 방향에 대한 연속 오목 개수 기록
	public static int[] xMove = { -1, 0, 1, 1 };
	public static int[] yMove = { 1, 1, 1, 0 };
	public static String answer;

	public static void searchFive() {
		for (int j = 1; j < omokSize - 1; j++) {
			for (int i = 1; i < omokSize - 1; i++) {
				// 흰색이거나 검정색이면 4개의 방향에 대해서 연속된 오목의 개수 찾음
				int curColor = omokMap[i][j];
				if (curColor != 0) {
					for (int k = 0; k < 4; k++) {
						if (memo[i][j][k] == 0 && recordMemo(i, j, k, curColor) == 5) {
							answer = curColor + "\n" + i + " " + j;
							return;
						}
					}
				}
			}
		}
		answer = "0";
	}

	public static int recordMemo(int x, int y, int dir, int color) {
		int xNext = x + xMove[dir];
		int yNext = y + yMove[dir];

		if (omokMap[xNext][yNext] == color) {
			memo[x][y][dir] = recordMemo(xNext, yNext, dir, color) + 1;
			return memo[x][y][dir];
		}
		return 1; // 혼자만임
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		// 오목판 입력받기
		for (int i = 1; i < omokSize - 1; i++)
			for (int j = 1; j < omokSize - 1; j++)
				omokMap[i][j] = sc.nextInt();
		sc.close();

		//오목 찾기
		searchFive();		
		System.out.println(answer);
	}
}
