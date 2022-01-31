import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static int sudokuSize = 9;
	static int[][] sudoku = new int[sudokuSize][sudokuSize];
	public static ArrayList<int[]> blank = new ArrayList<>();

	//해당 칸에 들어갈 수 있는 후보 숫자들 리턴
	public static ArrayList<Integer> getCandidateNum(int x, int y){
		ArrayList<Integer> retArr = new ArrayList<>();
		boolean[] isUsed = new boolean[10]; //0~9 쓰였는가?
		
		//가로, 세로줄 확인	
		for(int i = 0;i < sudokuSize;i++) {
			isUsed[sudoku[i][y]] = true;
			isUsed[sudoku[x][i]] = true;
		}
		
		//3x3 블록 확인
		int xBlock = x - x%3; // 해당 칸이 속한 3x3의 첫 인덱스
		int yBlock = y - y%3;
		
		for (int i = xBlock; i < xBlock+3; i++)
			for (int j = yBlock; j < yBlock+3; j++) 
				isUsed[sudoku[i][j]] = true;

		
		//사용되지 않은 숫자들 리스트로 반환
		for (int i = 1; i < isUsed.length; i++)
			if(!isUsed[i]) retArr.add(i);

		return retArr;
	}
	
	public static void printArr() {
		for (int i = 0; i < sudokuSize; i++) {
			for (int j = 0; j < sudokuSize; j++) {
				System.out.print(sudoku[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public static void dfs(int idx) {
		if(idx == blank.size()) {
			printArr();
			System.exit(0);
		}
		
		int x = blank.get(idx)[0];
		int y = blank.get(idx)[1];
		ArrayList<Integer> candidateNum = getCandidateNum(x, y);
		
		for (int num : candidateNum) {
			sudoku[x][y] = num;
			dfs(idx+1);
			sudoku[x][y] = 0;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 스도쿠판 입력
		for (int i = 0; i < sudokuSize; i++) {
			for (int j = 0; j < sudokuSize; j++) {
				sudoku[i][j] = sc.nextInt();
				if (sudoku[i][j] == 0) {
					int[] tmp = {0, 0};
					tmp[0] = i;
					tmp[1] = j;
					blank.add(tmp); //빈칸만 모아둠
				}
			}
		}
		sc.close();
		dfs(0);
	}
}