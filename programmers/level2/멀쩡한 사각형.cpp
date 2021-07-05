#include <algorithm>
using namespace std;

long long gcd(int a, int b){
    for(long long i = min(a,b);i > 0;i--){
        if(a % i == 0 && b % i == 0)
            return i;
    }
}

long long solution(int w,int h)
{
	long long answer = 1;
    answer = (long long)w * (long long)h;
    long long g = gcd(w, h);
    w /= g;
    h /= g;
    
    answer -= (w + h - 1) * g;
    return answer;
}

/*
//양 끝의 두 줄은 [a/b]만큼 사용할 수 없다고 생각하여
한 줄씩 줄여가며 계산했으나 3~6, 12~17 실패

long long unav(int a, int b){ //a가 큰 쪽
    if(b == 0) return 0;
    if(b == 1 || a%b == 0) return a;

    long long gauss = a/b+1;
    return gauss * 2 + unav(a - a/b*2, b-2);
}

long long solution(int w,int h)
{
	long long answer = 1;
    answer = w * h;
    
    if(w % h == 0 || h % w == 0) //배수관계이면
        answer -= max(w, h);
    
    else{ //나눈 값이 실수이면
        if(w> h) answer -= unav(w, h);
        else answer -= unav(h,w);
    }
    return answer;
}
*/