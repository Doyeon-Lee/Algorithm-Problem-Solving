#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int k, n;
ll answer = 0;

void bin_search(vector<ll> &arr, ll start, ll end){
    if(start > end) return;
    
    ll mid = (start + end) / 2;
    ll sum = 0;
    for(int i = 0;i < k;i++)
        sum += arr[i] / mid;

    if(sum < n) //더 작게 잘라야 한다
        bin_search(arr, start, mid-1);
    else{ //더 크게 잘라보자
        answer = max(answer, mid);
        bin_search(arr, mid+1, end);
    }
}

int main(){
    scanf("%d%d", &k, &n);
    vector<ll> lan(k);

    for(int i = 0;i < k;i++)
        cin >> lan[i];
    sort(lan.begin(), lan.end());

    ll start = 1;
    ll end = lan[k-1];
    bin_search(lan, start, end);
    cout << answer;
}