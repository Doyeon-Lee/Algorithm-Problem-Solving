#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void travel(vector<vector<string>> &tickets, string cur, vector<bool> &visit, vector<string> &answer){
    for(int i = 0;i < tickets.size();i++){
        pair<string, string> p = make_pair(tickets[i][0], tickets[i][1]);     
        
        //현재 위치에서 출발하며 가본 적 없는 경로일 경우
        if(p.first == cur && !visit[i]){
            visit[i] = true;
            cur = p.second;
            answer.push_back(cur);
            travel(tickets, cur, visit, answer);            

            if(answer.size() < tickets.size() + 1){
                answer.pop_back();
                visit[i] = false;
                cur = p.first;
            }
        }
    } //for문 close
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer{"ICN"};
    sort(tickets.begin(), tickets.end());
    
    string cur = "ICN";
    vector<bool> visit(false, tickets.size());
    travel(tickets, cur, visit, answer);
    
    return answer;
}