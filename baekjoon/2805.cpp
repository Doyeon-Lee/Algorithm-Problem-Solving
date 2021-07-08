#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> tree;
int n, m;

//binary search
void binsch(ll left, ll right, ll &res){
    if(left > right) return;

    ll sum = 0;
    ll mid = (left + right) / 2;
    
    for(int i = n-1;i >=0;i--){
        if(mid < tree[i]) sum += (tree[i] - mid);
        else break; //내림차순으로 정렬했기 때문에 더 짧다면 break
    }
    if(sum < m) binsch(left, mid-1, res);
    else{
        res = max(res, mid);
        binsch(mid+1, right, res);
    }
}


int main(){
    scanf("%d %d", &n, &m);
    
    for(int i = 0;i < n;i++){
        ll tmp;
        scanf("%lld", &tmp);
        tree.push_back(tmp);
    }
    
    //내림차순 정렬
    sort(tree.begin(), tree.end());
    ll res = 0;
    binsch(0, tree[n-1], res);

    printf("%lld", res);
}