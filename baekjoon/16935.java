package com.ssafy;

import java.io.*;
import java.util.StringTokenizer;

public class BJ16935 {
	static StringBuilder sb = new StringBuilder();
	static int N, M, R;
	static int[][] arr;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().split(" ");
		N = Integer.parseInt(s[0]);
		M = Integer.parseInt(s[1]);
		R = Integer.parseInt(s[2]);
		arr = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < R; i++) {
			int cmd = Integer.parseInt(st.nextToken());
			
			switch (cmd) {
			case 1:
				rotate1();
				break;
			case 2:
				rotate2();
				break;
			case 3:
				rotate3();
				break;
			case 4:
				rotate4();
				break;
			case 5:
				rotate5();
				break;
			case 6:
				rotate6();
				break;
			default:
				break;
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(arr[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

	static void rotate1() {
		int n2 = N/2;
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < M; j++) {
				int tmp = arr[i][j];
				arr[i][j] = arr[N-i-1][j];
				arr[N-i-1][j] = tmp;
			}
		}		
	}
	
	static void rotate2() {
		int m2 = M/2;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < m2; j++) {
				int tmp = arr[i][j];
				arr[i][j] = arr[i][M-j-1];
				arr[i][M-j-1] = tmp;
			}
		}		
	}
	
	static void rotate3() {
		int[][] tmpArr = new int[M][N];
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				tmpArr[i][j] = arr[N-j-1][i];
			}
		}
		arr = tmpArr;
		int tmp = N;
		N = M;
		M = tmp;
	}
	
	static void rotate4() {
		int[][] tmpArr = new int[M][N];
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				tmpArr[i][j] = arr[j][M-i-1];
			}
		}
		arr = tmpArr;
		int tmp = N;
		N = M;
		M = tmp;
	}
	
	static void rotate5() {
		int n2 = N/2;
		int m2 = M/2;
		
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {				
				int tmp = arr[i][j];
				arr[i][j] = arr[i+n2][j];
				arr[i+n2][j] = arr[i+n2][j+m2];
				arr[i+n2][j+m2] = arr[i][j+m2];
				arr[i][j+m2] = tmp;
			}
		}
	}
	
	static void rotate6() {
		int n2 = N/2;
		int m2 = M/2;
		
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				int tmp = arr[i][j];
				arr[i][j] = arr[i][j+m2];
				arr[i][j+m2] = arr[i+n2][j+m2];
				arr[i+n2][j+m2] = arr[i+n2][j];
				arr[i+n2][j] = tmp;
			}
		}
	}
}
