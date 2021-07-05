#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<bool> bracket;
    
    for(int i = 0;i < s.length();i++){
        if(s[i] == '(') bracket.push(1); //'('이면 1을 넣는다
        else{ // ')'이면
            if(bracket.empty()) return false;
            if(bracket.top() == 1) bracket.pop();
            else return false;
        }
    }

    if(bracket.empty()) return true;
    else return false;
}