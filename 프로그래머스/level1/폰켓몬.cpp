#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(), nums.end());
    unique(nums.begin(), nums.end());
    
    set<int> s;
    for(int i = 0;i < nums.size()/2;i++){
        if(s.find(nums[i]) != s.end()) break;
        else{
            s.insert(nums[i]);
            answer++;
        }
    }
    
    return answer;
}