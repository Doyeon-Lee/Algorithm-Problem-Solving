#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land){
    int answer = 0;
    int n = land.size();
    int **dp = new int*[n];
    for(int i = 0;i < n;i++){
        dp[i] = new int[4];
        fill(dp[i], dp[i]+4, 0);
    }

    for(int i = 0;i < 4;i++) dp[n-1][i] = land[n-1][i];
    
    for(int i = n-2;i >= 0;i--){
        dp[i][0] = max(dp[i+1][1], max(dp[i+1][2], dp[i+1][3])) + land[i][0];
        dp[i][1] = max(dp[i+1][0], max(dp[i+1][2], dp[i+1][3])) + land[i][1];
        dp[i][2] = max(dp[i+1][0], max(dp[i+1][1], dp[i+1][3])) + land[i][2];
        dp[i][3] = max(dp[i+1][0], max(dp[i+1][1], dp[i+1][2])) + land[i][3];
    }
    
    answer = max(max(dp[0][0], dp[0][1]), max(dp[0][2], dp[0][3]));   
    return answer;
}

/* 재귀를 사용하는 방식은 시간 초과가 뜨기 때문에 다이나믹 프로그래밍을 사용해야 한다
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int max_score = 0;

void max_land(vector<vector<int> > &land, int row, int col, int score){
    int n = land.size();
    if(n-1 == row){ //모든 행을 탐색함
        if(max_score < score) max_score = score;
        return;
    }

    row++; //다음 행을 볼 것임
    for(int i = 0;i < 4;i++){
        if(i == col) continue; //이전의 
        max_land(land, row, i, score + land[row][i]);
    }
}

int solution(vector<vector<int> > land)
{
    max_land(land, -1, -1, 0);
    return max_score;
}
*/