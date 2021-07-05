#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    string tok = ""; //반복되는지 비교할 기준 문자열
    int begin = 0; //기준 문자열의 시작 위치
    int count = 0; //반복되는 횟수
    int len = 0; //각 반복마다 나오는 압축문자열의 길이
    int min = 0; //최소 길이

    if(s.length() == 1) //길이가 1이면
        return 1;
    
    for(int i = 1;i <= (s.length()/2);i++){ //i는 스트링을 자르는 문자의 개수
        begin = 0; count = 1; len = 0;

        while(begin + 2*i <= s.length()){ //인풋 스트링의 길이만큼
            tok = s.substr(begin, i); //begin에서부터 i개의 문자열을 저장
            
            if(tok == s.substr(begin+i, i)){
                if(count == 1) len += 1 + i; //숫자와 반복되는 문자의 개수를 더한다
                if(count == 9 || count == 99 || count == 999) len++;
                count++;
            }
            else{
                if(count == 1) len += i; 
                count = 1;
            }
            
            begin += i; //다음 문자열의 위치로 이동
        } //while문 close
        if(count == 1) len += i;
        len += s.length() % i;        
        
        if(min == 0) min = len;
        if(min > len) min = len;
    } //for문 close
    return min;
}