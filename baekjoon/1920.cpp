#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int N, M, tmp;
    scanf("%d", &N);
    map<int, bool> m;
    
    for(int i = 0;i < N;i++){
        scanf("%d", &tmp);
        m[tmp] = true;
    }
    
    scanf("%d", &M);
    for(int i = 0;i < M;i++){
        scanf("%d", &tmp);
        if(m[tmp]) printf("1\n");
        else printf("0\n");
    }
}