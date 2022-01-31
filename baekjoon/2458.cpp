#include <iostream>
#include <vector>
#define INF 1000000000 //1e9
using namespace std;

int main(){
    int n, m, a, b;
    int answer = 0;
    scanf("%d%d", &n, &m);
    vector<vector<int>> dist(n+1, vector<int> (n+1, INF));
    
    //입력값 저장
    for(int i = 0;i < m;i++){
        scanf("%d%d", &a, &b);
        dist[a][b] = 1;
    }
    
    //나 -> 나 거리 0 초기화
    for(int i = 1;i < n+1;i++)
        dist[i][i] = 0;
    
    //i -> k -> j일 때 거리가 갱신 가능한가?
    for(int k = 1;k <= n;k++){
        for(int i = 1;i < n+1;i++){
            for(int j = 1;j < n+1;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    
    /*내가 몇 등인지 알려면 내가 출발해서 도달할 수 없는 놈이 없거나,
    혹은 도달할 수 없는데 나를 가리키고 있을 경우여야 한다
    즉, 내가 걔한테 갈 수 있거나 걔가 나한테 올 수 있어야 등수를 알 수 있음
    */
    for(int i = 1;i < n+1;i++){
        bool flag = true;
        for(int j = 1;j < n+1;j++)
            if(dist[i][j] == INF && dist[j][i] == INF){
                flag = false;
                break;
            }
        if(flag) answer++; //위쪽 포문을 통과했구나!
    }
    printf("%d", answer);
}