#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> uniform;
    uniform.assign(n+1, 1);    
    
    for(int i = 0;i < reserve.size();i++) uniform[reserve[i]]++;
    for(int i = 0;i < lost.size();i++) uniform[lost[i]]--;
    answer = n - count(uniform.begin(), uniform.end(), 0);
    
    for(int i = 1;i <= n;i++){
        if(uniform[i] == 0){
            if(uniform[i-1] == 2 && i != 1){
                uniform[i-1]--; answer++;}
            else if(uniform[i+1] == 2 && i != n){
                uniform[i+1]--; answer++;}
        } //if문 close
    } //for문 close
    
    return answer;
}