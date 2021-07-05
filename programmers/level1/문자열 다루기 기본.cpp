#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    int len = s.length();
    if(len != 4 && len != 6) return false;
    
    for(int i = 0;i < s.length();i++)
        if(s.at(i) - '0' > 10 || s.at(i) < 0) return false;
    return true;
}