#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int n;
    scanf("%d", &n);
    vector<ll> liquid(n);

    for(int i = 0; i < n;i++)
        scanf("%lld", &liquid[i]);
    sort(liquid.begin(), liquid.end());

    //투 포인터
    int left = 0, right = n-1;
    ll val = 2e9; //두 수의 합
    pii answer = pii(-1, -1);

    while(left < right){
        int sum = liquid[left] + liquid[right];
        if(val > abs(sum)){
            val = abs(sum);
            answer = pii(left, right);
            if(sum == 0) break; //합이 0이면 종료
        }

        if(sum < 0) left++;
        else right--;
    }

    printf("%lld %lld", liquid[answer.first], liquid[answer.second]);
}