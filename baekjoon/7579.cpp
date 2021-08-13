#include <iostream>
#include <vector>
using namespace std;
#define MAX 100*100 + 1
#define INF 1000000000 //1e9

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> memory(n+1), cost(n+1);
    vector<vector<int>> dp(n+1, vector<int> (MAX, 0)); //앱 개수 최대 100개 비용 최대 100
    //i번째 앱까지 선택했을 때 j번째 cost를 만족하는 최소 메모리

    //활성화된 앱들의 메모리
    for(int i = 1;i <= n;i++)
        scanf("%d", &memory[i]);

    //활성화된 앱들의 비활성화 시 비용
    for(int i = 1;i <= n;i++)
        scanf("%d", &cost[i]);

    int answer = INF;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= MAX;j++){ //모든 비용에 대해서
            if(j >= cost[i]) //해당 비용이 i번째 앱을 수용 가능한가
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);
            else dp[i][j] = dp[i-1][j];
        
            if(dp[i][j] >= m) answer = min(answer, j); //m 이상이면 최소 비용 업데이트
        }
    }
    printf("%d", answer);
}