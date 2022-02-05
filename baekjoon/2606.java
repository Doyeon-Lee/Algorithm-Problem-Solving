package second;

import java.util.Scanner;

public class BJ2606 {
	static boolean[][] network;
	static boolean[] visited;	
	static int N, edgeCnt;
	
	static int dfs(int curNum) {
		if(visited[curNum]) return 0;
		
		visited[curNum] = true;
		int cnt = 1;
		
		for (int i = 1; i <= N; i++) {
			if(network[curNum][i])
				cnt += dfs(i);
		}
	
		return cnt;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		edgeCnt = sc.nextInt();
		network = new boolean[N+1][N+1];
		visited = new boolean[N+1];
			
		for (int i = 0; i < edgeCnt; i++) {
			int node1 = sc.nextInt();
			int node2 = sc.nextInt();
			network[node1][node2] = true;
			network[node2][node1] = true;
		}
		System.out.println(dfs(1)-1);
		
		sc.close();
	}
}
