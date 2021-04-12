#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(int n) {
    string answer = "";
    int num = n / 2;
    int i;
    
    for(i = 0;i < num;i++)
        answer += "수박";
        
    if(n % 2 == 1)
        answer += "수";
       
    cout << answer;
    
    return answer;
}