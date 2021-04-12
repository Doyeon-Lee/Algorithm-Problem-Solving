#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int pre = 1; //왼쪽에서부터 커버되지 않은 가장 첫 아파트 단지
    int first, last; //현재 기지국에서 전파가 닿는 범위
    int s = stations.size();
    
    for(int i = 0;i < s;i++){
        first = stations[i] - w;
        last = stations[i] + w;
        while(pre < first){ //first가 pre를 커버할 수 있는가?
            pre = pre + 2*w + 1;
            answer++; //기지국 설치
        }
        //이미 설치된 기지국의 범위 내라면 pre의 위치를 업데이트
        if(pre < last+1) pre = last + 1;
    }

    //마지막 기지국 ~ 마지막 아파트 단지까지 남은 범위 확인
    for(;pre <= n;pre = pre+ 2*w+1)
        answer++;
   
    
    return answer;
}