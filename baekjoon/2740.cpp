#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, k;
    scanf("%d%d", &n, &m);

    vector<int> tmp(m);
    vector<vector<int>> A, B;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)
            cin >> tmp[j];
        A.push_back(tmp);
    }

    scanf("%d%d", &m, &k);
    vector<int> tmp2(k);

    for(int i = 0;i < m;i++){
        for(int j = 0;j < k;j++)
            cin >> tmp2[j];
        B.push_back(tmp2);
    }

    int val;
    //행렬곱 계산
    for(int i = 0;i < n;i++){
        for(int j = 0;j < k;j++){
            val = 0;
            for(int p = 0;p < m;p++)
                val += A[i][p] * B[p][j];
            printf("%d ", val);
        }
        printf("\n");
    }
}