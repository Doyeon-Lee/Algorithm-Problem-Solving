#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score = 0;
    int bfscore = 0;
    int pos = 0;
    string buf = "";
    
    for(int i = 0;i < 3;i++){
        buf = dartResult.substr(pos, 2);
        if(buf == "10"){
            score += 10;
            pos += 2;}
        else{
            buf = dartResult.substr(pos, 1);
            score = buf.at(0) - '0';
            pos++;
        }//점수를 먼저 파악한다
        
        buf = dartResult.substr(pos, 1);
        if(buf == "D") score = pow(score, 2);
        else if(buf == "T") score = pow(score, 3);
        pos++;
        //보너스 한 글자 확인 Single의 경우 1제곱이므로 넘어간다
        answer += score;
        
        buf = dartResult.substr(pos, 1);
        if(buf == "*"){
            answer = answer + score + bfscore;
            score *= 2;
            pos++;}
        else if(buf == "#"){
            score *= (-1);
            answer += score * 2;
            pos++;}
        //옵션 계산, *또는 #일 때만 pos를 이동해 준다
        bfscore = score;
        score = 0;
    } //다트 3번 for문 close

    return answer;
}