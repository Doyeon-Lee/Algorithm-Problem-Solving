#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    auto front = people.begin(); 
    auto end = people.end();
    sort(front, end);
    end--;
    
    while(front < end){
        if(*front + *end <= limit){
            front++; end--;
        }
        else end--;
        answer++;
    } 
    
    if(front == end) answer++; //혼자 남은 경우
    return answer;
}