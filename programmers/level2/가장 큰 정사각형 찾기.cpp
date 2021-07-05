#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void square(vector<vector<int>> &board, vector<vector<int>> &dp){
    for(int i = 1;i < dp.size();i++)
        for(int j = 1;j < dp[0].size();j++){
            if(board[i][j] && board[i-1][j] && board[i][j-1] && board[i-1][j-1])
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
        }
}

int solution(vector<vector<int>> board){
    vector<vector<int>> dp = board;
    
    square(board, dp);
    int answer = 0;
    for(int i = 0;i < dp.size();i++)
        answer = max(answer, *max_element(dp[i].begin(), dp[i].end()));

    return pow(answer, 2);
}

/*
//[i][j]에서 한 변의 길이가 n+1인 정사각형이 가능한가?
bool nextsquare(vector<vector<int>> &v, int a, int b, int n){
    if(a+n >= v.size() || b+n >= v[0].size()) return false;    
    
    for(int i = 0;i <= n;i++){
        if(!v[a+n][b+i]) return false;
        if(!v[a+i][b+n]) return false;
    }
    return true;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[0].size();j++){
            if(board[i][j]){
                int n = 1;
                while(1)
                    {if(!nextsquare(board, i, j, n++)) break;}
                answer = max(answer, --n);
            }
        }
    }
    
    return pow(answer, 2);
}
*/