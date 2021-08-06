#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000 //1e9
#define MAX 501
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int n, m;
    ll dist[MAX];
    fill(&dist[0], &dist[MAX - 1], INF);
    vector<pair<pii, int>> city; //<<a, b>, c> 
    scanf("%d%d", &n, &m);
    
    //입력값 저장
    int a, b, c;
    for(int i = 0;i < m;i++){
        scanf("%d%d%d", &a, &b, &c);
        city.push_back(make_pair(pii(a, b), c));
    }

    dist[1] = 0; //시작 지점 거리는 
    //1번 도시에서 출발(문제)
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
            a = city[j].first.first;
            b = city[j].first.second;
            c = city[j].second;
            
            if(dist[a] == INF) continue;
            if(dist[b] <= dist[a] + c) continue;
            dist[b] = dist[a] + c;
            
            if(i == n){ //n까지 왔으면 음수 사이클임
                printf("-1");
                return 0;
            }
        }
    }

    for(int i = 2;i <= n;i++){
        if(dist[i] == INF) printf("-1\n");
        else printf("%lld\n", dist[i]);
    }
}