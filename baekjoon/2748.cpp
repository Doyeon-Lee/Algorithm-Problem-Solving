#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<long long> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    
    int n;
    scanf("%d", &n);
    for(int i = 2;i <= n;i++)
        fibo.push_back(fibo[i-1] + fibo[i-2]);
    printf("%lld", fibo[n]);    
}