#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long square = sqrt(n);
    if(n == square * square)
        return (square+1) * (square+1);
    else return -1;
    return answer;
}