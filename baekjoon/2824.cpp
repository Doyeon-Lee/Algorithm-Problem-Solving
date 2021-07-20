#include <iostream>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;
#define SIZE 40000 //4만^2 > 10^9이므로
#define INF 1000000000 //10e9
typedef long long ll;
bool prime[SIZE];

//에라토스테네스의 체
void get_prime(bool *prime){
    int idx = 2;
    while(idx < SIZE){
        while(idx < SIZE && !prime[idx]) idx++; //소수 찾기
        for(int i = idx*2;i < SIZE;i+=idx) //소수의 배수 제외
            prime[i] = false;
        idx++;
    }
}

//Factorization; 소인수분해
void factor(ll tmp, map<int, int> &MAP){
    int idx = 2;
    while(idx < SIZE && tmp > 1){
        while(idx < SIZE && !prime[idx]) idx++; //소수 찾기
        while(tmp % idx == 0){
            MAP[idx]++;
            tmp /= idx;
        }
        idx++;
    }
    if(tmp > 2) MAP[tmp]++;
}

int main(){
    int n, m;
    memset(prime, true, sizeof(prime));
    get_prime(prime); //4만까지의 소수를 구함
    
	//각각 a와 b의 소인수분해 결과. 소수 key에 해당하는 개수를 value로 갖는다
    map<int, int> MAPA;
    map<int, int> MAPB;
    ll answer = 1; //a와 b가 서로소라면 결과는 1이다
    bool flag = false; //answer가 INF값을 넘었는가를 나타냄
    
    ll tmp;
	scanf("%d", &n);
    for(int i = 0;i < n;i++){
        cin >> tmp;
        factor(tmp, MAPA);
    }

    scanf("%d", &m);
    for(int i = 0;i < m;i++){
        cin >> tmp;
        factor(tmp, MAPB);
    }
    
    for(auto iter = MAPA.begin();iter != MAPA.end();iter++){
        ll key = iter->first;
        tmp = min(iter->second, MAPB[key]);
        //a와 b에서 공통으로 나온 소수의 횟수만큼 곱해준다
        for(int i = 0;i < tmp;i++){
            answer *= key;
            if(answer >= INF){
                flag = true;
                answer %= INF;
            }
        }
    }
    
    if(flag){
        cout.width(9);
        cout.fill('0');
    }
    cout << answer;
}