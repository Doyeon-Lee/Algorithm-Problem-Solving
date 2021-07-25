#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll n, b;

//v함수 제곱해서 리턴
vector<vector<int>> matrix_mul(vector<vector<int>> &v1, vector<vector<int>> &v2){
    vector<vector<int>> result = v1;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            ll val = 0;
            for(int k = 0;k < n;k++)
                val += v1[i][k] * v2[k][j];
            result[i][j] = val % 1000;
        }
    }
    return result;
}


int main(){
    cin >> n >> b;

    vector<int> tmp(n, 0);
    vector<vector<int>> v, answer;

    //행렬 입력받음
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cin >> tmp[j];
        v.push_back(tmp);
    }

    while(b > 0){
        if(b%2 == 1){
            if(answer.size() == 0) answer = v;
            else answer = matrix_mul(answer, v);
        }
        v = matrix_mul(v, v);
        b /= 2;
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ", answer[i][j] % 1000); //모든 값이 1000이고 1번만 곱할 경우에 대한 처리!
        }
        printf("\n");
    }
}