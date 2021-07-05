#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//분으로 환산
int StringtoMin(string str){
    int res = (str[0]-'0') * 10 + (str[1]-'0');
    res *= 60;
    
    res += (str[3]-'0') * 10 + (str[4]-'0');
    return res;
}

string MintoString(int time){
    int h = time / 60;
    int m = time % 60;
    
    string hs = to_string(h);
    string ms = to_string(m);
    if(hs.length() == 1) hs = "0" + hs;
    if(ms.length() == 1) ms = "0" + ms;
    
    return hs + ":" + ms;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int s = timetable.size(); 
    vector<int> time;
    
    for(int i = 0;i < s;i++)
        time.push_back(StringtoMin(timetable[i])); 
    sort(time.begin(), time.end());
    
    int bus = StringtoMin("09:00"); //shuttle
    int people = 0; //대기하는 크루수
    int idx = 0; //timetable의 idx
    int tmp = time[0];
    
    //버스 기준으로 본다
    for(int i = 0;i < n;i++){
        people = 0;
        answer = MintoString(bus);  
        
        for(int j = idx;j < s;j++){
            if(time[j] <= bus){
                people++;
                idx++;
                if(people == m) {
                    answer = MintoString(time[idx-1]-1);
                    break;
                }
            }
            else break;
        }
        
        /* 이거 진짜 왜안됨????????? 위에거랑 뭐가 달라!!!
        while(tmp <= bus && idx < s){
            people++;
            idx++;
            
            if(people == m){
                answer = MintoString(tmp-1);
                break;
            }
            tmp = time[idx];
        }
        */
        bus += t;
    }
    return answer;
}