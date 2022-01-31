#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


int main(){
    int n, e, v1, v2;
    scanf("%d%d", &n, &e);
    vector<vector<ll>> dist(n+1, vector<ll> (n+1, INF));

    int a, b, c;
    for(int i = 0;i < e;i++){
        scanf("%d%d%d", &a, &b, &c);
        dist[a][b] = dist[b][a] = c;
    }
    scanf("%d%d", &v1, &v2);

    //자기 자신으로의 거리는 0이다
    for(int i = 1;i <= n;i++)
        dist[i][i] = 0;

    //플로이드 워셜 알고리즘
    for(int k = 1;k <= n;k++){ //i -> k -> j
        for(int i = 1;i <= n;i++){
            if(dist[i][k] == INF) continue;
            for(int j = 1;j <= n;j++){
                if(dist[k][j] == INF) continue; //연결되어 있지 않다면
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }   
    
    ll answer = min(dist[1][v1]+dist[v1][v2]+dist[v2][n], dist[1][v2]+dist[v2][v1]+dist[v1][n]);
    if(answer >= INF) answer = -1;
    printf("%lld", answer);
}