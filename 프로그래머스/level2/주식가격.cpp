#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    int s = prices.size();
    vector<int> answer(s);
    priority_queue<pair<int, int>> PQ; //값과 시간 저장
    pair<int, int> p;
    
    for(int i = 0;i < prices.size();i++){
        while(!PQ.empty()){ 
            if(PQ.top().first > prices[i]){
                answer[PQ.top().second] = i - PQ.top().second;
                PQ.pop();
            }
            else break;
        }
        PQ.push(make_pair(prices[i], i));
    }
    
    s--;
    while(!PQ.empty()){
        answer[PQ.top().second] = s - PQ.top().second;
        PQ.pop();
    }    
    
    return answer;
}