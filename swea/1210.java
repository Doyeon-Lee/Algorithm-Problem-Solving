package hw;

import java.io.*;
import java.util.*;

public class SW1210_0209 {
	static int testCase = 10;
	static int[][] ladderMap;
	static int ladderSize = 100;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		ladderMap = new int[ladderSize][ladderSize];

		int startcol = -1;
		int endcol = -1;

		for (int t = 1; t <= testCase; t++) {
			br.readLine();
			sb.append("#").append(t).append(" ");

			// 입력값 저장
			for (int i = 0; i < ladderSize; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < ladderSize; j++) {
					int num = Integer.parseInt(st.nextToken());
					if (num == 2)
						endcol = j;
					ladderMap[i][j] = num;
				}
			}

			startcol = findStartIdx(endcol);
			sb.append(startcol).append("\n");
		}
		System.out.println(sb);
	}

	static int findStartIdx(int curCol) {
		for (int i = ladderSize - 1; i >= 0; i--) {
			curCol = moveToSide(i, curCol); // 옆에 연결된 다리가 있으면 이동
		}
		return curCol;
	}

	static int moveToSide(int row, int col) {
		boolean flag = false;
		
		while (col + 1 < ladderSize && ladderMap[row][col + 1] == 1) {
			col++;
			flag = true;
		}

		while (col - 1 >= 0 && ladderMap[row][col - 1] == 1) {
			if(flag) break;
			col--;
		}

		return col;
	}
}
