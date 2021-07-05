#include <string>
#include <vector>
#include <iostream>
using namespace std;

string getNum(int num, int n){
    string s = "";
    int mod = 0;
    
    while(1){
        mod = num % n;
        if(mod >= 10){
            char c = 'A' + (mod - 10);
            s = c + s;
        }
        else s = to_string(mod) + s;
        num = num / n;
        
        if(num == 0) break;
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "0";

    int l = (t-1) * m + p;
    int num = 1;
    
    while(tmp.length() < l)
        tmp += getNum(num++, n);
    
    int pos = p-1;
    for(int i = 0;i < t;i++){
        answer += tmp[pos];
        pos += m;
    }
    return answer;
}