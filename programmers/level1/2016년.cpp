#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    
    int i;
    for(i = 0;i < a-1;i++)
        sum += month[i];
    
    sum += b;
    printf("%d", sum);
    
    string answer = "";
    
    switch(sum % 7){
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 0:
            answer = "THU";
            break;
    }
    return answer;
}