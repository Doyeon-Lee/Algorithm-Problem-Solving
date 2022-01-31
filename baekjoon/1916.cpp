#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> city;
vector<int> dist;
priority_queue<pii> pq; //방문 가능한 <거리, 노드번호>를 저장한다


void pq_push(int idx){
    int s = city.size();
    for(int i = 1;i < s;i++){
        if(city[idx][i] != INF){ //방문이 가능하고
			//거리가 새로 갱신되는 경우
            if(dist[idx]+city[idx][i] < dist[i]){
                pq.push(pii(-city[idx][i], i));
                dist[i] = dist[idx]+city[idx][i];
            }
        }
    }
}

int main(){
    int n, m, a, b, c;
    int start_node, end_node;
    scanf("%d%d", &n, &m);
    city = vector<vector<int>> (n+1, vector<int> (n+1, INF));
    dist = vector<int> (n+1, INF);

    for(int i = 0;i < m;i++){
        scanf("%d%d%d", &a, &b, &c);
        city[a][b] = min(city[a][b], c);
    }

    //시작 위치는 방문 처리
    scanf("%d%d", &start_node, &end_node);
    dist[start_node] = 0;
    pq_push(start_node);

    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        pq_push(cur.second);
    }

    printf("%d", dist[end_node]);
}