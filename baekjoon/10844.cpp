#include <iostream>
#include <vector>
using namespace std;
#define DIV 1000000000 //1e9
//0으로 시작하면 안된다!

int main(){
    vector<vector<int>> dp(10, vector<int> (10, 0));
    vector<int> tmp(10, 0);
    int n, answer = 0;
    scanf("%d", &n);

    //초기화
    for(int i = 1;i < 10;i++)
        dp[i][i] = 1;

    for(int k = 2; k <= n;k++){
        //뒤에 j를 더 붙인다
        for(int i = 1; i < 10;i++){
            for(int j = 0;j < 10;j++){
                tmp[j] = 0;
                if(j > 0) tmp[j] = (tmp[j] + dp[i][j-1]) % DIV;
                if(j < 9) tmp[j] = (tmp[j] + dp[i][j+1]) % DIV;
            }
            dp[i] = tmp;
        }
    }

    for(int i = 1; i < 10;i++){
        for(int j = 0;j < 10;j++){
            answer = (answer + dp[i][j]) % DIV;
        }
    }

    printf("%d", answer);
}