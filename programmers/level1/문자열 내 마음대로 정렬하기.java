import java.util.*;

class Solution {
    int N;
    class sString implements Comparable<sString>{
        public String str;

        public sString(String str){
            this.str = str;
        }

        public int compareTo(sString o){
            if(str.charAt(N) < o.str.charAt(N)) return -1;
            else if(str.charAt(N) > o.str.charAt(N)) return 1;
            else return str.compareTo(o.str); //같을 경우 사전순으로
        }
    }
    
    public String[] solution(String[] strings, int n) {
        List<sString> sortString = new ArrayList<>();
        N = n;
        
        for(int i = 0;i < strings.length;i++)
            sortString.add(new sString(strings[i]));
        
        Collections.sort(sortString);

        String[] answer = new String[sortString.size()];
        int i = 0;
        for(Iterator<sString> iter = sortString.iterator();iter.hasNext();){
            answer[i] = iter.next().str;
            i++;
        }
        
        return answer;
    }
}