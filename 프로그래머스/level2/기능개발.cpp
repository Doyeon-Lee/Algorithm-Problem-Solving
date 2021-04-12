// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i, start = 0;
    int j = 0;
    
    while(start < progresses.size()){     
        for(i = start;i < progresses.size();i++)
            progresses[i] += speeds[i];
        //하루 작업량 실행
        
        i = start;
        while(progresses[i] >= 100 && i < progresses.size()) i++; //연속하여 완료된 작업들을 탐색
        
        if(progresses[i-1] >= 100 && i != start){
            answer.push_back(i-start);
            start = i;}
    }
    return answer;
}