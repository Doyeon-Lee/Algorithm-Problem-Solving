#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, tmp;
    vector<int> arr; //길이 i인 증가하는 부분 수열을 만들 수 있는 마지막 원소 중  가장 작은 값
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> tmp;

        //길이가 더 증가 가능한 경우
        if(arr.empty() || arr.back() < tmp)
            arr.push_back(tmp);
        else{
            *lower_bound(arr.begin(), arr.end(), tmp) = tmp;
        }
    }
    cout << arr.size();
}