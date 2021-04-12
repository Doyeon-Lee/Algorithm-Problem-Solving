//!신장 트리(spanning tree); Kruskal, Prim, Sollin 알고리즘!
//Kruskal: cycle이 생기지 않도록 가장 작은 cost부터 트리에 추가
//Prim: 하나의 노드(트리 T)에서 시작하여 cycle이 생기지 않도록 (u,v)중 한쪽만 T에 있는 것 선택
//Sollin: 여러 트리(포레스트)마다 edge를 트리가 하나가 될 때까지 하나씩 붙여간다

//여기서는 Kruskal을 사용하였다
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

class Graph{
public:
    Graph(int n);
    int Find(int i);    
    void Add(int i, int j);
private:
    int *parent;
};


Graph::Graph(int n){
    parent = new int[n];
    fill(parent, parent+n, -1);    
}

int Graph::Find(int i){
    while(parent[i] >= 0)
        i = parent[i];
    return i;
}

void Graph::Add(int i, int j){
    parent[i] = j;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    int s = costs.size();
    
    Graph g(n);
    int a, b, c; //a, b, cost
    int r1, r2; //root1, root2
    int edges = 0; //연결된 edge의 갯수
    
    for(int i = 0;i < s;i++){
        if(edges == n-1) break; //모든 노드들이 연결됨
        
        a = costs[i][0];
        b = costs[i][1];
        c = costs[i][2];
        
        r1 = g.Find(a);
        r2 = g.Find(b);
        
        if(r1 != r2){ //cycle 아님
            g.Add(r1, r2);
            answer += c;           
            edges++;
        }
    }
    
    return answer;
}