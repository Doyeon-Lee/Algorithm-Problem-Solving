#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    //입력값 저장
    int T, n, m, tmp;
    vector<int> a, b;
    scanf("%d\n%d", &T, &n);
    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    
    scanf("%d", &m);
    for(int i = 0;i < m;i++){
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    
    //가능한 부분합을 모두 구한다
    vector<int> subA, subB;
    for(int i = 0;i < n;i++){
        int sum = a[i];
        subA.push_back(sum);
        for(int j = i+1;j < n;j++){
            sum += a[j];
            subA.push_back(sum);
        }
    }
    
    for(int i = 0;i < m;i++){
        int sum = b[i];
        subB.push_back(sum);
        for(int j = i+1;j < m;j++){
            sum += b[j];
            subB.push_back(sum);
        }
    }
    
    //이분 탐색을 위해 B의 부분합 정렬
    sort(subB.begin(), subB.end());

    int s = subA.size();
    ll answer = 0;
    //lower, upper bound 사용
    for(int i = 0;i < s;i++){
        int sub = T - subA[i];
        int low = lower_bound(subB.begin(), subB.end(), sub) - subB.begin();
        int high = upper_bound(subB.begin(), subB.end(), sub) - subB.begin();
        answer += (high - low);
    }
    printf("%lld", answer);
}