//메모리 초과 코드
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int V, E, start;
    scanf("%d%d", &V, &E);
    scanf("%d", &start);
    V++;

    vector<vector<pii>> cost(20001); //u번째 벡터에는 <v, w>들의 벡터가 들어있음
    priority_queue<pii> pq; //지금까지중 <가장 가까운 거리, 해당 노드 번호>
    int dist[20001];
    memset(dist, -1, sizeof(dist));

    //방향 그래프 입력
    for(int i = 0;i < E;i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        cost[u].push_back(pii(v, w));
    }
    
    //시작점부터 탐색
    pq.push(pii(0, start));
    dist[start] = 0;

    //pq가 빌 때까지 가장 가까운놈 반복
    while(!pq.empty()){
        int cur = pq.top().second; pq.pop();
        
        //해당 노드와 연결된 노드의 최단거리 갱신
        int s = cost[cur].size();
            for(int i = 0;i < s;i++){
                int next = cost[cur][i].first;
                int val = dist[cur] + cost[cur][i].second;
                
                if(dist[next] == -1) dist[next] = val;
                else dist[next] = min(dist[next], val);
                
                //방문 가능한 노드들 추가
                pq.push(pii(-cost[cur][i].second, cost[cur][i].first));
        }
    }
    
    for(int i = 1;i < V;i++){
        if(dist[i] == -1) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}