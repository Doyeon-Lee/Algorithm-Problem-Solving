#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void get_dist(int idx, vector<int> &dist){
    pair<int, int> p1 = chicken[idx];
    int s = house.size();
    
    for(int i;i < s;i++){
        pair<int, int> p2 = house[i];
        dist[i] = min(dist[i], abs(p1.first - p2.first) + abs(p1.second - p2.second));
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    
    int tmp;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            scanf("%d", &tmp);
            if(tmp == 0) continue;
            else if(tmp == 1) house.push_back(make_pair(i, j));
            else chicken.push_back(make_pair(i, j));
        }
    }
    
    int answer = 1e9;
    int cur_dist;
    int s = house.size();
    vector<int> buf(s, 1e9); //집별로 최소 치킨 거리 저장
    vector<int> dist = buf;

    s = chicken.size();
    vector<int> v(s-M, 0);
    for(int i = 0;i < M;i++)
        v.push_back(1);
    
    //m개의 치킨집의 조합을 골라 최소 치킨 거리를 구한다
    do{
        cur_dist = 0;
        dist = buf;
        //선택된 치킨집들 별로 거리를 계산
        for(int i = 0;i < chicken.size();i++)
            if(v[i]) //선택된 곳이라면
                get_dist(i, dist);
        
         for(int j = 0;j < dist.size();j++)
            cur_dist += dist[j];
        answer = min(answer, cur_dist);
    }while(next_permutation(v.begin(), v.end()));
    
    printf("%d", answer);
}