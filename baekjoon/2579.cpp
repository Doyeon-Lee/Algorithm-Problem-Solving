#include <iostream>
using namespace std;
#define MAX 301

int main(){
    int n;
    int stair[MAX];
    int dp[MAX]; //i까지의 계단에 오기까지 최대값
    scanf("%d", &n);

    for(int i = 1;i <= n;i++)
        scanf("%d", &stair[i]);

    //초기값
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1]+stair[3], stair[2]+stair[3]);

    //dp 계산
    for(int i = 4;i <= n;i++){
        //현재 칸 기준으로 3칸까지 본다
        //현재가 4일때, (2_4, 1_34)
        dp[i] = max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
    }

    printf("%d", dp[n]);
}