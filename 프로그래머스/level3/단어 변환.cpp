#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//하나의 알파벳만 다른지 확인
bool comp(string &a, string &b){
    int dif = 0;
    for(int i = 0;i < a.length();i++)
        if(a[i]!=b[i]) dif++;
        
    if(dif == 1) return true;
    else return false;
}

void dfs(string &begin, string &target, vector<string> &words, int &answer, int count, vector<bool> &checkUse){
    if(begin == target){
        count;
        if(count < answer) answer = count;
        return;
    }
    
    for(int i = 0;i < words.size();i++){
        if(checkUse[i]) continue;
        if(comp(begin, words[i])){            
            checkUse[i] = true;
            dfs(words[i], target, words, answer, count+1, checkUse);
            checkUse[i] = false;
        }
    }    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 50;
    //target이 word안에 없을 경우
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    vector<bool> checkUse(words.size(), 0);
    dfs(begin, target, words, answer, 0, checkUse);    
    
    return answer;
}