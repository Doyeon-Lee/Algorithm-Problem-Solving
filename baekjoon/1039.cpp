#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int k;
int max_res = 0;
int dp[1000001][11];

//str의 i번째와 j번째를 바꿔 리턴
string swap(string &str, int &i, int &j){
    string res = str;
    res[i] = str[j];
    res[j] = str[i];
    return res;
}


int dfs(string str, int cnt){
    //k번만큼 탐색했다면 최대값 갱신
    if(cnt == k) return stoi(str);
    
    int len = str.size();
    int &ret = dp[stoi(str)][cnt];
    if(ret != -1) return ret;
    
    for(int i = 0;i < len-1;i++){
        for(int j = i+1; j < len;j++){
            string tmp = swap(str, i, j);
            if(tmp[0] == '0') continue;
            ret = max(ret, dfs(tmp, cnt+1));
        }
    }
    return ret;
}


int main(){
    memset(dp, -1, sizeof(dp));
    string str;
    cin >> str; //string은 cin만 가능하다
    scanf("%d", &k);
    printf("%d", dfs(str, 0));
}