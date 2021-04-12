import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = new int[arr.length];
        answer[0] = arr[0];
        int pos = 0;     

        for(int i = 1;i < arr.length;i++){
            if(arr[i] != answer[pos]) answer[++pos] = arr[i];
        }

        answer = Arrays.copyOfRange(answer, 0, ++pos);
        return answer;
    }
}