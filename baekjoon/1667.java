package second;

import java.io.*;
import java.util.*;

public class BJ1667 {
	static int[] dx = {-1, 0, 1, 0}; //위쪽부터 시계방향
	static int[] dy = {0, 1, 0, -1};
	static char[][] houseMap;
	static int N;
	static List<Integer> houseCnt = new ArrayList<Integer>();
	
	
	static boolean inBound(int x, int y) {
		return !(x < 0 || y < 0 || x >= N || y >= N);
	}
	
	static int dfs(int x, int y) {
		if(houseMap[x][y] == '0') return 0;
		houseMap[x][y] = '0'; //방문했음
		int cnt = 1;
		
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			
			if(inBound(nextX, nextY)) 
				cnt += dfs(nextX, nextY);
		}
		return cnt;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		houseMap = new char[N][N];
		
		//단지 정보 저장
		for (int i = 0; i < N; i++) 
			houseMap[i] = br.readLine().toCharArray();

		//단지 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(houseMap[i][j] == '1')
					houseCnt.add(dfs(i, j));
			}
		}
		
		//정렬 후 결과 출력
		Collections.sort(houseCnt);
		System.out.println(houseCnt.size());
		for (int num : houseCnt) 
			System.out.println(num);
	}
}
