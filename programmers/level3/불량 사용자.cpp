#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

//불량 사용자 아이디에 해당하는 인덱스를 이차원 벡터에 저장하여
//모든 경우의 수를 탐색한 후, 정렬해서 겹치는 경우를 제외한다
int BS, US; //Banned Size, User Size

bool matchID(string b, string u){
    int bs = b.length();
    int us = u.length();
    if(bs != us) return false;
    
    for(int i = 0;i < bs;i++){
        if(b[i] == '*') continue;
        if(b[i] != u[i]) return false;
    }
    
    return true;
}

string GetUsed(vector<bool> &used){
    string str;
    
    for(int i = 0;i < US;i++)
        if(used[i]) str += to_string(i);
    return str;
}

void dfs(int idx, vector<bool> &used, set<string> &sset, vector<string> &u, vector<string> &b){
    if(idx == BS){
        string str = GetUsed(used);
        sset.insert(str);
        return;
    }
    else{
        int s = u.size();
        for(int i = 0;i < s;i++){
            if(!used[i] && matchID(b[idx], u[i])){
                //새로운놈이고 조건에 맞는다면
                used[i] = true;
                dfs(idx+1, used, sset, u, b);
                used[i] = false;
            }
        } //for문
    } //else문 
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;    
    BS = banned_id.size();
    US = user_id.size();
    
    vector<vector<int>> v;
    vector<bool> used(US);
    set<string> sset;

    for(int i = 0;i < BS;i++){
        used.clear();
        dfs(0, used, sset, user_id, banned_id);
    }
    
    answer = sset.size();

    return answer;
}