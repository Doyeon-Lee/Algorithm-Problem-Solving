#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string buf = ""; //record를 하나씩 저장하는 버퍼
    string inout = ""; //Enter, Leave, Change 저장
    string id = ""; //id저장
    string name = ""; //닉네임 저장
    
    map<string, string> m;
    
    for(int i = 0;i < record.size();i++){
        buf = record[i];
        stringstream ss(buf);
        ss >> inout; ss >> id; ss >> name;
        
        if(inout == "Enter"){   
            buf = "e" + id; 
            answer.push_back(buf);
            m[id] = name;
        } //Enter의 경우
        else if(inout == "Leave"){
            buf = "l" + id;
            answer.push_back(buf);
        } //Leave의 경우
        else m[id] = name; //Change의 경우
        
    } //record만큼 반복    
    
    for(int i = 0;i < answer.size();i++){
        inout = answer[i].at(0); //e인지 l인지 판단
        id = answer[i].substr(1); //e혹은 l 다음부터의 문자열(id)  
        
        if(inout == "e")
            answer[i] = m[id] + "님이 들어왔습니다.";
        else //l이면
            answer[i] = m[id] + "님이 나갔습니다.";
    }
    return answer;
}