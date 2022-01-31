import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, m;
		int maxVal = 0;
		
		n = sc.nextInt(); m = sc.nextInt();
		Integer[] cards = new Integer[n]; //int로 하면 sort 빨간줄
		//입력값 저장
		for(int i = 0;i < n;i++)
			cards[i] = sc.nextInt();
		
		//큰 수부터 탐색 위해 정렬
		Arrays.sort(cards, Collections.reverseOrder());
		int arrLength = cards.length;
		
		//브루트포스
		for (int i = 0; i < arrLength; i++) {
			int sum = 0;
			if(cards[i] >= m) continue;
			sum += cards[i];
			
			for (int j = i+1; j < arrLength; j++) {
				sum += cards[j];
				if(sum >= m) {
					sum -= cards[j];
					continue;
				}
				for (int k = j+1; k < arrLength; k++) {
					if(sum + cards[k] <= m) {
						maxVal = Math.max(maxVal, sum + cards[k]);
						break; //뒤는 더 작은 수라 볼 필요 없음
					}
				}
				sum -= cards[j];
			}
		}
		
		sc.close();
		System.out.println(maxVal);
	}
}