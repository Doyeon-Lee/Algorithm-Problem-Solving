import java.util.*;

class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        String kim = "Kim";
        int pos = 0;
        
        for(String s : seoul){
            if(s.equals(kim)) break;
            pos++;
        }
        answer = "김서방은 " + pos + "에 있다";
        return answer;
    }
}