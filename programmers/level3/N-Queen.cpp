#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(vector<int> &chess, int idx, int &n){
    //같은 열 또는 대각선인가
    for(int i = 0;i < idx;i++){
        if(chess[idx] == chess[i]) return false; 
        if(abs(chess[i]-chess[idx]) == abs(i-idx)) return false;
    }
    return true;
}

//k는 이제 놓아야 할 체스판의 행
void dfs(vector<int> &chess, int k, int &n, int &answer){
    if(k == n){
        cout << endl;
        answer++; return;
    }
    
    //chess[k][i]에 놓고 싶다
    for(int i = 0;i < n;i++){
        chess[k] = i;
        //일단 놓고 나서 성립 가능한지 확인해본다
        if(check(chess, k, n))
            dfs(chess, k+1, n, answer);
        chess[k] = 0;
    }
}

int solution(int n) {
    int answer = 0;
    //각 x좌표에 놓인 체스의 y좌표를 저장
    vector<int> chess(n);
    dfs(chess, 0, n, answer);

    return answer;
}