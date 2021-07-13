#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//먼저 에라토스테네스의 체로 홀수인 소수를 모두 구한 후, 
//n = a + b라고 할 때, a가 소수이면 b도 소수인지를 본다.
#define SIZE 1000001

void get_prime(bool *prime){
    int idx = 2;

    while(idx < 1000001){
        while(!prime[idx] && idx < 1000001) idx++;

        for(int i = idx;i < SIZE;i += idx)
            prime[i] = false;
        if(idx != 2) prime[idx] = true;
            
        idx++;
    }
}

void solve(int val, bool *prime){
    int s = SIZE/2;
    for(int i = 0;i < s;i++){
        if(!prime[i]) continue;
        
        int tmp = val - i;
        if(prime[tmp]){
            printf("%d = %d + %d\n", val, i, tmp);
            return;
        }
    }
    printf("Goldbach's conjecture is wrong.\n");
}

int main(){
    bool prime[SIZE];
    memset(prime, true, sizeof(prime));
    get_prime(prime);
    prime[0] = prime[1] = false;

    int val;
    while(scanf("%d", &val) != EOF){
        if(val == 0) break;
        solve(val, prime);
    }
}