#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int k, n;
    scanf("%d %d", &n, &k);
    bool *arr = new bool[n+1];
    memset(arr, true, n+1);

    int cnt = 0;
    int p = 2; //소수인 p의 인덱스

    while(1){
        while(!arr[p]) p++; //ptr이 true를 가리킬 때까지 탐색한다

        for(int j = p;j <= n;j += p){
            if(arr[j]){
                arr[j] = false;
                cnt++;
            }
            if(cnt == k){
                cout << j;
                exit(0);
            }
        }
    }
}