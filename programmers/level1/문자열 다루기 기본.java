import java.util.*;

class Solution {
    public boolean solution(String s) {
        int l = s.length();
        if(l != 4 && l != 6) return false;
        
        for(int i = 0;i < l;i++)
            if(!Character.isDigit(s.charAt(i))) return false;
    
        return true;
    }
}