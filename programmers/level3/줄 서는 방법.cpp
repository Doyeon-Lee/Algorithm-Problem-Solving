#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long pct[21] = {1, 1, 0};
vector<int> num;

void fnc(int &n, int pos,  long long &k, vector<int> &answer){
    if(answer.size() == n) return;
    
    int quot = k/pct[pos-1];
    k = k%pct[pos-1];
    
    if(k == 0){
        if(quot > 0) quot--;
        else quot = num.size()-1;
    }

    answer.push_back(num[quot]);
    num.erase(num.begin() + quot);
    fnc(n, --pos, k, answer);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    //펙토리얼 저장
    for(int i = 2;i < 21;i++)
        pct[i] = i * pct[i-1];
    //줄을 안 선 사람들의 번호 저장
    for(int i = 1;i <= n;i++)
        num.push_back(i);
    
    fnc(n, n, k, answer);
    return answer;
}

/* 시간 초과
vector<int> solution(int n, long long k) {
    vector<int> answer;
    for(int i = 1;i <= n;i++)
        answer.push_back(i);
    
    long long cnt = 1;
    do{
        if(cnt == k) break;
        cnt++;
    }while(next_permutation(answer.begin(), answer.end()));
    
    return answer;
}
*/