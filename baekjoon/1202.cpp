#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel(n);
    vector<int> bag(k);
    priority_queue<int> pq; //i번째 주머니에 담을 수 있는 보석의 가격
    long long answer = 0;
    
    //보석 정보 저장
    for(int i = 0;i < n;i++)
        cin >> jewel[i].first >> jewel[i].second;
    sort(jewel.begin(), jewel.end());

    //주머니 정보 저장
    for(int i = 0;i < k;i++)
        cin >> bag[i];
    sort(bag.begin(), bag.end());

    int index = 0;
    //모든 가방에 대하여 
    for(int i = 0;i < k;i++){
		while (index < n && jewel[index].first <= bag[i])
			pq.push(jewel[index++].second);

        if(!pq.empty()){
            answer += (long long)pq.top();
            pq.pop();
        }
    }
    cout << answer;
}