#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

//상하좌우로 이동
int xmove[4] = {1, -1, 0, 0};
int ymove[4] = {0, 0, 1, -1};
int m, n;

//박스 범위 내면 true 벗어나면 false
bool in_bound(int x, int y){
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

void bfs(vector<vector<int>> &box, queue<pii> &tomato, int &num_unripe, int &days){
    bool flag; //추가로 익은 토마토가 있는가?
     
    while(!tomato.empty()){
        int cnt = tomato.size();
        flag = false; //현재 익은 토마토에 영향을 받아 새로 익게된 토마토가 있는가?

        //현재 익은 토마토의 개수만큼 반복
        for(int i = 0;i < cnt;i++){
            pii tmp = tomato.front(); tomato.pop();
            //상하좌우 체크
            for(int i = 0;i < 4;i++){
                int xtmp = tmp.first + xmove[i];
                int ytmp = tmp.second + ymove[i];
                if(!in_bound(xtmp, ytmp)) continue;
    
								//범위 내 상하좌우에 안익은 토마토가 있다면
                if(box[xtmp][ytmp] == 0){
                    box[xtmp][ytmp] = 1;
                    num_unripe--; //덜익은 토마토 개수 1감소
                    tomato.push(pii(xtmp, ytmp));
                    flag = true;
                }
            }
        }
        if(flag) days++; //익는데 걸리는 날짜수 증가
    }
}

int main(){
    cin >> m >> n;
    vector<vector<int>> box(n, vector<int>(m));
    queue<pii> tomato; //익은 토마토가 있는 칸의 위치 저장
    int num_unripe = 0; //익지 않은 토마토의 개수
    int days = 0; //다 익는데 필요한 날짜의 개수

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> box[i][j];
            if(box[i][j] == 1) tomato.push(pii(i, j));
            else if(box[i][j] == 0) num_unripe++;
        }
    }

		//이미 다 익은 상태면 0 출력
    if(num_unripe == 0){
        printf("0");
        return 0;
    }
    bfs(box, tomato, num_unripe, days);
    if(num_unripe != 0) printf("-1"); //다 못익으면 -1 출력
    else printf("%d", days);
}