class Solution {
    public String solution(int n) {
        String answer = "";
        int twice = n/2;
        for(int i = 0;i < twice;i++)
            answer = answer + "수박";
        
        if(n%2 == 1)
            answer = answer + "수";
        
        return answer;
    }
}