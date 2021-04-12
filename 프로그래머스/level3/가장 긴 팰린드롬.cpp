#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int solution(string s){
    int answer = 1;
    int l = s.length();

    bool **arr = new bool*[l];
    for(int i = 0;i < l;i++){
        arr[i] = new bool[l];
        memset(arr[i], 0, l);
    }
 
    //arr[i][i] = 1, arr[i][i+1] = 1
    for(int i = 0;i < l;i++){
        if(s[i] ==s [i+1]) arr[i][i+1] = true;
        arr[i][i] = true;
    }
    
    for(int i = l-1;i >= 0;i--){
        for(int j = l-1;j > i;j--){
            if(arr[i+1][j-1] == true && s[i] == s[j]) arr[i][j] = true;
        }
    }   

    for(int i = 0;i < l;i++){
        for(int j = l-1;j >= i;j--){
            if(arr[i][j]){
                answer = max(answer, j-i+1);
                break;
            }
        }
    } 
    
    return answer;
}