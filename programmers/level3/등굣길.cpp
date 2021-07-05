//처음에는 각 블럭까지의 최단 거리와 함께 해당 블럭까지 올 수 있는 경로의 수를 pair로
//저장했으나, 이차원 데이터를 탐색하는 순서대로라면 어차피 최단거리가 됨을 깨닫고
//구글을 통해 다른 사람의 풀이를 참고하여 풀었다.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int x, int y, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> m(y+1); //map
    vector<int> v(x+1);
    
    for(int i = 0;i <= y;i++) m[i] = v;
    vector<vector<int>> d = m;
   
    //웅덩이 -1
    for(int i = 0;i < puddles.size();i++){
        vector<int> v = puddles[i];
        m[v[1]][v[0]] = -1;
    }
    
    //dp
    d[1][0] = 1;
    for(int i = 1;i <= y;i++){
        for(int j = 1;j <= x;j++){
            if(m[i][j] == -1) d[i][j] = 0;
            else
                d[i][j] = (d[i-1][j] + d[i][j-1]) % 1000000007;
        }
    }
    answer=  d[y][x];
    
    return answer;
}