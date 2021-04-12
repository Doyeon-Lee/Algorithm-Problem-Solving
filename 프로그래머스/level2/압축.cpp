#include <string>
#include <vector>
#include <map>
using namespace std;
#define ALPHANUM 26

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    
    char c = 'A';
    int n = 1;
    string tmp = "";
    for(;n <= ALPHANUM;n++){
        tmp = c++;
        m[tmp] = n;
    } //n = 27인 상태

    int i = 0;
    while(1){
        int j = 1;
        do{
            tmp = msg.substr(i, ++j);
            if(i+j-1 == msg.length()){
                answer.push_back(m[tmp]);
                return answer;
            }
        }while(m[tmp]);

        answer.push_back(m[tmp.substr(0, tmp.length()-1)]);
        m[tmp] = n++;
        i += (--j);
    }
}