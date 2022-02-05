package second;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class BJ2178 {
	static int[] dx = { -1, 0, 1, 0 }; // 위쪽부터 시계방향
	static int[] dy = { 0, 1, 0, -1 };
	static char[][] mazeMap;
	static int N, M;

	// (x, y)까지 도달하는데 걸리는 횟수
	static class Position {
		int x, y, cnt;

		Position(int x, int y, int cnt) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}

	static boolean inBound(int x, int y) {
		return !(x < 0 || y < 0 || x >= N || y >= M);
	}

	static int bfs() {
		Queue<Position> q = new LinkedList<Position>();
		q.add(new Position(0, 0, 1));

		while (!q.isEmpty()) {
			Position curPos = q.poll();
			// 벽이면 패스
			if (mazeMap[curPos.x][curPos.y] == '0')
				continue;

			// (N, M) 도착
			if (curPos.x == N - 1 && curPos.y == M - 1)
				return curPos.cnt;

			mazeMap[curPos.x][curPos.y] = '0';
			for (int i = 0; i < 4; i++) {
				int nextX = curPos.x + dx[i];
				int nextY = curPos.y + dy[i];

				if (inBound(nextX, nextY))
					q.add(new Position(nextX, nextY, curPos.cnt + 1));
			}
		}
		return 0;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String mazeSize = br.readLine();
		N = Integer.parseInt(mazeSize.split(" ")[0]);
		M = Integer.parseInt(mazeSize.split(" ")[1]);
		mazeMap = new char[N][M];

		for (int i = 0; i < N; i++)
			mazeMap[i] = br.readLine().toCharArray();

		System.out.println(bfs());
	}
}
