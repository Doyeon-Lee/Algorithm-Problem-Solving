import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        int l = s.length();
        if(l % 2 == 0) //짝수라면
            answer = s.substring(l/2-1, l/2+1);
        else //홀수면
            answer = s.substring(l/2, l/2+1);
        
        return answerㅁ;
    }
}