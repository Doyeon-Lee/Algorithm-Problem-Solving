#include <iostream>
#include <vector>
using namespace std;
#define DIV 10007

int main(){
    //현재 길이에서 시작하는 숫자가 i, 끝나는 숫자가 j일때 오르막수 개수
    vector<vector<int>> dp(10, vector<int> (10, 0));
    vector<int> tmp(10, 0);
    int n, answer = 0;
    scanf("%d", &n);

    //길이가 1일때 초기화
    for(int i = 0;i < 10;i++)
        dp[i][i] = 1;

    for(int k = 1; k < n;k++){
        //뒤에 j를 더 붙인다
        for(int i = 0; i < 10;i++){
            int sum = 0;
            for(int j = i;j < 10;j++){
                sum += dp[i][j] % DIV;
                tmp[j] = sum;
            }
            dp[i] = tmp;
        }
    }

    for(int i = 0; i < 10;i++){
        for(int j = i;j < 10;j++){
            answer = (answer + dp[i][j]) % DIV;
        }
    }

    printf("%d", answer);
}