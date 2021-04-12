#include <string>
#include <algorithm>
using namespace std;

string solution(string s) {
    /*
    string answer = "";
    string tmp = "";
    for(int i = 0;i < s.length();i++){
        if(islower(s[i])) answer += s[i];
        else tmp += s[i];
    }
    sort(answer.begin(), answer.end());
    sort(tmp.begin(), tmp.end());    
    reverse(answer.begin(), answer.end());
    reverse(tmp.begin(),tmp.end());
    answer = answer + tmp;   
    return answer;
    */
    
    sort(s.rbegin(), s.rend());
    return s;
}