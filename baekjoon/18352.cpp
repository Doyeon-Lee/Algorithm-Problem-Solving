#include <iostream>
#include <vector>
#include <queue>
#define INF 300001 //k의 최대값은 300,000
using namespace std;


int main(){
    int n, m, k, x, a, b;
    scanf("%d%d%d%d", &n, &m, &k, &x);
    vector<vector<int>> city(n+1); //맵 입력
    vector<int> dist(n+1, INF); //x로부터 다른 노드까지 걸리는 거리
    vector<bool> visit(n+1, false);

    //입력값 받기
    for(int i = 0;i < m;i++){
        scanf("%d%d", &a, &b);
        city[a].push_back(b);
    }

    queue<int> q; //다음으로 방문할 노드들
    dist[x] = 0; //시작점 거리는 0
    q.push(x);    

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(visit[cur]) continue; //이미 방문한 노드이면
        visit[cur] = true;
        int cur_dist = dist[cur];

        int s = city[cur].size();
        for(int i = 0;i < s;i++){
            int idx = city[cur][i];
            //방문한 적이 없다면 q에 넣고
            if(!visit[idx]) q.push(idx);
            //거리 갱신
            if(cur_dist + 1 < dist[idx]){
                dist[idx] = cur_dist + 1;
            }
        }
    }

    bool no_city = true; //하나의 도시라도 방문했으면 false
    for(int i = 1;i <= n;i++){
        if(dist[i] == k){
            printf("%d\n", i);
            no_city = false;
        }
    }

    if(no_city) cout << -1;
}