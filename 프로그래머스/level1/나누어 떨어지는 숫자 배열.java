import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        List<Integer> intList = new ArrayList<Integer>();
        
        for(int i = 0;i < arr.length;i++)
            if(arr[i] % divisor == 0) intList.add(arr[i]);

        if(intList.size() == 0){
            int[] answer = new int[1];
            answer[0] = -1;
            return answer;
        }
        
        Collections.sort(intList);
        
        int[] answer = new int[intList.size()];
        for(int i = 0;i < intList.size();i++)
            answer[i] = intList.get(i);
        
        return answer;
    }
}