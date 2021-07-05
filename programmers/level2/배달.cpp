#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    priority_queue<pair<int, int>> pq;
    vector<vector<int>> v(N); //v[i][j]: i부터 j까지가는데 <cost, 시작노드>
    
    vector<int> tmp(N, INF);
    for(int i = 0;i < N;i++)
        v[i] = tmp;
    
    vector<int> dist(N, INF); //distance
    dist[0] = 0;
    int a, b, c; //a부터 b까지 cost c
    int var; //이미 저장된 cost의 값
    vector<int> buf;
    
    //각 마을이 연결된 값을 이차원 배열에 저장
    for(int i = 0;i < road.size();i++){
        buf = road[i];
        for(int j = 0;j < tmp.size();j++){
            a = buf[0]-1; b = buf[1]-1; c = buf[2];
            var = v[a][b];
            
            if(var > c){
                v[a][b] = c;
                v[b][a] = c;
            }
        }
    }
    
    pq.push(make_pair(0, 0)); //1번 노드는 거리가 0
    int curNode, cost;
    int nextNode, ncost;
    pair<int, int> p; //cost, 연결된 노드
    
    //pq가 빌 때까지 반복
    while(!pq.empty()){
        p = pq.top(); pq.pop();
        cost = p.first;
        curNode = p.second;
        
        for(int i = 0;i < N;i++){
            ncost = v[a][b];
            if(ncost == INF) continue;

            nextNode = i;
            if(dist[nextNode] > cost + ncost){
                dist[nextNode] = cost + ncost;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }

    
    
    //k를 초과하지 않는 마을 카운트
    for(int i = 0;i < N;i++){
        if(dist[i] <= K) answer++;
        cout << dist[i];
    }

    return answer;
}