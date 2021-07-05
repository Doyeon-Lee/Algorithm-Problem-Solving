#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    string tmp = words[0];
    map<string, bool> m;
    int count = 1;
    char c = tmp[tmp.size()-1];
    m[tmp] = 1;
    
    for(int i = 1;i < words.size();i++){
        tmp = words[i];

        //이미 나온 단어거나 알파벳이 다를 경우
        if(tmp[0] != c || m[tmp] == 1){
            answer.push_back(count%n+1);
            answer.push_back(count/n+1);
            return answer;
        }
        else{
            m[tmp] = 1;
            c = tmp[tmp.size()-1];
            count++;
        }
    }

    answer.push_back(0);
    answer.push_back(0);    
    return answer;
}