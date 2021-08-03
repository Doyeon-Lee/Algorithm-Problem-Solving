#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii; //value, index

int main(){
    /* cin, cout 입출력 속도 향상 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<pii> pq;
    int n, l, tmp;
    cin >> n >> l;

    for(int i = 0;i < n;i++){
        cin >> tmp;
        pii p = pii(-tmp, i);
        pq.push(p);
        
        int start = max(0, i-l+1);
        while(!pq.empty()){
            pii p = pq.top();
            if(p.second >= start){
                cout << -p.first << " ";
                break;
            }
            else pq.pop();
        }       
    }
}