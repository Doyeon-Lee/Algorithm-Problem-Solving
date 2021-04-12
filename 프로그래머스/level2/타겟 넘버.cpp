#include <string>
#include <vector>
using namespace std;

void dfs(vector<int> &numbers, int pos, int sum, const int target, int &answer){
    if(pos == numbers.size()){
        if(sum == target) answer++;
        return;
    }
    
    sum += numbers[pos];
    dfs(numbers, ++pos, sum, target, answer); //더한거
    sum -= numbers[pos-1] * 2;
    dfs(numbers, pos, sum, target, answer); //뺸거
}

int solution(vector<int> numbers, const int target) {
    int answer = 0;
    dfs(numbers, 0, 0, target, answer);
    return answer;
}