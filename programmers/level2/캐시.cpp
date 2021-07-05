#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

void searchData(deque<string> &dq, string &s1, int &answer, int &cacheSize){
    auto iter = dq.begin();
    for(;iter != dq.end();iter++){
        string s2 = *iter;
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        
        if(s1 == s2){ //found
            answer += 1;
            dq.erase(iter);
            dq.push_front(s1);
            return;
        }
    }

    //not exists
    if(dq.size() == cacheSize) dq.pop_back();
    dq.push_front(s1);
    answer += 5;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    deque<string> dq(cacheSize);
    for(int i = 0;i < cities.size();i++)
        searchData(dq, cities[i], answer, cacheSize);

    return answer;
}