#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> v;
map<int, bool> m;
int k;
int max_res = 0;

//현재까지의 알파벳으로 
int get_num(){
    int ret = 0;
    int len = v.size();
    for(int i = 0;i < len;i++){
        //모든 단어들에 대하여
        string str = v[i];
        int str_len = str.size();
        bool flag = false;
        
        //각 글자들마다
        for(int j = 0;j < str_len;j++){
            if(!m[str[j]]){
                flag = true;
                break;
            }
        }
        if(!flag) ret++;
    }
    return ret;
}

void dfs(int begin, int cnt){
    if(cnt == 0){ //k개의 문자를 택함
        max_res = max(max_res, get_num());
        return;
    }
    
    //브루트 포스
    for(int i = begin;i <= 'z';i++){
        if(m[i]) continue;
        
        m[i] = 1;
        dfs(i, cnt-1);
        m[i] = 0;
    }
}

void init(){
    k -= 5;
    m['a'] = 1; m['n'] = 1;
    m['t'] = 1; m['i'] = 1;
    m['c'] = 1;    
}

int main(){
    int n = 0;
    scanf("%d %d", &n, &k);
    string str;
    if(k < 5){ //anta~tica를 읽지 못함
        printf("0");
        return 0;
    }

    init();
    
    for(int i = 0;i < n;i++){
        cin >> str;
        int len = str.size();
        str = str.substr(4, len-8); //anta, tica를 제와한 문자열
        v.push_back(str);
    }
    dfs('a', k);
    printf("%d", max_res);
}