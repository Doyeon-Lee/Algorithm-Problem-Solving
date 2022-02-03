package hw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SW1954_0203 {
	static int[] xMove = { 0, 1, 0, -1 };
	static int[] yMove = { 1, 0, -1, 0 };
	static int testCase, n;

	public static boolean inBound(int x, int y) {
		return !(x < 0 || y < 0 || x >= n || y >= n);
	}

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();

		try {
			testCase = Integer.parseInt(br.readLine());
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}

		for (int t = 1; t <= testCase; t++) {
			try {
				n = Integer.parseInt(br.readLine());
			} catch (NumberFormatException | IOException e) {
				e.printStackTrace();
			}

			int[][] numArr = new int[n][n];
			int num = 1;
			int d = 0;
			int x = 0;
			int y = -1;

			while (num <= n * n) {
				int xNext = x + xMove[d];
				int yNext = y + yMove[d];

				if (inBound(xNext, yNext) && numArr[xNext][yNext] == 0) {
					numArr[xNext][yNext] = num++;
					x = xNext;
					y = yNext;
				}
				else {
					d++;
					d %= 4;
				}
			}

			sb.append("#").append(t).append("\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					sb.append(numArr[i][j]).append(" ");
				}
				sb.append("\n");
			}
		}
		System.out.println(sb);
	}
}
