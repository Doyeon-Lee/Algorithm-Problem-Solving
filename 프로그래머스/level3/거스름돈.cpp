/*
https://jyukki97.github.io/blog/2020-01-10-change/   풀이 참고
가장 작은 단위의 돈부터 시작하여 액수를 증가시키며 경우의 수를 쌓아 올린다.
[1,2,5]의 경우, 먼저 1원으로 가능한 경우(1)을 모두 채워 넣고, 2, 5 순서로 추가한다.
arr[n]은 현재까지의 동전으로 n원을 만들 수 있는 경우의 수이며, 2가 추가될 경우 
arr[2]부터 시작하여(거스름돈이 2일 경우부터 경우의 수가 늘어나는 것이므로)
현재까지의 경우에 2를 하나 더 사용가능한 경우가 추가될 것이다. arr[3]도 2보다 크므로
2를 사용한 경우를 추가해주는데, 3=2+1이므로 3에서 2를 뺀 나머지 즉 1원을 만들 수 있는
경우의 수를 더해준다. 따라서 arr[n] = arr[n] + arr[n-i] (i는 추가적으로 사용할 동전)이다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int num[100001] = {1};

    for(int m : money){
        for(int i = m;i <= n;i++)
            num[i] += num[i-m];
    }

    answer = num[n];
    return answer;
}