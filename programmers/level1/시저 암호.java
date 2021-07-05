import java.util.*;

class Solution {
    public String solution(String s, int n) {
        String answer = "";

        for(int i = 0;i < s.length();i++){
            char c = s.charAt(i);
            if(c == ' '){answer += c; continue;}
            
            if(Character.isLowerCase(c))
                {if(c+n > 'z') c -= 26;}
            else if(c+n > 'Z') c -= 26;

            answer += Character.toString(c+n);
        }
        return answer;
    }
}