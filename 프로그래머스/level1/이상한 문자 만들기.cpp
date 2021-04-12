#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int w = 0; //word시작인가?
    for(int i = 0;i < s.length();i++){
        if(s[i] == ' '){
            w = -1;
            answer += " ";
        }
        else if(w%2 == 0) answer += toupper(s[i]);
        else answer += tolower(s[i]);
        w++;
    }
    
    return answer;
}