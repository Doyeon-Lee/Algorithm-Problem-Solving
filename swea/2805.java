package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SW2805 {
	static int testCase;
	static StringBuilder sb = new StringBuilder();
	static char[][] farm;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(br.readLine());
		
		for (int t = 1; t <= testCase; t++) {
			int N = Integer.parseInt(br.readLine());
			farm = new char[N][N];
			int sum = 0;
			
			//농장 입력
			for (int i = 0; i < N; i++) 
				farm[i] = br.readLine().toCharArray();

			//수확물 계산
			int left = N/2;
			int right = N/2;
			for (int i = 0; i < N/2; i++) {
				for (int j = left; j <= right; j++) {
					sum += (farm[i][j] - '0');
				}
				left--; right++;
			}
			
			for (int i = N/2; i < N; i++) {
				for (int j = left; j <= right; j++) {
					sum += (farm[i][j] - '0');
				}
				left++; right--;
			}
			
			sb.append("#").append(t).append(" ").append(sum).append("\n");
		}
		System.out.println(sb);
		
	}
}
