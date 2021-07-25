#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define MAX 501
//위상정렬 문제!

int main(){
    int Time[MAX]; //해당 건물을 짓는데 필요한 시간
    vector<vector<int>> graph(MAX); //해당 건물을 지어야만 건설 가능한 건물 번호 저장
    int entry[MAX] = {0, }; //해당 건물을 짓는데 필요한 건물들의 개수
    int answer[MAX];
    queue<int> q; //entry가 0인 노드들만 저장

    int n, tmp;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        cin >> Time[i];
        answer[i] = Time[i];
        
        while(1){
            scanf("%d", &tmp);
            if(tmp == -1) break;
            
            graph[tmp].push_back(i);
            entry[i]++;
        }
    }
    
    for(int i = 1;i <= n;i++){
        if(entry[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        tmp = q.front(); q.pop();
        int s = graph[tmp].size();
        for(int i = 0;i < s;i++){
            int idx = graph[tmp][i];
            answer[idx] = max(answer[idx], answer[tmp] + Time[idx]);

            if(--entry[idx] == 0)
                q.push(idx);
        }
    }

    for(int i = 1;i <= n;i++)
        printf("%d\n", answer[i]);
}