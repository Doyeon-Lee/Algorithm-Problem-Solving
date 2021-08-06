#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 51
#define INF 1000000000

int cand[MAX][MAX]; //cand[i][j]는 i부터 j까지 갈 수 있는 최단거리
int n;

//idx의 최대 점수 구하기
int max_num(int idx){
    int max_cnt = 0;
    for(int i = 1;i <= n;i++)
        max_cnt = max(max_cnt, cand[idx][i]);
    return max_cnt;
}

int main(){
    int a, b;
    fill(&cand[0][0], &cand[MAX][MAX], INF);
    scanf("%d", &n);

    //입력값 저장
    while(1){
        scanf("%d%d", &a, &b);
        if(a == -1) break;
        cand[a][b] = cand[b][a] = 1;
    }
    
		//i에서 i로 가는 거리는 0
    for(int i = 1;i <= n;i++)
        cand[i][i] = 0;    

    //모든 노드를 중간에 거쳐간다고 하면
    for(int k = 1;k <= n;k++){
        //i > k > j 순서로 이동
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                //i, k, j는 서로 달라야 한다
                if(i == k || j == k || i == j) continue;
                cand[i][j] = min(cand[i][j], cand[i][k] + cand[k][j]);
            }
        }
    }

    int cur_cnt, min_cnt = 1e9;
    vector<int> answer; //회장 후보를 담는 벡터

		//각 회원의 점수로 회장 후보 찾기
    for(int i = 1;i <= n;i++){
        cur_cnt = max_num(i);
        if(min_cnt > cur_cnt){
            answer.clear(); //현재까지의 후보 쓸모없어짐
            min_cnt = cur_cnt;
            answer.push_back(i);
        }
        else if(min_cnt == cur_cnt)
            answer.push_back(i); //후보 추가
    }

    sort(answer.begin(), answer.end()); //오름차순 정렬
    int s = answer.size();
    printf("%d %d\n", min_cnt, s);
    for(int i = 0;i < s;i++)
        printf("%d ", answer[i]);
}