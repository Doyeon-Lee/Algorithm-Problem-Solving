#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int tmp = 0;
    if(a == b) return a;
    else if(a > b){
        tmp = b; b = a; a = tmp;
    }
    
    for(int i = a;i <= b;i++) answer += (long long)i;
    return answer;
}