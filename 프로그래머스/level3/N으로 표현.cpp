// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
//다른 사람의 풀이 참고
//number(k) = number(j) [+, -, *, /] number(k-j);
#include <string>
#include <set>
#include <vector>
using namespace std;

void addValue(set<int> &a, set<int> &b, set<int> &c){
    for(int i : a){
        for(int j : b){
            c.insert(i+j);
            c.insert(i-j);
            c.insert(j-i);
            c.insert(i*j);
            //0일 경우 나누면 안된다
            if(j != 0) c.insert(i/j);
            if(i != 0) c.insert(j/i);
        }
    }
}

int solution(int N, int number) {
    vector<set<int>> v{9};
    v[0].insert(0);
    //5, 55, 555..와 같은 값들을 넣어준다
    for(int i = 1;i <= 8;i++)
        v[i].insert(*v[i-1].begin() * 10 + N);

    for(int i = 2;i <= 8;i++){
        for(int j = 1;j < i;j++)
            addValue(v[j], v[i-j], v[i]);
        //number에 해당하는 숫자를 찾았으면
        if(v[i].find(number) != v[i].end()) return i;
    }
    
    return -1;
}