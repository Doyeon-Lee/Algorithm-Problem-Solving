#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int w, h = 0;
    int tot = brown + red;
    
    for(h = 3; h < brown;h++){
        if(tot % h != 0) continue;
        w = tot / h;

        if((h-2)*(w-2) == red) break;
    }
    answer.push_back(w);
    answer.push_back(h);
    return answer;
}