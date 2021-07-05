#include <iostream>
using namespace std;

int next_round(int n){
    if(n % 2 == 0) return n/2;
    else return n/2+1;
}
    
int solution(int n, int a, int b){
    int answer = 0;
    int tmp = 0;
    if(a > b){
        tmp = b; b = a; a = tmp;
    } //swap
           
    while(1){
        if(b == a + 1 && b % 2 == 0) break;
        answer++;
        a = next_round(a);
        b = next_round(b);
    }
    
    return ++answer;
}