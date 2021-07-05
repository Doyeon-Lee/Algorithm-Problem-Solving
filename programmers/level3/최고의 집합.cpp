#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int val = s/n;
    int mod = s%n;
    
    if(val == 0) return {-1};
    for(int i = 0;i < n;i++)
        answer.push_back(val);
    
    int idx = answer.size()-1;
    for(int i = mod;i > 0;i--)
        answer[idx--]++;    
    
    return answer;
}