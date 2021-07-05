#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

void findMinMax(map<string, int> &m, vector<vector<int>> &v){
    int min = 1e9; int max = 0;
    for(auto iter = m.begin();iter != m.end();iter++){
        if(iter->second < min) min = iter->second;
        if(iter->second > max) max = iter->second;
    }
    v.push_back({++min, ++max});
}

bool compare(vector<int> &a, vector<int> &b){
    if(a[1]-a[0] == b[1]-b[0]) return a[0] < b[0];
    return a[1]-a[0] < b[1]-b[0];
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<vector<int>> v;
    vector<string> u = gems; //unique
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    int us = u.size(); //unique size; 총 보석 종류의 개수

    map<string, int> m;
    int idx = 0; string tmp = "";
    
    for(int idx = 0;idx < gems.size();idx++){
        tmp = gems[idx];
        m[tmp] = idx;
        
        if(m.size() == us)
            findMinMax(m, v);
    }

    sort(v.begin(), v.end(), compare);   
    answer = v[0];
    return answer;
}