#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, tmp;
    int answer = 0;
    scanf("%d", &n);
    vector<int> negative, positive;

    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        if(tmp > 0) positive.push_back(tmp);
        else negative.push_back(tmp);
    }

    //절댓값이 큰 순서대로 정렬
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    int s = positive.size();
    int idx = 0;
    while(idx < s-1){
        int a = positive[idx];
        int b = positive[idx+1];
        if(a == 1 || b == 1) answer += (a+b);
        else answer += a*b;
        idx += 2;
    }
    if(idx < s) answer += positive[idx];

    s = negative.size();
    idx = 0;
    while(idx < s-1){
        int a = negative[idx];
        int b = negative[idx+1];
        answer += a*b;
        idx += 2;
    }
    if(idx < s) answer += negative[idx];
    
    printf("%d", answer);
}