#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int arr[10] = {0, };
    cin >> str;

    int s = str.size();
    for(int i = 0;i < s;i++)
        arr[str[i] - '0']++;

    int sum = 0;
    //모든 숫자들의 합이 3의 배수여야 한다
    for(int i = 1;i < 10;i++)
        sum += i*arr[i];
           
    //0이 없거나 수들의 합이 3의 배수가 아니라면 30의 배수가 되지 못한다
    if(arr[0] == 0 || sum % 3 != 0){
        cout << -1;
        return 0;
    }

    for(int i = 9;i >= 0;i--){
        int cnt = arr[i];
        for(int j = 0;j < cnt;j++)
            cout << i;
    }
}