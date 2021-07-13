#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;


int main(){
    int min_dp[2][3]; //두 줄만 있으면 가능, 메모리 초과 해결
    int max_dp[2][3];
    
    //vector<vector<int>> m; //map
    //vector<int> v(3);
    int m[MAX][3];
    int n, tmp;
    scanf("%d", &n);
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 3;j++){
            cin >> m[i][j];
            //scanf("%d", &tmp);
            //v[j] = tmp;
        }
        //m.push_back(v);
    }
    
    //초기화
    for(int i = 0;i < 3;i++)
        max_dp[1][i] = min_dp[1][i] = m[n-1][i];
    
    for(int i = n-2;i >= 0;i--){
        max_dp[0][0] = m[i][0] + max(max_dp[1][0], max_dp[1][1]);
        max_dp[0][1] = m[i][1] + max(max_dp[1][0], max(max_dp[1][1], max_dp[1][2]));
        max_dp[0][2] = m[i][2] + max(max_dp[1][1], max_dp[1][2]);
        
        min_dp[0][0] = m[i][0] + min(min_dp[1][0], min_dp[1][1]);
        min_dp[0][1] = m[i][1] + min(min_dp[1][0], min(min_dp[1][1], min_dp[1][2]));
        min_dp[0][2] = m[i][2] + min(min_dp[1][1], min_dp[1][2]);

        //아래 칸으로 옮기기
        for(int j = 0;j < 3;j++){
            max_dp[1][j] = max_dp[0][j];
            min_dp[1][j] = min_dp[0][j];
        }
    }
    
    int minval = 1e9;
    int maxval = 0;
    for(int i = 0;i < 3;i++){
        minval = min(minval, min_dp[1][i]);
        maxval = max(maxval, max_dp[1][i]);
    }
        
    cout << maxval << " " << minval;
}