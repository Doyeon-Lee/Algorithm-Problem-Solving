#include <iostream>
#include <vector>
using namespace std;
#define MAX 501
#define INF 1000000000 //10e9
typedef long long ll;
typedef pair<int, int> pii;

int n;

bool bellman(vector<pii> *MAP, ll *dist){
    dist[1] = 0; //시작지점 임의로 지정

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int _size = MAP[j].size();
            for(int k = 0;k < _size;k++){
                int next = MAP[j][k].first;
                int cost = MAP[j][k].second;

                //if(dist[j] == INF) continue;
                if(dist[next] <= dist[j] + cost) continue;
                dist[next] = dist[j] + cost;
                //음의 사이클이 있고 값이 갱신되면(여기까지 왔으면 갱신됨)
                if(i == n) return true;
            }
        }
    }
    return false;
}

int main(){
    int T, m, w, s, e, t;
    scanf("%d", &T);

    for(int test = 0;test < T;test++){
        scanf("%d%d%d", &n, &m, &w);
        vector<pii> MAP[MAX]; //<<a, b>, c> 
        ll dist[MAX];
        fill(dist, dist + MAX, INF);
        
        for(int i = 0;i < m;i++){
            scanf("%d%d%d", &s, &e, &t);
            MAP[s].push_back(pii(e, t));
            MAP[e].push_back(pii(s, t));
        }
        for(int i = 0;i < w;i++){
            scanf("%d%d%d", &s, &e, &t);
            MAP[s].push_back(pii(e, -t));
        }
        if(bellman(MAP, dist)) printf("YES\n");
        else printf("NO\n");
    }
}