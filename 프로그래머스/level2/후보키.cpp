#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

void pushComb(vector<string> &v, vector<bool> &b){
    do{
        string tmp = "";
        for(int i = 0;i < b.size();i++)
            if(b[i]) tmp += to_string(i);
        v.push_back(tmp);
    }while(next_permutation(b.begin(), b.end()));
}

bool checkMap(vector<vector<string>> &v, string &str){
    map<string, int> m;
    
    for(int i = 0;i < v.size();i++){
        string tmp = "";
        for(int j = 0;j < str.length();j++)
            tmp = tmp + v[i][str[j]-'0'] + " ";
        if(m[tmp]) return false;
        else m[tmp]++;
    }
    return true;
}

void eraseComb(vector<string> &comb, string &str){
    auto it = comb.begin();
    
    while(it != comb.end()){
        if(*it == str){it++; continue;}
        string tmp = *it;
        int i = 0;
        
        while(i < str.length()){
            if(tmp.find(str[i]) == string::npos) break;
            else i++;
        }
        if(i == str.length()) comb.erase(it);
        else it++;
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<string> comb;
    int s = relation[0].size();
    vector<bool> b(s);
    
    //nCr에서 r이 1~n의 경우를 구한다
    for(int i = s-1;i >= 0;i--){
        b[i] = 1;
        pushComb(comb, b);    
    }
    
    auto iter = comb.begin();
    while(iter != comb.end()){
        if(checkMap(relation, *iter)){
            eraseComb(comb, *iter);
            iter++;
        }
        else comb.erase(iter);
    }

    
    answer = comb.size();
    return answer;
}