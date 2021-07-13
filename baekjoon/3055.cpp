#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//강사님 솔루션
typedef pair<int, int> pii; //좌표 저장
int r, c; //RxC 칸

bool check_bound(int i, int j){
    return (i >= 0 && i < r & j >= 0 && j < c);
}

int main(){
    vector<vector<char>> m; //지도
    queue<pii> ddg_q; //두더지의 방문 좌표를 저장
    queue<pii> water_q; //물의 방문 좌표를 저장
    int ddg_vt[50][50] = {0, }; //두더지가 해당 칸에 방문하는데 얼마나 걸렸는가?
    int water_vt[50][50] = {0, }; //물이 "
    pii biber; //비버의 굴의 좌표
    
    vector<char> tmp;
    char ch;
    scanf("%d %d", &r, &c);
    
    for(int i = 0;i < r;i++){
        tmp.clear();
        for(int j = 0;j < c;j++){
            cin >> ch;
            tmp.push_back(ch);
            
            if(ch == 'S') {
                ddg_vt[i][j] = 1;
                ddg_q.push(pii(i, j));
            }
            else if(ch == 'D') biber = pii(i, j);
            else if(ch == '*'){
                water_q.push(pii(i, j));
                water_vt[i][j] = 1;
            }
        }
        m.push_back(tmp);
    }
    
    int xmove[4] = {-1, 1, 0, 0};
    int ymove[4] = {0, 0, -1, 1};
    
    //두더지 큐가 비어있으면 더이상 갈 곳이 없음 = 끝
    while(!ddg_q.empty()){
        //물을 먼저 이동
        int s = water_q.size();
        
        for(int i = 0;i < s;i++){
            pii buf = water_q.front(); water_q.pop();
            int x = buf.first; //단순히 처음 나오는 수를 x로 쳤다(x축 말고)
            int y = buf.second;
            
            for(int j = 0;j < 4;j++){
                //범위를 벗어나지 않고 방문하지 않은 곳이라면 상하좌우를 탐색한다
                //물은 비버의 굴에 갈 수 없고, 돌을 통과할 수 없다
                int xtmp = x + xmove[j];
                int ytmp = y + ymove[j];
                if(check_bound(xtmp, ytmp) && water_vt[xtmp][ytmp] == 0
                && !(xtmp == biber.first && ytmp == biber.second)
                && m[xtmp][ytmp] != 'X'){
                    water_vt[xtmp][ytmp] = water_vt[x][y] + 1;
                    water_q.push(pii(xtmp, ytmp));
                }
            }
        }
    
        //두더지를 이동
        s = ddg_q.size();
        for(int  i = 0;i < s;i++){
            pii buf = ddg_q.front(); ddg_q.pop();
            int x = buf.first;
            int y = buf.second;
            for(int j = 0;j < 4;j++){
                //범위를 벗어나지 않고 방문하지 않은 곳이라면 상하좌우를 탐색한다
                //물이 방문하지 않고, 돌이 아니어야 한다
                int xtmp = x + xmove[j];
                int ytmp = y + ymove[j];
                if(check_bound(xtmp, ytmp) && ddg_vt[xtmp][ytmp] == 0
                && water_vt[xtmp][ytmp] == 0 && m[xtmp][ytmp] != 'X'){
                    ddg_vt[xtmp][ytmp] = ddg_vt[x][y] + 1;
                    ddg_q.push(pii(xtmp, ytmp));
                }
            }
        }
    }
    
    if(ddg_vt[biber.first][biber.second] == 0)
        cout << "KAKTUS";
    else cout << ddg_vt[biber.first][biber.second] - 1;
}