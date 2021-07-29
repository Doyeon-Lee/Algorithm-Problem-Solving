#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(vector<vector<bool>> &v, vector<bool> &visit, int start){
		//불가능한 인덱스값(조건 만족하는 정점x) or 이미 방문한 노드이면
    if(start == -1 || visit[start]) return;

		//방문 처리 및 출력
    visit[start] = true;
    cout << start << " ";
    
    int s = v.size();
    int idx = -1; //다음에 방문할 인덱스값

    //방문할 점이 여러 개인 경우 정점 번호가 작은 것을 먼저 방문한다
    for(int i = 0;i < s;i++){
        if(v[start][i] && !visit[i]){
            idx = i;
            dfs(v, visit, idx);
        }
    }
}

void bfs(vector<vector<bool>> v, vector<bool> &visit, int start){
    queue<int> q; //다음에 방문할 노드 후보 집합
     q.push(-start); //큰 값부터 니오기 때문에 음수 활용

    while(!q.empty()){
        int s = v.size();
        int idx = -q.front(); q.pop();
        
        if(!visit[idx]){
            cout << idx << " ";
            visit[idx] = true;
        }
	    else continue;

		//간선이 연결되어 있고, 방문한 적 없는 노드라면 큐에 넣음
        for(int i = 0;i < s;i++)
            if(v[idx][i] && !visit[i]) q.push(-i);
    }
}

int main(){
    int n, m, start;
    int a, b; //입력받을 떄 사용할 임시 변수
    cin >> n >> m >> start;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false)); //연결 여부만 저장한다
    vector<bool> visit(n+1, false); //방문했는가
  
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }

    dfs(graph, visit, start);
    cout << endl;
    fill(visit.begin(), visit.end(), false);
    bfs(graph, visit, start);
}