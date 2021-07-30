#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1000000
typedef pair<int, int> pii;

char MAP[50][50]; //우체국인지 집인지
int height[50][50]; //고도 저장
int n, postx, posty, house; //우체국의 위치
int xmove[] = {1, -1, 0, 0, 1, 1, -1, -1};
int ymove[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool in_bound(int x, int y){
    return !(x < 0 || x >= n || y < 0 || y >= n);
}

//low-high 범위 내의 고도로 배달할 수 있는 집의 개수를 리턴
int bfs(int n, int low, int high){
    //시작 우체국의 높이가 가능한지 판단
    int post = height[postx][posty];
    if(post < low || post > high) return -1;

    int cnt = 0;
    queue<pii> q;
    q.push(pii(postx, posty));
    bool visit[50][50] = {false, };
    visit[postx][posty] = true;

    //카운트한 집의 개수가 전체와 같아지면 멈춘다
    while(!q.empty() && cnt < house){
        pii cur = q.front(); q.pop();
        for(int i = 0;i < 8;i++){
            int nxt_x = cur.first + xmove[i]; //next x, y
            int nxt_y = cur.second + ymove[i];

            if(!in_bound(nxt_x, nxt_y)) continue; //범위를 벗어나면 패스
            if(visit[nxt_x][nxt_y]) continue; //이미 방문했으면 패스
            if(height[nxt_x][nxt_y] < low || height[nxt_x][nxt_y] > high) continue; //범위 내의 고도를 벗어나면 패스
            
            q.push(pii(nxt_x, nxt_y));
            visit[nxt_x][nxt_y] = true;
            if(MAP[nxt_x][nxt_y] == 'K') cnt++;
        }
    }
    
    return cnt;
}

int main(){
    int tmp, answer = INF;
    cin >> n;
    vector<int> arr;
    house = 0;

    //맵 저장
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'P'){
                    postx = i; posty = j;
            }
            else if(MAP[i][j] == 'K')
                house++; //총 집의 개수
        }
    }

    //고도 저장
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> height[i][j];
            arr.push_back(height[i][j]);
        }       
    }
    
    sort(arr.begin(), arr.end());

    //arr 인덱스 투포인터
    int low = 0;
    int high = 0;
    int s = n*n;

    //이분탐색 방식으로도 가능
    while(low <= high && low < s && high < s){
        //해당 범위 내에서 모든 집에 방문이 가능하면
        if(bfs(n, arr[low], arr[high]) == house){
            answer = min(answer, arr[high] - arr[low]); //피로도 업데이트
            low++; //high 늘려봤자 성립하므로 low를 늘린다
        }
        else high++;
    }

    if(answer == INF) cout << 0;
    else cout << answer;
}