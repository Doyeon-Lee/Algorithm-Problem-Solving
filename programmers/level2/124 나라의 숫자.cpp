#include <string>
#include <stack>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    stack<int> stack;
    int mod = 0;
    
    while(1){
        mod = n % 3;
        switch(mod){
        case(0):
            stack.push(4);
            n--;
            break;
        case(1):
            stack.push(1);
            break;
        case(2):
            stack.push(2);
            break;
        default:
            break;
        } //switch문 close
    
        n /= 3;
        if(n == 0) break;
    }
    
    while(!stack.empty()){
        answer += to_string(stack.top());
        stack.pop();
    }
    
    string aa = "aa";
    cout << std::stoi(aa);
    
    return answer;
}