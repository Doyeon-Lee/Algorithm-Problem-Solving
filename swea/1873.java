package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SW1873 {
	static char[] playerIcon = {'^', '>', 'v', '<'}; //위쪽부터 시계방향
	static int[] xMove = {-1, 0, 1, 0};
	static int[] yMove = {0, 1, 0, -1};	
	static char[][] gameMap;
	static int H, W, N;
	static Player p;
	
	
	static class Player{
		public int playerX, playerY, playerDir;
		
		public Player(int x, int y, int d){
			playerX = x;
			playerY = y;
			playerDir = d;
		}
		
		boolean inBound(int x, int y) {
			return !(x < 0 || y < 0 || x >= H || y >= W);
		}
		
		//벽이 없다면 플레이어를 한 칸 이동
		void move() {
			int xNext = playerX + xMove[playerDir];
			int yNext = playerY + yMove[playerDir];
			
			if(inBound(xNext, yNext) && gameMap[xNext][yNext] == '.') {
				gameMap[playerX][playerY] = '.';
				playerX = xNext;
				playerY = yNext;
			}
			gameMap[playerX][playerY] = playerIcon[playerDir];
		}
		
		void shoot() {
			int bulletX = playerX; int bulletY = playerY;
			
			while(inBound(bulletX, bulletY)) {				
				if(gameMap[bulletX][bulletY] == '*') { //벽돌벽이면 벽 부숨
					gameMap[bulletX][bulletY] = '.';
					break;
				}
				else if(gameMap[bulletX][bulletY] == '#') //강철벽이면 총알 소멸
					break;
			
				if(playerDir == 0) bulletX--;
				else if(playerDir == 1) bulletY++;
				else if(playerDir == 2) bulletX++;
				else bulletY--;
			}
		}
	}

	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int testCase = Integer.parseInt(br.readLine());

		for (int t = 1; t <= testCase; t++) {
			//게임판 저장
			String hwStr = br.readLine();
			H = Integer.parseInt(hwStr.split(" ")[0]);
			W = Integer.parseInt(hwStr.split(" ")[1]);
			gameMap = new char[H][W];
			
			for (int i = 0; i < H; i++) {
				String tmp = br.readLine();
				gameMap[i] = tmp.toCharArray();
				for (int d = 0; d < 4; d++) {
					int idx = tmp.indexOf(playerIcon[d]);
					if(idx != -1) { //플레이어 정보 저장
						p = new Player(i, idx, d);
						break;
					}
				}
			}
			
			//명령어 입력
			N = Integer.parseInt(br.readLine());
			char[] cmd = br.readLine().toCharArray();
			
			//명령어 처리
			for (char c : cmd) {
				switch(c) {
				case 'U':
					p.playerDir = 0;
					p.move();
					break;
				case 'R':
					p.playerDir = 1;
					p.move();
					break;
				case 'D':
					p.playerDir = 2;
					p.move();
					break;
				case 'L':
					p.playerDir = 3;
					p.move();
					break;
				case 'S':
					p.shoot();
					break;
				}
			}
			
			//결과 출력
			sb.append("#").append(t).append(" ");
			for (int i = 0; i < H; i++) 
					sb.append(gameMap[i]).append("\n");
		}		
		System.out.println(sb);
	}
}
