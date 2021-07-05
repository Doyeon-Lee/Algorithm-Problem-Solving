#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> cStack;
    cStack.push(s[0]);
    
    for(int i = 1;i < s.length();i++){
        if(!cStack.empty() && cStack.top() == s[i]) cStack.pop();
        else cStack.push(s[i]);
    }
    
    if(cStack.empty()) return true;
    else return false;
}