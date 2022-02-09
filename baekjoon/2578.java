package im;

import java.io.*;
import java.util.*;

public class BJ2578 {
	static int bingoSize = 5;
	static boolean[][] erased = new boolean[bingoSize][bingoSize];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Map<Integer, Pair> position = new HashMap<>();
		
		//빙고판 입력
		for (int i = 0; i < bingoSize; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < bingoSize; j++) {
				int num = Integer.parseInt(st.nextToken());
				position.put(num, new Pair(i, j));
			}
		}
		
		//숫자 부름
		boolean bingoFin = false;
		for (int i = 0; i < bingoSize; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			if(bingoFin) continue;
			
			for (int j = 0; j < bingoSize; j++) {
				int num = Integer.parseInt(st.nextToken());
				Pair p = position.get(num);
				erased[p.x][p.y] = true;
				//빙고 개수 확인
				if(checkBingo()) {
					bingoFin = true;
					System.out.println(i*bingoSize+j+1);
					break;
				}
			}
		}
	}
	
	static boolean checkBingo() {
		int bingoCnt = 0;
		
		//가로 & 세로
		for (int i = 0; i < bingoSize; i++) {
			int rowEraseCnt = 0;
			int colEraseCnt = 0;
			for (int j = 0; j < bingoSize; j++) {
				if(erased[i][j]) rowEraseCnt++;
				if(erased[j][i]) colEraseCnt++;
			}				
			if(rowEraseCnt == 5) bingoCnt++;
			if(colEraseCnt == 5) bingoCnt++;
		}
		
		//대각선
		int eraseCnt1 = 0; // '/'방향
		int eraseCnt2 = 0; // '\' 방향
		for (int i = 0; i < bingoSize; i++) {
			if(erased[i][bingoSize-i-1]) eraseCnt1++;
			if(erased[i][i]) eraseCnt2++;
		}

		if(eraseCnt1 == 5) bingoCnt++;
		if(eraseCnt2 == 5) bingoCnt++;

		return (bingoCnt >= 3);
	}
}

class Pair{
	int x, y;
	Pair(int x, int y){
		this.x = x;
		this.y = y;
	}
}