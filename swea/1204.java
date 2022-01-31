import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
	public static int studentNum = 1000;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int testCase = sc.nextInt();
		for (int i = 0; i < testCase; i++) {
			Map<Integer, Integer> numberCnt = new HashMap<>();
			int t = sc.nextInt();
			int maxCnt = 0;
			int maxVal = 0;
			
			for (int j = 0; j < studentNum; j++) {
				int inputVal = sc.nextInt();
				int curCnt = 1;
				if(numberCnt.containsKey(inputVal))
					curCnt += numberCnt.get(inputVal);
				numberCnt.put(inputVal, curCnt);

				//횟수가 더 많거나, 같다면 더 큰 수를 저장
				if (maxCnt < curCnt || (maxCnt == curCnt) && (maxVal < inputVal)) {
					maxCnt = curCnt;
					maxVal = inputVal;
				}
			}
			
			System.out.printf("#%d %d\n", t, maxVal);
		}
	}
}