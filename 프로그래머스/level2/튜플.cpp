#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

bool cmp(string &a, string &b){
    return a.length() < b.length();
}

void covNum(string &str, set<int> &s, vector<int> &answer){
    int n = 0;
    
    for(int i = 0;i < str.length();i++){
        if(str[i] == ','){
            if(s.find(n) == s.end()) break;
            else n = 0;
        }
        else n = n * 10 + (str[i] - '0');
    }
    if(n != 0){
        answer.push_back(n);
        s.insert(n);
    }
}

vector<int> solution(string str) {
    vector<int> answer;
    vector<string> v;
    string tmp = "";
    int l = 0;
    
    for(int i = 1;i < str.length()-1;i++){
        if(str[i] == '{') l = 0;
        else if(str[i] == '}'){
            tmp = str.substr(i-l, l);
            v.push_back(tmp);
        }
        else l++; //숫자나 ','일 경우
    }
    
    sort(v.begin(), v.end(), cmp);
    set<int> s;
    
    for(int i = 0;i < v.size();i++)
        covNum(v[i], s, answer);   
    
    
    return answer;
}