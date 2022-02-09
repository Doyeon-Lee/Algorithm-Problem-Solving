package im;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BJ2605 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		ArrayList<Integer> arr = new ArrayList<>();
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int j = 0; j < arr.size(); j++) {
			System.out.print(arr.get(j) + " ");
		}

		for (int i = 1; i <= N; i++) {
			int num = Integer.parseInt(st.nextToken());
			if (num == 0)
				arr.add(i);
			else
				arr.add(arr.size() - num, i);
		}
		for (int j = 0; j < arr.size(); j++) {
			System.out.print(arr.get(j) + " ");
		}
	}
}
