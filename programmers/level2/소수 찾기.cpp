//다른 사람 코드보다 내거가 훨씬 빠르다 아싸
//소수 판별 시 sqrt(n)까지만 확인하면 된다 배우고감
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool Prime(int n){
    if(n < 2) return 0;
    if(n % 2 == 0){
        if(n == 2) return 1;
        else return 0;}
    
    int odd = 3;
    while(odd <= sqrt(n)){
        if(n % odd == 0) return 0;
        odd += 2;}
    return 1;
}

int makeNum(int *arr, int size){
    int tmp = 0;
    for(int i = 0;i < size;i++){
        tmp = tmp * 10 + arr[i];
    }
    return tmp;
}

void permutation(int *arr, int n, int r, int depth, vector<int> &per){
    if(r == depth){
        per.push_back(makeNum(arr, depth));
        return;
    }
    
    for(int i = depth;i < n;i++){
        swap(&arr[i], &arr[depth]);        
        permutation(arr, n, r, depth+1, per);
        swap(&arr[i], &arr[depth]);
    }
}

int solution(string numbers) {
    int answer = 0;
    const int n = numbers.length();
    int *arr = new int[n];
    vector<int> per;
    
    for(int i = 0;i < n;i++) arr[i] = numbers[i] - '0';
    int depth;
    for(int r = 1;r <= n;r++){
        depth = 0;
        permutation(arr, n, r, depth, per);
    }
    
    sort(per.begin(), per.end());
    per.erase(unique(per.begin(), per.end()), per.end());
    
    for(int i = 0;i < per.size();i++)   
        if(Prime(per[i]) == 1) answer++;
    return answer;
}