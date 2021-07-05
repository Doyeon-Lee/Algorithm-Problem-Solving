#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    int tmp = 0; int un = 0;
    char c;
    
    for(int i = 0;i < s.length();i++){
        c = s[i];
        if(isspace(c)){
            if(un == 1) tmp *= -1;
            v.push_back(tmp); un = tmp = 0;
            continue;
        }
        if(isdigit(c)) tmp = tmp * 10 + c-'0';
        else un = 1;
    }
    if(un == 1) tmp *= -1;
    v.push_back(tmp); //마지막 숫자
    
    sort(v.begin(), v.end());
    auto iter = v.begin();
    answer = to_string(*iter) + " ";
    iter = v.end() -1 ;
    answer += to_string(*iter);
   
    return answer;
}