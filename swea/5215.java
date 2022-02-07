package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//조합
public class SW5215 {
	static int N, L, maxVal;
	static int[] calorie, score;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int testCase = Integer.parseInt(br.readLine());
		
		for (int t = 1; t <= testCase; t++) {
			String inputStr = br.readLine();
			N = Integer.parseInt(inputStr.split(" ")[0]);
			L = Integer.parseInt(inputStr.split(" ")[1]);
			
			calorie = new int[N];
			score = new int[N];
			maxVal = 0;
			
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				score[i] = Integer.parseInt(st.nextToken());
				calorie[i] = Integer.parseInt(st.nextToken());
			}
			
			comb(0, 0, 0);
			
			sb.append("#").append(t).append(" ").append(maxVal).append("\n");
		}
		
		System.out.println(sb);
	}
	
	static void comb(int idx, int calorieSum, int scoreSum) {
		if(calorieSum >= L) return;
		maxVal = Math.max(maxVal, scoreSum);
		
		for (int i = idx; i < N; i++) {
			comb(i+1, calorieSum + calorie[i], scoreSum + score[i]);
		}
	}
}
