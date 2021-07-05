#include <iostream>
using namespace std;

int main(){
    int answer = 0;
    int n = 0;
    cin >> n;
    
    int quot = n / 5;
    int mod = n % 5;
    
    while(quot >= 0){
        if(mod % 3 == 0) {
            answer = quot + mod / 3;
            break;
        }
        else{
            quot--;
            mod = n - quot * 5;
        }
    }
    
    if(quot < 0) cout << -1;
    else cout << answer;
}