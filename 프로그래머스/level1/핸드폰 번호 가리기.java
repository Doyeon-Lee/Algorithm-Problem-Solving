class Solution {
    public String solution(String phone_number) {
        String answer = "";
        int indx = phone_number.length()-4;
        
        for(int i = 0;i < indx;i++)
            answer += '*';
        answer += phone_number.substring(indx);
            
        return answer;
    }
}