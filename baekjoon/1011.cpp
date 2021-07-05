#include <iostream>
using namespace std;

/*
1
11
1(2)1
1(21)1
1(22)1
12(1)21
...
=> 1이 두개면 2로 넘어가고, 2가 2개면 3으로 넘어가고..
*/

void func(long &dist, long &cnt){
    long move = 1;
    long sum = 0;
    
    if(dist == 1){
        cout << 1 << endl;
        return;
    }
    
    //대칭인 부분 찾기
    while(1){
        long val = sum + move * 2;
        if(val <= dist){
            sum = val;
            move++;
        }
        else break;
    }
    move--; //move가 2면 2까지 무조건 대칭임; 12(@)21
    
    cnt += move * 2;
    dist -= (move/2.0 * (move+1))*2; //a1 = 1, d = 1인 등차수열의 합 * 2
 
    //양옆 12 21을 제외한 가운데 숫자를 분해
    for(int i = move+1;i > 0;i--){
        if(dist == 0) break;
        
        cnt += dist/i;
        dist = dist%i;
    }
    cout << cnt << endl;
}

int main(){
    int n = 0;
    cin >> n;
    
    for(int i = n;i > 0;i--){
        long x, y = 0;
        long cnt = 0;
        cin >> x >> y;
        long dist = y - x; //distance

        func(dist, cnt);
    }
}