#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//cur은 해당 노드까지 오는데 걸린 횟수
void bfs(int cur, bool** &g, bool* &v, int* &d, int &n){
    queue<int> q;
    q.push(cur);
    v[cur] = true;
    d[cur] = 0;
    
    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        for(int i = 0;i < n;i++){            
            if(!v[i] && g[start][i]){
                v[i] = true;
                q.push(i);
                d[i] = d[start] + 1;
            }
        } //for문 close
    } //while문 close
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    bool **g = new bool*[n]; //graph
    bool *v = new bool[n]; //visited
    int *d = new int[n];
    
    for(int i = 0;i < n;i++){
        g[i] = new bool[n];
        v[i] = false; d[i] = 0;
        
        for(int j = 0;j < n;j++)
            g[i][j] = false;
    }
        
    int a = 0; int b = 0;
    for(int i = 0;i < edge.size();i++){
        //간선을 추가한다
        a = edge[i][0]-1; b = edge[i][1]-1;
        g[a][b] = 1; g[b][a] = 1;
    }    
    
    bfs(0, g, v, d, n);

    int m = *max_element(d, d+n);
    answer = count(d, d+n, m);
        
    return answer;
}