#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<int> v(n);
    for(int i = 0;i < n;i++) v.push_back(0);

    vector<vector<int>> g(n);
    for(int i = 0;i < n;i++)
        g[i] = v;

    //g[i][j] 는 i가 j와 대결해서 이기면 1, 지면 -1이다
    for(int i = 0;i < results.size();i++){
        int win = results[i][0]-1;
        int lose = results[i][1]-1;
        g[win][lose] = 1;
        g[lose][win] = -1;
    }



    //A에게 진 사람은 A가 진 사람들보다 무조건 약하므로 승패를 알 수 있다
    //g[i][j] == -1이면 g[i][k] = 1이고 g[j][k] = -1이다
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(g[i][j] == 1){
                for(int k = 0;k < n;k++){
                    if(g[i][k] == -1){
                        g[j][k] = -1;
                        g[k][j] = 1;}
                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        int res = 0; //0이 나온 횟수; 1이어야 본인을 제외한 결과를 아는 것
        for(int j = 0;j < n;j++){
            if(g[i][j] == 0) res++;
            if(res > 1) break;
        }
        if(res == 1) answer++;
    }

    return answer;
}