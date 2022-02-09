package com.ssafy;

import java.io.*;
import java.util.StringTokenizer;

public class BJ16926 {
	static int[] dx = {0,1,0,-1}; 
	static int[] dy = {1,0,-1,0};
	static int[][] numArr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String nmStr = br.readLine();

		int N = Integer.parseInt(nmStr.split(" ")[0]);
		int M = Integer.parseInt(nmStr.split(" ")[1]);
		int R = Integer.parseInt(nmStr.split(" ")[2]);
		numArr = new int[N][M];

		// 배열 입력
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				numArr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// 회전
		int railCnt = Math.min(N, M)/2;
		for (int i = 0; i < railCnt; i++)
			for (int j = 0; j < R; j++)
				rotateArr(i, i, N - i, M - i);

		// 출력
		for(int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(numArr[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

	// 회전할 범위: 왼쪽 상단~오른쪽 하단
	static void rotateArr(int x1, int y1, int x2, int y2) {
		int tmp = numArr[x1][y1];
		int direction = 0;
		int curX = x1;
		int curY = y1;
		
		while(direction < 4) {
			int nextX = curX + dx[direction];
			int nextY = curY + dy[direction];

			if(nextX < x1 || nextX >= x2 || nextY < y1 || nextY >= y2) {
				direction++;
			}
			else {
				numArr[curX][curY] = numArr[nextX][nextY];
				curX = nextX;
				curY = nextY;
			}
		}
		numArr[x1+1][y1] = tmp; //N, M은 2 이상
	}
}
