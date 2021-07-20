#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int root[1001];

int find(int num){
    if(root[num] == num) return num;
    else return find(root[num]);
}

void Union(int a, int b){
    int tmp1 = find(a);
    int tmp2 = find(b);
    
    if(tmp1 != tmp2) root[tmp2] = tmp1;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    memset(root, -1, sizeof(root));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq; //비용, 노드 번호

    //입력값 순서대로 정렬
    for(int i = 0;i < m;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        pii p = pii(a, b);
        pq.push(make_pair(c, p));
    }

    int answer = 0;
    while(!pq.empty()){
        answer += pq.top().first;
        pii p = pq.top().second;
        pq.pop();
        Union(p.first, p.second);
    }
    printf("%d", answer);
}