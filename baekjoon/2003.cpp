#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, tmp;
    vector<int> v;
    scanf("%d %d", &n, &m);
    
    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    
    auto left = v.begin();
    auto right = v.begin();
    int sum = 0;
    int answer = 0;
    
    while(left <= right && right <= v.end()){
        if(sum < m){
            sum += *right;
            right++;
        }
        else{
            if(sum == m) answer++;
            sum -= *left;
            left++;
        }
    }
    printf("%d", answer);
}