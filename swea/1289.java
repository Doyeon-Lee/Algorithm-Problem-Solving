import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
	public static int getCnt(String str) {
		char preNum = '0';
		int cnt = 0;
		
		for (int i = 0; i < str.length(); i++) {
			if(str.charAt(i) != preNum) {
				cnt++;
				preNum = str.charAt(i);
			}
		}
	
		return cnt;
	}
	
	public static void main(String args[]) throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
	
		for(int test_case = 1; test_case <= T; test_case++)
		{
			String inputStr = br.readLine();
			System.out.printf("#%d %d\n", test_case, getCnt(inputStr));
		}
	}
}	