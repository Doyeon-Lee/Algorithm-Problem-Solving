#include <string>
#include <vector>
#include <iostream>
using namespace std;
//다른 사람 풀이 이해;
//선택한 풍선이 양쪽의 최소값보다 모두 클 경우만 죽는다
//즉, left는 나보다 왼쪽 중에서 가장 작은 leftMin보다 작으면 살아남기 가능
//right도 마찬가지로 진행하며 값을 업데이트 및 answer를 증가시켜준다

int solution(vector<int> a) {
    int answer = 2; //양 끝은 무조건 살아남기 가능
    
    auto leftMin = a.begin();
    auto rightMin = a.end(); rightMin--;
    auto left = leftMin; left++;
    auto right = rightMin; right--;    
    auto end = a.end();
    
    while(left < end){
        //left와 right가 교차한 후에는 어떻게 되나?
        // left가 위치한 인덱스가, right가 지날 당시에는 rightMin보다
        // 커서 지나갔으나, leftMin보다는 작은 놈이 있을 수 있으므로
        // 끝까지 탐색해줘야 한다. leftMin과 rightMin 둘 중 하나보다라도
        // 작으면 살아남을 수 있기 때문이다.
        if(*left < *leftMin){
            answer++;
            leftMin = left;
        }
        if(*right < *rightMin){
            answer++;
            rightMin = right;
        }
        left++; right--;
    }
    
    //다만 모든 탐색을 완료한 후 둘이 같은 값을 가리킬 경우 중복 카운팅이 됐으므로 1감소
    if(leftMin == rightMin) answer--;
    
    return answer;
}