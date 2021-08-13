#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, answer = 0;
    scanf("%d%d", &n, &k);
    vector<int> weight(n), value(n);
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0)); //nxk 이차원 벡터
    // i번째 물건까지 넣을 수 있고 최대 무게가 j일 떄의 최대 이윤을 저장한다

    //무게와 가치 입력
    for(int i = 1;i <= n;i++)
        scanf("%d%d", &weight[i], &value[i]);

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            if(j >= weight[i]) //현재 무게가 i번째 물건을 감당 가능하면
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else dp[i][j] = dp[i-1][j];
            answer = max(answer, dp[i][j]);
        }
    }
    printf("%d", answer);
}