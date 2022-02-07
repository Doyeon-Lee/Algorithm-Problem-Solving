package hw;

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Bj2493_0207 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		Stack<Pair> building = new Stack<>();

		for (int i = 1; i <= N; i++) {
			int height = Integer.parseInt(st.nextToken());
			int receiveBuilding = 0;

			while (!building.isEmpty()) {
				Pair p = building.pop();
				if(p.height >= height) {
					receiveBuilding = p.idx;
					building.add(p);
					break;
				}
			}
			building.add(new Pair(i, height));
			sb.append(receiveBuilding).append(" ");
		}
		System.out.println(sb);
	}
}

class Pair {
	int idx, height;

	Pair(int idx, int height) {
		this.idx = idx;
		this.height = height;
	}
}