#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> v, int location) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(int i = 0;i < v.size();i++) pq.push(v[i]);
    
    auto iter = v.begin();
    while(1){
        if(location == 0){
            if(pq.top() == *iter) break;
            else location = v.size();
        }
        else{
            if(pq.top() == *iter){ //출력한다
                pq.pop();
                v.erase(iter);
                location--;
                answer++;
                continue;
            }
        }
        v.push_back(*iter);
        iter = v.begin();
        v.erase(iter);
        location--;
    }

    return ++answer;
}