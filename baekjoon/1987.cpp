#include <iostream>
//#include <set>
//#include <unordered_map>
using namespace std;

char MAP[20][20];
int xmove[] = {0, 0, 1, -1};
int ymove[] = {1, -1, 0, 0};
int r, c, answer = 0;
bool alpha[26] = {false, };
//set<char> alpha;
//unordered_map<char, bool> alpha;

bool in_bound(int x, int y){
    return !(x < 0 || x >= r || y < 0 || y >= c);
}

//(x, y) 부분에서 방문하지 않았던 상하좌우의 개수를 카운트
void dfs(int x, int y, int cnt){
    answer = max(answer, cnt);
    if(answer == r*c) return; //이미 모든 칸을 탐색했다면

    for(int i = 0;i < 4;i++){
        int nxt_x = x + xmove[i];
        int nxt_y = y + ymove[i];
        if(!in_bound(nxt_x, nxt_y)) continue; //범위를 벗어나면 패스

        int idx = MAP[nxt_x][nxt_y] - 'A';
        //처음 보는 알파벳이라면 삽입 > dfs > 원상복귀
        if(!alpha[idx]){
            alpha[idx] = true;
            dfs(nxt_x, nxt_y, cnt+1);
            alpha[idx] = false;
		}
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> MAP[i][j];
        }
    }

    alpha[MAP[0][0]-'A'] = true; //첫 번째 칸 방문 표시
    //alpha.insert(MAP[0][0]); //첫 번째 칸 방문 표시
	//alpha[MAP[0][0]] = true; 
    dfs(0, 0, 1); //첫 번째 칸도 포함한다
    cout << answer;
}