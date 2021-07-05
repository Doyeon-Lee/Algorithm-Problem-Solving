#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(int &n, vector<vector<int>> &v){
    for(int i = 0;i < v[0].size();i++){
        if(v[n][i] == 1){
            v[n][i] = 0;
            dfs(i, v);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0;i < computers.size();i++){
        for(int j = i;j < computers[0].size();j++){
            if(computers[i][j] == 1){
                dfs(i, computers);
                answer++;
            }
        }
    }    
    
    return answer;
}