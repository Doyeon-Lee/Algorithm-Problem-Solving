class Solution {
    public int solution(String s) {
        int answer = 0;
        int i = 0;
        if(!Character.isDigit(s.charAt(0))) i = 1;
        
        for(;i < s.length();i++)
            answer = answer * 10 + s.charAt(i) - '0';
        if(s.charAt(0) == '-') answer *= -1;
        return answer;
    }
}