package day3;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
1. 임의의 노드에서 가장 멀리 있는 노드 찾기(dfs)
2. 해당 노드에서 가장 멀리 있는 노드 찾기(dfs)
=> 2번의 dfs로 '트리'에서 서로 거리가 가장 먼 트리의 지름을 찾을 수 있음!
 */

public class BJ1967 {
	static boolean[] visited;
	static ArrayList<Edge> edgeArr[];
	static int maxDist = 0;
	static int maxIdx = 1; //초기값이 0일 경우 N=1일 때 널포인터 익셉션 발생
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		edgeArr = new ArrayList[N+1];
		visited = new boolean[N+1];
		for (int i = 1; i <= N; i++) 
			edgeArr[i] = new ArrayList<>();
		
		for (int i = 0; i < N-1; i++) { //N-1개 간선
			StringTokenizer st = new StringTokenizer(br.readLine());
			int node1 = Integer.parseInt(st.nextToken());
			int node2 = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			
			edgeArr[node1].add(new Edge(node2, weight));
			edgeArr[node2].add(new Edge(node1, weight));
		}
		
		dfs(1, 0);
		dfs(maxIdx, 0);
		System.out.println(maxDist);
	}
	
	static void dfs(int curNode, int dist) {
		if(visited[curNode]) return;
		
		// 거리가 최대면 업데이트
		if(maxDist < dist) {
			maxDist = dist;
			maxIdx = curNode;
		}
		
		visited[curNode] = true;
		for (Edge e : edgeArr[curNode]) 
			dfs(e.num, dist + e.dist);
		visited[curNode] = false;
	}
}

class Edge{
	int num, dist;

	public Edge(int num, int dist) {
		this.num = num;
		this.dist = dist;
	}
}