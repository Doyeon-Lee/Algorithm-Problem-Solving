#include <vector>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){return a > b;}
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int a, b = 0;
    priority_queue<int, vector<int>, cmp> Q;
    for(int i =0;i < scoville.size();i++) Q.push(scoville[i]);
    
    while(Q.top() < K){
        a = Q.top(); Q.pop();
        if(Q.empty()) return -1;
        
        b = Q.top(); Q.pop();
        Q.push(a + 2 * b);
        answer++;
    }
    
    return answer;
}