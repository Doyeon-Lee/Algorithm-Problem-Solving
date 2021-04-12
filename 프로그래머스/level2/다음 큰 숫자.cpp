#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int oneCount(int n){
    int res = 0;
    while(n != 0){
        if(n%2 == 1) res++;
        n /= 2;
    }
    return res;
}

int solution(int n) {
    int num = oneCount(n++);
    while(1){
        if(oneCount(n) == num) break;
        n++;
    }
    return n;
    
/*
    int answer = 0;
    int one = 0; int zero = 0;
    int i = 0; int l = 0;
    int pos = -1; //01이 나오는 0의 위치
    string bi = "";
    
    while(n!=0){
        bi = to_string(n%2) + bi;
        n /= 2;
    }

    l = bi.length();
    for(i = l-1;i > 0;i--){
        if(bi[i] == '1' && bi[i-1] == '0'){
            bi[i] = '0';
            bi[i-1] = '1';
            pos = i+1;
            break;
        }
    }

    if(pos == -1){
        sort(bi.begin(), bi.end());
        bi = "10" + bi;
        bi = bi.substr(0, l+1);
    }
    else sort(bi.begin()+pos, bi.end());
    
    l = bi.length();
    for(i = l;i >= 0;i--)
        if(bi[i] == '1')
            answer += pow(2,l-i-1);
    return answer;
    */
}