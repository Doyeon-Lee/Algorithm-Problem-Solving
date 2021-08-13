#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000

int main(){
    int n, x, tmp, answer = 0;
    vector<int> arr;

    //입력값 받기
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    scanf("%d", &x);

    //투 포인터
    sort(arr.begin(), arr.end()); //정렬해야 순서대로 비교가 가능함
    int left = 0, right = n-1;
    while(left < right){
        if(arr[left] + arr[right] < x) left++;
        else{
            if(arr[left] + arr[right] == x) answer++;
            right--;
        }
    }

    printf("%d", answer);
}