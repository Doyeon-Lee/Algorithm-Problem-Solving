package second;

import java.io.*;
import java.util.*;

public class BJ1260 {
	static StringBuffer sb = new StringBuffer();
	static int N, M, V;
	static boolean[] visited;
	static boolean[][] graph;
	
	static void dfs(int curNode) {
		if(visited[curNode]) return;
		
		visited[curNode] = true;
		sb.append(curNode).append(" ");
		for (int i = 1; i <= N; i++) {
			if(graph[curNode][i]) 
				dfs(i);
		}
	}
	
	static void bfs(int root) {
		//왜 arraylist대신 linkedlist를 사용하는가?
		//https://devlog-wjdrbs96.tistory.com/246
		Queue<Integer> nextNode = new LinkedList<>();
		nextNode.add(root);
		
		while(!nextNode.isEmpty()) {
			int curNode = nextNode.poll();
			if(visited[curNode]) continue;
			
			visited[curNode] = true;
			sb.append(curNode).append(" ");
			for (int i = 1; i <= N; i++) {
				if(graph[curNode][i]) 
					nextNode.add(i);
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		
		//초기화 작업
		visited = new boolean[N+1];
		graph = new boolean[N+1][N+1];
		
		//간선 정보 저장
		for (int i = 0; i < M; i++) {
			String edgeStr = br.readLine();
			int node1 = Integer.parseInt(edgeStr.split(" ")[0]);
			int node2 = Integer.parseInt(edgeStr.split(" ")[1]);
			graph[node1][node2] = true;		
			graph[node2][node1] = true;		
		}
		
		//탐색 시작
		dfs(V);
		Arrays.fill(visited, false);
		sb.append("\n");
		bfs(V);
		System.out.println(sb);
	}
}
