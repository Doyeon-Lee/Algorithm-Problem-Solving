#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int n = 0; //맨 앞에서 대기하는 트럭의 번호
    int sum = 0; //다리 위의 트럭의 무게의 합
    int truckN = truck_weights.size(); //트럭의 갯수
    queue<pair<int, int>> Q;
    
    while(n < truckN){
        if(!Q.empty() && ((time - Q.front().second) == bridge_length)){
            sum -= truck_weights[Q.front().first];
            Q.pop();
        }
        
        if(sum+truck_weights[n] <= weight){
            sum += truck_weights[n];
            Q.push(make_pair(n, time));
            n++;
        }
        time++;
    } //마지막 트럭까지 큐 안에 들어왔음
    time += bridge_length; //마지막 트럭이 다리를 건너는 시간

    return time;
}