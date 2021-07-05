#include <string>
using namespace std;

void balanced(string &s, int &i){
    int n;
    s[i++] == '(' ? n = 1 : n = -1;
    while(n != 0) s[i++] == '(' ? n++ : n--; //i-1번째까지가 u, 나머지가 v
}

bool right(string &s){
    int n = 0;
    for(int i = 0;i < s.length();i++){
        if(n < 0) return false;
        if(s[i] == '(') n++;
        else n--;
    }
    return true;
}

void reverseString(string &s){ //양 옆의 괄호도 함께 지워준다
    s = s.substr(1, s.length()-2);
    for(int i = 0;i < s.length();i++)
        if(s[i] == '(') s[i] = ')';
        else s[i] = '(';
}

string makeBalancedString(string &s){
    if(s == "") return s;
    
    int i = 0;
    balanced(s, i);
    string u = s.substr(0, i);
    string v = s.substr(i); //2번
    
    if(right(u))
        return u+ makeBalancedString(v); //3번
    
    else{ //4번
        string tmp = "(";
        tmp += makeBalancedString(v) + ')';
        reverseString(u);
        return tmp += u;
    }   
}

string solution(string p) {
    string answer = "";
    string tmp = "";
    answer = makeBalancedString(p);
    return answer;
}