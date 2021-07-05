#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times){
    long long min = 1;
    long long max = (long long)*max_element(times.begin(), times.end()) * n; 
    long long mid;
    long long answer = max;
    
    while(min <= max){
        long long sum = 0;
        mid = (min + max) / 2;
        for(int i = 0;i < times.size();i++){
            sum += mid / times[i];
        }
        
        if(sum < n) min = mid + 1;
        else{
            if(answer > mid)
                answer = mid;
            max = mid - 1;
        }
    }
    
    return answer;
}