package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class SW1208 {
	static int testCase = 10;
	static int boxCnt = 100;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for (int t = 1; t <= testCase; t++) {
			int dumpCnt = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			PriorityQueue<Integer> maxQ = new PriorityQueue<>(Collections.reverseOrder());
			PriorityQueue<Integer> minQ = new PriorityQueue<>();
			int maxNum = 0; int minNum = 0;
			
			//박스 입력
			for (int i = 0; i < boxCnt; i++) {
				int val = Integer.parseInt(st.nextToken());
				maxQ.add(val); minQ.add(val);
			}
			
			int subVal = 0;
			int i = 0;
			for (; i < dumpCnt; i++) {
				maxNum = maxQ.peek(); minNum = minQ.peek(); 
				maxQ.remove(maxNum); maxQ.remove(minNum);
				minQ.remove(maxNum); minQ.remove(minNum);
				
				if(Math.abs(maxNum - minNum) <= 1) {
					subVal = maxNum - minNum;
					break;
				}
				maxNum--; minNum++;
				maxQ.add(maxNum); maxQ.add(minNum);
				minQ.add(maxNum); minQ.add(minNum);			
			}
			
			if(i == dumpCnt) subVal = maxQ.peek() - minQ.peek();
			sb.append("#").append(t).append(" ").append(subVal).append("\n");
		}
		System.out.println(sb);
	}
}
