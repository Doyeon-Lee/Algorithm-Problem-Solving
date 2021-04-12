#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int retSize(string str, int i){ //str[i+1] > str[i]인가?
    
    char c = str[0];
    char c2 = str[i++]; //겹치는 마지막 숫자
    while(i < str.length()){
        if(str[i] > c) return 0; //더 크다
        else if(str[i] < c) return 1; //더 작다
        else i++; //같으면 그 뒷자리도 확인한다
    }
    //끝까지 봤는데도 다 같다면 겹치는 마지막 숫자와 비교한다
    if(c2 > c) return 1; //짧은 쪽이 더 먼저 와야함
    else return 0;
}

struct cmp{ //true이면 왼쪽이 오른쪽보다 먼저 나온다
    bool operator()(string a, string b){
        int i = 0;     
        
        while(i < min(a.length(), b.length())){
            if(a[i] == b[i]){
                if(i == a.length()-1)
                   {if(i == b.length()-1) return 0; //완전히 같은 수
                    else return retSize(b,i) != 0;}                            
                else if(i == b.length()-1) return retSize(a,i) == 0;
                else {i++; continue;}
            }
            return a[i] > b[i];
        } //while문 close
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(int i = 0;i < numbers.size();i++) str.push_back(to_string(numbers[i]));
    if(str.size() == 1) return str[0];
    
    sort(str.begin(), str.end(), cmp());

    
    if(str[0] == "0") return "0";    
    for(int i = 0;i < str.size();i++)
        answer = answer + str[i];

    return answer;
}