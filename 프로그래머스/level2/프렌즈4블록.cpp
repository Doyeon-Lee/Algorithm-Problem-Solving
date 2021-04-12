#include <string>
#include <vector>
#include <iostream>
using namespace std;

void sameCheck(vector<string> &v, vector<string> &v2, int &i, int &j){
    if(v[i][j] == v[i][j+1] && v[i][j] == v[i+1][j] && v[i+1][j] == v[i+1][j+1]){
        v2[i][j] = v2[i][j+1] = 'e';
        v2[i+1][j] = v2[i+1][j+1] = 'e';
    }
}

void pushString(vector<string> &v, int i, int &j){
    for(;i > 0;i--)
        v[i][j] = v[i-1][j];
    v[0][j] = ' ';
}

void eraseBlock(vector<string> &v, int &answer){
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v[0].length();j++){
            while(v[i][j] == 'e'){
                if(i == 0) v[i][j] = ' ';
                else pushString(v, i, j);
                answer++;}   
        }
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> erase_board = board;
    
    while(1){
        int pre_answer = answer;
        for(int i = 0;i < m-1;i++){
            for(int j = 0;j < n-1;j++){
                if(isblank(board[i][j])) continue;
                sameCheck(board, erase_board, i, j);
            }
        }
        eraseBlock(erase_board, answer);
        board = erase_board;
        if(pre_answer == answer) break;
    }
    
    return answer;
}