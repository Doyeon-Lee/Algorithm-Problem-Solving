#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, tmp;
    int answer = 0;
    scanf("%d%d", &n, &k);
    vector<int> coin;

    //오름차순으로 주어진다
    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        coin.push_back(tmp);
    }

    for(int i = n-1;i >= 0;i--){
        if(k == 0) break;
        answer += (k/coin[i]);
        k %= coin[i];
    }

    printf("%d", answer);
}