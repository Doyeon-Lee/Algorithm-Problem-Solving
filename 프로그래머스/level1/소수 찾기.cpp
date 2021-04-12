#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    bool *prime = new bool[n+1];
    fill(prime, prime+n+1, 1);
    
    for(int i = 2;i <= n;i++){
        if(prime[i] == 0) continue;
        for(int j = i*2;j <= n;j += i)
            prime[j] = 0;
    }
    
    answer = count(prime, prime+n+1, true) - 2; //0과 1은 제외한다
    return answer;
}