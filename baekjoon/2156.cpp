#include <iostream>
using namespace std;
#define MAX 10001

int main(){
    int n;
    int wine[MAX];
    int dp[MAX]; //i까지의 계단에 오기까지 최대값
    scanf("%d", &n);

    for(int i = 1;i <= n;i++)
        scanf("%d", &wine[i]);

    //초기값
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = max(wine[1]+wine[3], wine[2]+wine[3]);

    //dp 계산
    for(int i = 4;i <= n;i++){
        dp[i] = max(dp[i-2]+wine[i], dp[i-3]+wine[i-1]+wine[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }

    printf("%d", dp[n]);
}