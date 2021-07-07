#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

map<char, int> m;

void check_alpha(string &str){
    int len = str.size();
    for(int i = 0;i < len;i++){
        m[str[i]] += pow(10, (len-i-1));
    }
}

bool cmp(pair<char, int> &a, pair<char, int> &b){
    return a.second > b.second;
}

int main(){
    int n;
    string str;
    vector<string> v;
    scanf("%d", &n);
    
		//사용되는 알파벳의 값 누적
    for(int i = 0;i < n;i++){
        cin >> str;
        v.push_back(str);
        check_alpha(str);
    }
    
    //map을 vector로 이동
    vector<pair<char, int>> tmp(m.begin(), m.end());
    sort(tmp.begin(), tmp.end(), cmp);
    
    int s = tmp.size();
    int val = 9;
		//값이 큰 순서대로 알파벳에 숫자 부여
    for(int i = 0;i < s;i++)
        m[tmp[i].first] = val--;

    int answer = 0;
		//각 단어에 대하여 모든 알파벳을 '숫자'로 변환한 뒤 int로 누적
    for(int i = 0;i < n;i++){
        str = v[i];
        int len = str.size();
        for(int j = 0;j < len;j++)
            v[i][j] = m[str[j]] + '0';
        answer += stoi(v[i]);
    }
    cout << answer;
}