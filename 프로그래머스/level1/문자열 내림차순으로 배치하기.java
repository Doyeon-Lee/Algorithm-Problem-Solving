import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        List<Character> l = new ArrayList<Character>();
        
        for(int i = 0;i < s.length();i++)
            l.add(s.charAt(i));
        
        Collections.sort(l);
        for(int i = s.length()-1;i >= 0;i--)
            answer += l.get(i);
        return answer;
    }
}