#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, input;
    scanf("%d", &n);
    priority_queue<int> min_pq; //중간값 기준 왼쪽 작은 수들
    priority_queue<int, vector<int>, greater<int>> max_pq; //중간값 기준 오른쪽 수들


    for(int i = 0;i < n;i++){
        scanf("%d", &input);

        if(min_pq.size() <= max_pq.size()) min_pq.push(input);
        else max_pq.push(input);
        
        //크기가 다르면 교환
        if(min_pq.size() > 0 && max_pq.size() > 0){
            int a = min_pq.top();
            int b = max_pq.top();
            if(a > b){
                min_pq.pop();
                max_pq.pop();
                min_pq.push(b);
                max_pq.push(a); 
            }
        }
        printf("%d\n", min_pq.top());
    }
}