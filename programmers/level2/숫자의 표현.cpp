#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1;i <= n/2;i++){
        int tmp = i;
        int sum = 0;
        while(1){
            sum += tmp;
            if(sum == n){ answer++; break;}
            if(sum > n) break;
            tmp++;
        }
    }
    
    return ++answer;
}