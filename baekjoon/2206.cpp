#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000
typedef pair<int, int> pii;

//상하좌우 이동
int xmove[] = {0, 0, 1, -1};
int ymove[] = {1, -1, 0, 0};
int MAP[MAX][MAX];
int visit[MAX][MAX][2]; //NxM개의 칸, 2는 벽을 뚫을 수 있는가
int n, m;

bool in_bound(int x, int y){
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

//도착지점까지 이동한 최소 칸의 개수를 반환
int bfs(){
    queue<pair<pii, bool>> q;
    //해당 칸에 도착하는데 걸린 칸수를 저장(뚫기 불가능/가능별로)
    visit[0][0][1] = 1; //시작점도 1칸으로 친다
    q.push(make_pair(pii(0, 0), true)); //시작점, 벽 뚫기 가능

    while(!q.empty()){
        pii cur = q.front().first; 
        bool wall = q.front().second;
        q.pop();

        //도착했으면 
        if(cur.first == n-1 && cur.second == m-1)
            return visit[cur.first][cur.second][wall];

        for(int i = 0;i < 4;i++){
            int nxt_x = cur.first + xmove[i];
            int nxt_y = cur.second + ymove[i];
            if(!in_bound(nxt_x, nxt_y)) continue; //범위 벗어나면 패스

            if(!MAP[nxt_x][nxt_y] && !visit[nxt_x][nxt_y][wall]){ //이동할 곳이 벽이 아니고 방문한 적이 없다면
                visit[nxt_x][nxt_y][wall] = visit[cur.first][cur.second][wall] + 1;
                q.push(make_pair(pii(nxt_x, nxt_y), wall));
            }
            //벽이 있고 아직 안뚫었다면
            else if(MAP[nxt_x][nxt_y] && wall){
                if(!visit[nxt_x][nxt_y][wall-1]){ //빙문한 적이 없다면
                    visit[nxt_x][nxt_y][wall-1] = visit[cur.first][cur.second][wall] + 1;
                    q.push(make_pair(pii(nxt_x, nxt_y), wall-1));
                }
            }
        } //상하좌우
    }

    return -1;
}

int main(){
    char c;
    cin >> n >> m;
    //지도 저장
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> c;
            MAP[i][j] = c-'0';
        }
    }

    cout << bfs();
}