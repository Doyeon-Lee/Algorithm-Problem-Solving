#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    int left = 0; int right = 0;

    //int *arr = new int(n);
    vector<int> arr;

    for(int i = 0;i < n;i++){
        int tmp;
        scanf("%d", &tmp);
        //arr[i] = tmp;
        arr.push_back(tmp);
    }

    int answer = 0x7FFFFFF;
    int sum = 0;
    bool flag = false;

    while(left <= right && right <= n){
        if(sum < s) sum += arr[right++];
        else if(sum >= s){
            flag = true;
            answer = min(answer, right-left);
            sum -= arr[left++];
        }
    }

    if(flag) printf("%d", answer);
    else printf("0");
}