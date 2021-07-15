#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//에라토스테네스의 체 방식으로 소수를 구한 후 나머지가 0이 되는걸 찾는다
#define MAX 1000001

//아래는 while문을, 그 아래는 for문을 사용한 것으로 어떤 것을 사용해도 동일하다.
//다만 for문의 경우가 조금 더 빠른 것으로 나타났다.
// bool check(string &str, int val){
//     int s = str.size();
//     int idx = 0;
//     int num = str[idx++] - '0';

//     while(idx < s){
//         //val로 나눌 수 있는 수가 될 때까지 반복한다. 
//         num = num*10 + (str[idx++] - '0');
//         num %= val;
//     }
//     return num == 0;
// }

bool check(string &str, int val){
    int s = str.size();
    int num = 0;

    for(int i = 0;i < s;i++){
        //val로 나눌 수 있는 수가 될 때까지 반복한다. 
        num = num*10 + (str[i] - '0');
        num %= val;
    }
    return num == 0;
}

int main(){
    bool prime[MAX];
    memset(prime, 1, sizeof(prime));
    int k;
    string str;

    cin >> str;
    scanf("%d", &k);
    
    //소수 구하기
    int idx = 2;
    while(1){
        //소수 찾음
        while(!prime[idx] && idx < MAX) idx++;
        if(idx >= k) break;
        
        if(check(str, idx)){
            printf("BAD %d", idx);
            return 0;
        }
        
        for(int i = idx*2;i < MAX;i+=idx) prime[i] = false;
        idx++;
    }

    printf("GOOD");
}