#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    while(1){
        if(num == 1){
            cout << num;
            return answer;
        }

        if(answer >= 500)
            return -1;
        
        if(num % 2 == 1)
            num = 3 * num + 1;
        else num = num / 2;
        answer++;
    }
}