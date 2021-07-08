#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    vector<int> A, B, C, D;
    for(int i = 0;i < n;i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        A.push_back(a); B.push_back(b);
        C.push_back(c); D.push_back(d);
    }
    
    vector<int> subA, subB;
    for(int i  = 0; i < n;i++){
        int sum = A[i];
        for(int j = 0; j < n;j++)
            subA.push_back(sum + B[j]);
    }
    
    for(int i  = 0; i < n;i++){
        int sum = C[i];
        for(int j = 0; j < n;j++)
            subB.push_back(sum + D[j]);
    }
    
    //lower, upper 사용 위해 정렬
    sort(subB.begin(), subB.end());

    long long answer = 0;
    int s = subA.size();
    for(int i = 0;i < s;i++){
        int val = -subA[i];
        int low = lower_bound(subB.begin(), subB.end(), val) - subB.begin();
        int high = upper_bound(subB.begin(), subB.end(), val) - subB.begin();
        
        //if(val == subB[low])
        answer += (high - low);
    }

    printf("%lld", answer);
}