#include <iostream>
#include <vector>
using namespace std;

int n, person1, person2, m;
int answer = -1;

void dfs(vector<vector<bool>> &family, vector<bool> &visit, int cur, int cnt){
    for(int i = 1;i <= n;i++){
        if(answer != -1) return; //이미 정답을 찾았으면
        if(cur == person2){ //도착 지점에 도달했다면 답 갱신
            answer = cnt;
            return;
        }

        if(i == cur) continue; //자기 자신으로는 이동할 수 없음
        if(family[cur][i] && !visit[i]){
            visit[i] = true;
            dfs(family, visit, i, cnt+1);
            visit[i] = false; //방문 후 되돌림
        }
    }
}


int main(){
    scanf("%d%d%d%d", &n, &person1, &person2, &m);

    vector<vector<bool>> family(n+1, vector<bool> (n+1, false));
    vector<bool> visit(n+1, false);
    visit[person1] = true; //시작점은 무조건 방문함

    int a, b;
    for(int i = 0;i < m;i++){
        scanf("%d%d", &a, &b);
        family[a][b] = family[b][a] = true;
    }
    
    dfs(family, visit, person1, 0);
    cout << answer;
}