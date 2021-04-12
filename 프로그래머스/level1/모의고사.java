import java.util.*;

class Solution {   
    public int[] solution(int[] answers) {
        int[] answer = {};
        int[] a = {1, 2, 3, 4, 5};
        int[] b = {2, 1, 2, 3, 2, 4, 2 ,5};
        int[] c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int one = 0; int two = 0; int three = 0;
        
        for(int i = 0;i < answers.length;i++){
            if(a[i%5] == answers[i]) one++;
            if(b[i%8] == answers[i]) two++;
            if(c[i%10] == answers[i]) three++;
        }
        
        int res = Math.max(one, Math.max(two, three));
        int s = answer.length;

        if(res == one){
            s++;
            answer = Arrays.copyOf(answer, s);
            answer[s-1] = 1;
        }
        if(res == two){
            s++;
            answer = Arrays.copyOf(answer, s);
            answer[s-1] = 2;
        }
        if(res == three){
            s++;
            answer = Arrays.copyOf(answer, s);
            answer[s-1] = 3;
        }
        
        
        return answer;
    }
}