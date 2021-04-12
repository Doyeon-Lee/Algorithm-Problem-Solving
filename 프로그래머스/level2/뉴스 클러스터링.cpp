#include <string>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define MULNUM 65536;

void cutString(map<string, int> &m, string &str){
    for(int i = 0;i < str.length()-1;i++){
        if(isalpha(str[i]) && isalpha(str[i+1]))
            m[str.substr(i, 2)]++;
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    //전부 소문자로 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    map<string, int> m1;
    map<string, int> m2;
    
    cutString(m1, str1);
    cutString(m2, str2);
    int same = 0; int diff = 0;
    
    for(auto iter = m1.begin();iter != m1.end();iter++){
        string tmp = iter->first;
        int a = m1[tmp]; int b = m2[tmp];
        
        same += min(a, b);
        a >= b ? diff+= a-b : diff+= b-a;
        m2.erase(tmp);
    }
    
    for(auto iter = m2.begin();iter != m2.end();iter++)
        diff += iter->second;
    
   if(same + diff == 0) return MULNUM;
    answer = (double)same / (same + diff) * MULNUM;
    return answer;
}