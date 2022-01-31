#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int main(){
    int n, tmp;
    int answer = 0;
    vector<int> arr;
    scanf("%d", &n);

    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    
    int sum = 0;
    sort(arr.begin(), arr.end());
    for(int i = 0;i < n;i++){
        sum += arr[i];
        answer += sum;
    }
    
    printf("%d", answer);
}