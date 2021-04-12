#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//다른 사람 풀이 참고; 이분 탐색!
//가장 큰 값의 돌을 찾고 그 중간값에 해당하는 인원이 건넜을 때, 연속된 k개의 0이 있느냐?

bool binarySearch(vector<int> &v, int &mid, int &k){
    int s = v.size();
    int count = 0; //연속된 0의 갯수

    for(int i = 0;i < s;i++){
        if(v[i] - mid <= 0) count++;
        else count = 0;
        
        if(count >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int first = 1, last = *max_element(stones.begin(), stones.end());
    
    while(first <= last){
        int mid = (first + last) / 2;
        
        if(binarySearch(stones, mid, k)) first = mid + 1;
        else last = mid - 1;
    }
    
    return first;
}