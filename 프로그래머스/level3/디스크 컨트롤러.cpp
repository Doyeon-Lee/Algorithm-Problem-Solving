#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp{
    bool operator()(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int i = 0;
    while(i < jobs.size() || !pq.empty()){
        //수행 가능한 작업을 추가해준다
        while(i < jobs.size()){
            if(i < jobs.size() && jobs[i][0] <= time) pq.push(jobs[i++]);
            else break;
        }
        
        if(!pq.empty()){
            time += pq.top()[1];
            answer += (time - pq.top()[0]);
            pq.pop();
        }
        else time = jobs[i][0];
    }
    
    return answer / jobs.size();
}