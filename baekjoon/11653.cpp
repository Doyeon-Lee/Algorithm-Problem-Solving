#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1) return 0;

    for(int i = 0;i < n;i++){
        while(n % i == 0){
            printf("%d\n", i);
            n /= i;
        }
    }
}