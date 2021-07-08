/*
수식을 구현한 코드
*/
#include <iostream>
#include <cmath>
using namespace std;
/*
x/y * 100 = z
(x+v)/(y+v) * 100 >= z+1가 되는 v의 최소값을 구하려 한다
(x+v)/(y+v) >= (z+1) / 100
v{1 - (z+1)/100} >= (z+1)/100*x - y
v >= {(z+1)/100*x - y} / ((99-z)/100) 100은 서로 약분된다
v >= (xz+x-100y) / (99-z)
*/

int main(){
    double x, y;
    scanf("%lf %lf", &x, &y);
    double z = floor(100*y/x);
    if(z >= 99) printf("-1");
    else{
        double a = x*z + x - 100*y;
        double b = 99-z;
        double tmp = a/b;
        printf("%d", (int)ceil(tmp));    
    }
}

/*
이분 탐색 코드

#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    ll z = floor(100*y/x);
    if(z >= 99){
        cout << "-1";
        return 0;
    }

    ll high = 1e9; //문제에서 X의 최대값
    ll low = 0;
    ll mid, tmp;
    
    while(low <= high){
        mid = (low + high)/2;
        tmp = floor(100*(y+mid)/(x+mid));
        if(tmp > z) high = mid - 1;
        else low = mid + 1;
    }
    printf("%lld", low);
}
*/