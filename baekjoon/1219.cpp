#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF -1000000000 //1e9
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef long long ll;

//S에서 E로 가는 길이 있는가?
bool check(vector<pair<pii, int>> &graph, int S, int E){
    int s = graph.size();
    vector<bool> visit(s, false);
    queue<int> q;
    q.push(S);
    
    while(!q.empty()){
        int cur_node = q.front(); q.pop();
        if(cur_node == E) return true;
        visit[cur_node] = true;
        
        for(int i = 0;i < s;i++){
            ppi cur_edge = graph[i];
            pii tmp = cur_edge.first;
            if(cur_node == tmp.first && !visit[tmp.second]) q.push(tmp.second);
        }
    }
    return false;
}

int main(){
    int n, a, b, m;
    scanf("%d%d%d%d", &n, &a, &b, &m);
    vector<pair<pii, int>> graph; //<<시작, 끝>, 비용>
    vector<ll> dist(n, INF); //시작 지점 기준 거리
    vector<int> money(n); //각 도시에서 벌 수 있는 금액

    //교통 수단 입력받기
    int p, q, r;
    for(int i = 0;i < m;i++){
        scanf("%d%d%d", &p, &q, &r);
        graph.push_back(ppi(pii(p, q), r));
    }

    //도시별 금액 입력
    int tmp;
    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        money[i] = tmp;
    }

    dist[a] = money[a]; //시작 지점의 거리는 0
    bool cycle = false; //사이클 여부

    //벨만 포드 알고리즘
    for(int i = 0;i < n;i++){
        //모든 간선 탐색
        for(int j = 0;j < m;j++){
            ppi cur_edge = graph[j];
            pii tmp = cur_edge.first;
            //a -> tmp.second 로 갈 때, tmp.first를 거쳐가면 얻는 money와 잃는 cost를 계산
            ll new_cost = dist[tmp.first] + money[tmp.second] - cur_edge.second;
            if(dist[tmp.first] != INF && new_cost > dist[tmp.second]){
                dist[tmp.second] = new_cost;
                //tmp.second -> b로 갈 수 있으면 사이클 발생한 것
                if(i == n-1 && check(graph, tmp.second, b)){
                    cycle = true;
                    break;
                }
            }
        }
    }
    
    if(dist[b] == INF) printf("gg");
    else{
        if(cycle) printf("Gee");
        else printf("%d", dist[b]);
    }
}