#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
    int k, n;
    int prime[100] = {0, };
    priority_queue<long> pq;
    map<long, int> m; //중복된 숫자를 제외하기 위함
    
    scanf("%d %d", &k, &n);
    
    for(int i = 0;i < k;i++){
        int input;
        cin >> input;
        prime[i] = input;
        pq.push(-(long)input);
        m[-(long)input] = 1;
    }
    
    long val;
    
    for(int i = 0;i < n;i++){
        val = pq.top(); pq.pop();
        
        for(int j = 0;j < k;j++){
            long tmp = val * prime[j];
            if(m[tmp] == 1) continue;
            m[tmp] = 1;
            pq.push(tmp);
            if(-val % prime[j] == 0) break;
        }
    }
    
    cout << -val;
}