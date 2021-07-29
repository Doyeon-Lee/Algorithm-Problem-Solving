#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

//상하좌우로 이동
int xmove[4] = {1, -1, 0, 0};
int ymove[4] = {0, 0, 1, -1};
int n;

bool in_bound(int x, int y){
    return !(x < 0 || x >= n || y < 0 || y >= n);
}

void bfs(vector<vector<int>> &v, pii p, vector<int> &answer){
    queue<pii> q;
    q.push(p);
    int cnt = 1; //현재 단지 내의 집의 개수(1개인 경우 대비 1로 초기화)

    while(!q.empty()){
        pii tmp = q.front(); q.pop();
        
        for(int i = 0;i < 4;i++){
            int xtmp = tmp.first + xmove[i];
            int ytmp = tmp.second + ymove[i];

            if(!in_bound(xtmp, ytmp)) continue;
            if(v[xtmp][ytmp]){
                v[xtmp][ytmp] = 0; //방문했다는 의미로 0 대입
                q.push(pii(xtmp, ytmp));
                cnt++;
            }
        } //4개 방향대로
    }
    answer.push_back(cnt);
}

int main(){
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> answer; //한 단지 내에 속한 집의 개수 저장

    char c;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
           cin >> c;
           v[i][j] = c-'0';
        }
    }

    //집을 발견하면 단지 내의 집 개수 탐색, answer 업데이트
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(v[i][j]){
                v[i][j] = 0; //첫 집은 방문한 것으로 처리
                bfs(v, pii(i, j), answer);
            }
        }
    }

    sort(answer.begin(), answer.end()); //단지내 집 수대로 정렬

    int s = answer.size(); //단지의 개수
    printf("%d\n", s);
    for(int i = 0;i < s;i++)
        printf("%d\n", answer[i]);
}