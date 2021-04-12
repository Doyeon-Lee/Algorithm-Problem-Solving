#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getHead(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0;
    
    while(i < s.length())
        if(isdigit(s[i++])) break;
    return s.substr(0, --i);
}

int getNumber(string &s){
    int l = 0; //최대 다섯 글자의 연속된 숫자의 길이
    int h = 0; //h의 위치
    
    while(!isdigit(s[h])) h++;
    for(; l < 5;l++) 
        if(!isdigit(s[h+l])) break;
    
    string tmp = s.substr(h, l);
    int res = 0;
    for(int i = 0;i < tmp.length();i++)
        res = res * 10 + (tmp[i]-'0');
    return res;
}

bool compare(string a, string b){
    string head1 = getHead(a);
    string head2 = getHead(b);    
    if(head1 < head2) return true;
    else if(head1 > head2) return false;
    else return getNumber(a) < getNumber(b);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(), files.end(), compare);
    return files;
}