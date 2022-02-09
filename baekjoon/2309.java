package im;

import java.io.*;
import java.util.*;

public class BJ2309 {
	static int dwarfCnt = 9;
	static int[] height;

	static ArrayList<Integer> sevenHeight = new ArrayList<>();
	static int sum = 0;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		height = new int[dwarfCnt];

		for (int i = 0; i < dwarfCnt; i++)
			height[i] = Integer.parseInt(br.readLine());

		dfs(-1);
		Collections.sort(sevenHeight);
		for (int h : sevenHeight)
			System.out.println(h);
	}

	static boolean dfs(int idx) {		
		if (sevenHeight.size() == 7) 
			return (sum == 100);
				
		for (int i = idx+1; i < dwarfCnt; i++) {
			//i번째 난쟁이 포함
			sum += height[i];
			sevenHeight.add(height[i]);
			if(dfs(i)) return true;
		
			//i번째 난쟁이 미포함
			sum -= height[i];
			sevenHeight.remove(sevenHeight.size()-1);
			if(dfs(i)) return true;
		}
		
		return false;
	}
}
