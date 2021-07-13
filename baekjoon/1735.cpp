#include <iostream>
using namespace std;
//두 분모의 곱으로 통일한 후, 유클리드 호제법으로 합친 분모와 분자의 최대공약수를 구해 나눈다.

int gcd(int a, int b){
    if(b == 0) return a;
    int big = max(a, b);
    int small = min(a, b);
    int mod = big % small;

    return gcd(small, mod);
}

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int den = a*d + b*c; //분자
    int num = b*d; //분모
    
    int g = gcd(den, num);
    printf("%d %d", den/g, num/g);
}