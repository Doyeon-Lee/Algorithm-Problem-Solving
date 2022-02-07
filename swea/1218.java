package com.ssafy;

import java.io.*;
import java.util.Stack;

public class SW1218 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Stack<Character> st;
		int testCase = 10;
		
		for (int t = 1; t <= testCase; t++) {
			st = new Stack<>();
			int N = Integer.parseInt(br.readLine());
			char[] brackets = br.readLine().toCharArray();
			int flag = 1;
			
			for (char c : brackets) {
				if(c == '(' || c == '{' || c == '[' || c == '<') st.push(c);
				
				else { //닫는 괄호
					if(st.isEmpty()) {
						flag = 0;
						break;
					}
					char c2 = st.pop();					
					if(!(c2 == '(' && c == ')') && !(c2 == '{' && c == '}') && 
					   !(c2 == '[' && c == ']') && !(c2 == '<' && c == '>')){
						flag = 0;
						break;
					}
				}
			}
			if(!st.isEmpty()) flag = 0;
			
			sb.append("#").append(t).append(" ").append(flag).append("\n");
		}
		System.out.println(sb);
	}
}
