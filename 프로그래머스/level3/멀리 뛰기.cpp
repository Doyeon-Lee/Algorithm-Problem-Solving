//1칸, 2칸, 3칸... 을 이동가능한 갯수는 1, 2, 3, 5, 8, 13, ...
//a(n) = a(n-1) + a(n-2)이다
#include <string>
#include <vector>
using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long a = 1;
    long long b = 2;
    
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    for(int i = 3;i <= n;i++){
        answer = (a + b) % 1234567;
        a = b;
        b = answer;
    }
    
    return answer;
}