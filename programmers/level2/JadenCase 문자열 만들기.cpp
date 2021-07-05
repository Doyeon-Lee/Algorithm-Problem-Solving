#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool blank = 1; //처음 문자인가?
    
    for(int i = 0;i < s.length();i++){
        if(isblank(s[i])) {
            blank = 1;
            answer += s[i];
            continue;
        }
        
        if(blank == 1){ //처음 나오는 문자이면
            blank = 0;
            if(isalpha(s[i])){
                answer += toupper(s[i]);
                continue;}
        }
        answer += tolower(s[i]);
    }
    
    return answer;
}