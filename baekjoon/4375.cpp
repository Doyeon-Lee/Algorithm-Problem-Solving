#include <iostream>
using namespace std;

int main(){
    int input;
    while(scanf("%d", &input) != EOF){
        int val = 1;
        int cnt = 1;
        while(1){
            if(val % input == 0){
                printf("%d\n", cnt);
                break;
            }
            else{
                val %= input;
                val = val * 10 + 1;
                cnt++;
            }
        }
    }
}