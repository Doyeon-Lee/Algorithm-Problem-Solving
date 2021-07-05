#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> buf;
    for(int i = 0;i < clothes.size();i++)
        buf[clothes[i][1]]++;

    answer = buf.begin() -> second + 1;
    for(auto i = ++buf.begin(); i != buf.end(); i++){
        answer *= (i -> second + 1);
    }
    return --answer;
    
/*
    int answer = 0, num = 1;
    vector<int> cases;
    vector<string> buf;
    vector<vector<string>> clothes2;
    
    for(int i = 0;i < clothes.size();i++){
        string tmp = clothes[i].back();
        buf.push_back(tmp);
        buf.push_back(clothes[i].front());
        clothes2.push_back(buf);
        buf.clear();  
    }
    
    sort(clothes2.begin(), clothes2.end());

    for(int i = 0;i < clothes2.size() - 1;i++){
        if(clothes2[i].front() == clothes2[i+1].front())
            num++;
        else{
            cases.push_back(num+1);
            num = 1;
        }
    }
    cases.push_back(num+1);
    
    answer = cases[0];
    for(int i = 1;i < cases.size();i++)
        answer = answer * cases[i];

    return answer - 1;
*/
}