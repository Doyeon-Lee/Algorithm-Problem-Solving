#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int num(string &str){
    int i = 2; bool f = false;
    if(str[i] == '-'){
        i = 3;
        f = true;
    }
    
    int n = str[i] - '0';
    for(++i;i < str.length();i++)
        n = n * 10 + str[i] - '0';
    return f ? -n : n;
}

void Insert(string &str, deque<int> &dq){
    int n = num(str);
    
    if(dq[0] > n) dq.push_front(n);
    else{
        dq.push_back(n);
        sort(dq.begin(), dq.end());
    }
}

void Delete(string &str, deque<int> &dq){
    if(dq.empty()) return;
    
    if(str[2] == '-') dq.pop_front();
    else dq.pop_back();
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(int i = 0;i < operations.size();i++){
        string str = operations[i];
        if(str[0] == 'I') Insert(str, dq);
        else Delete(str, dq);
    }    
    
    if(dq.empty()) return {0,0};
    
    answer.push_back(dq.back());
    answer.push_back(dq.front());
    return answer;
}