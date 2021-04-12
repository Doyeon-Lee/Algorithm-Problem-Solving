#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(int i = 0;i < works.size();i++)
        pq.push(works[i]);
    
    for(int i = 0;i < n;i++){
        if(pq.top() == 0) break;
        pq.push(pq.top()-1);
        pq.pop();
    }
    
    while(!pq.empty()){
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    
    return answer;
}