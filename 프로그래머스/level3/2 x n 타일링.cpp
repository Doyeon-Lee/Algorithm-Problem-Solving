#include <string>
#include <vector>
#define MODNUM 1000000007;
using namespace std;

int solution(int n) {
    int answer = 0;
    int *arr = new int[n+1];
    arr[1] = 1; arr[2] = 2;
    
    for(int i = 3;i <= n;i++)
        arr[i] = (arr[i-1] + arr[i-2])%MODNUM;
    
    answer = arr[n];
    return answer;
}