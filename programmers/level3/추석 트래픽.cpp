#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

//시간을 숫자로 변환하는 과정에서, hh:mm:ss.sss의 숫자는 double에 담기 어려움
//각각 따로 분리하여 ms로 변환하면 int로도 가능하더라 (int범위 2,147,483,647)

void calTime(vector<string> &lines, vector<int> &in, vector<int> &out){
    string S, T;
    int hh, mm, start, end;
    float ss, t;
    string str = ""; //현재 line
    
    int s = lines.size();
    
    for(int i = 0;i < s;i++){
        str = lines[i];
        //시, 분, 초 각각 분리
        S = str.substr(11, 12);
        T = str.substr(24);
        
        hh = stoi(S.substr(0, 2)) * 3600 * 1000;
        mm = stoi(S.substr(3, 2)) * 60 * 1000;
        ss = stof(S.substr(6)) * 1000;
        
        //맨뒤의 s제거
        T.erase(--T.end());
        t = stof(T);
        
        //시작, 끝 시간 계산
        //end = (hh * 3600 * 1000) + (mm * 60 * 1000) + (int)(ss * 1000);
        end = hh + mm + ss;
        t = (int)(t * 1000);
        start = end - t + 1;

        //큐에 저장
        in.push_back(start);
        out.push_back(end);
    }
}

int solution(vector<string> lines) {
    int answer = 0;
    
    string cur, next;
    int num = 0; int max = 0;
    vector<int> in, out;
    
    calTime(lines, in, out); //시작, 끝 시간을 큐에 저장한다
    int s = in.size();
    
    for(int i = 0;i < s;i++){
        int end_time = out[i] + 1000;
        int cnt = 0;
        
        //트래픽이 끝나는 시간~(+1초) 사이의 갯수를 세면 된다!
        for(int j = i;j < s;j++){
            if(in[j] < end_time) cnt++;
            //else break;
        }
        
        answer = answer < cnt ? cnt : answer;
    }
    
    /*
    for(int i = 0;i <s;i++)
        cout << in[i] << " " << out[i] << endl;
    */

    
    return answer;
}