package second;

import java.util.*;

public class BJ1012 {
	static int[] dx = {-1, 0, 1, 0}; //위쪽부터 시계방향
	static int[] dy = {0, 1, 0, -1};
	static boolean[][] farm;
	static int N, M, K;
	
	static class Pair {
		int x, y;

		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	

	static boolean inBound(int x, int y) {
		return !(x < 0 || y < 0 || x > N || y > M);
	}
	
	static void bfs(int x, int y) {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(x, y));
		
		while(!q.isEmpty()) {
			Pair curPair = q.poll();
			if(!farm[curPair.x][curPair.y]) continue;
			
			farm[curPair.x][curPair.y] = false;
			for (int i = 0; i < 4;i++) {
				int nextX = curPair.x + dx[i];
				int nextY = curPair.y + dy[i];

				if (inBound(nextX, nextY))
					q.add(new Pair(nextX, nextY));
			}	
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();

		for (int t = 0; t < testCase; t++) {
			N = sc.nextInt(); 
			M = sc.nextInt(); 
			K = sc.nextInt(); 
			
			farm = new boolean[N+1][M+1];
			for (int i = 0; i < K; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				farm[x][y] = true; //배추 표시
			}
			
			int wormCnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if(farm[i][j]) {
						bfs(i, j);
						wormCnt++;
					}
				}
			}
			System.out.println(wormCnt);
		}
		sc.close();
	}
}
