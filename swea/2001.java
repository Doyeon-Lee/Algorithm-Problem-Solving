package hw;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SW2001_0204 {
	static int T, N;
	static int[][] flyArea;
	
	static int getFly1DCnt(int x, int y, int m) {
		int sum = 0;
		for (int i = 0; i < m; i++) 
			sum += flyArea[x][y+i];
		
		return sum;
	}
	
	static int getFly2DCnt(int x, int y, int m) {
		int sum = 0;
		for (int i = 0; i < m; i++) 
			for (int j = 0; j < m; j++) 
				sum += flyArea[x+i][y+j];
		
		return sum;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		
		for (int t = 1; t <= T; t++) {
			String nm = br.readLine();
			int N = Integer.parseInt(nm.split(" ")[0]);
			int M = Integer.parseInt(nm.split(" ")[1]);
			flyArea = new int[N][N];
			int maxCnt = 0; //최대 파리 마릿수
			
			//파리 정보 입력
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					flyArea[i][j] = Integer.parseInt(st.nextToken());
				}				
			}
			
			//최대 마릿수 탐색
			//첫번째 열만 전부 계산한 후 그 밑은 변화되는(위, 아래 한줄씩) 값들만 계산
			int maxFlyArrLen = N-M+1;
			int[][] maxFlyArr = new int[maxFlyArrLen][maxFlyArrLen];
			for (int i = 0; i < N-M+1; i++) {
				maxFlyArr[0][i] = getFly2DCnt(0, i, M);
				maxCnt = Math.max(maxCnt, maxFlyArr[0][i]);
			}

			for (int i = 1; i < maxFlyArrLen; i++) {
				for (int j = 0; j < maxFlyArrLen; j++) {
					maxFlyArr[i][j] = maxFlyArr[i-1][j] - getFly1DCnt(i-1, j, M) + getFly1DCnt(i+M-1, j, M);
					maxCnt = Math.max(maxCnt, maxFlyArr[i][j]);
				}
			}
			
			sb.append("#").append(t).append(" ").append(maxCnt).append("\n");
		}
		System.out.println(sb);
	}
}
