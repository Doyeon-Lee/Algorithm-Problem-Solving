class Solution {
    boolean solution(String s) {        
        boolean answer = true;
        int pcount = 0;
        int ycount = 0;

        char []arr = s.toCharArray();
        
        for(char c : arr){
            if(c == 'P' || c == 'p') pcount++;
            else if(c == 'Y' || c == 'y') ycount++;
        }
        
        if(pcount != ycount) answer = false;
        return answer;
    }
}