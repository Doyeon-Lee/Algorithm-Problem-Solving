using namespace std;

int solution(int n) {
    int answer = 0;
    long long *arr = new long long[n+1];
    arr[0] = 0; arr[1] = 1;
    
    for(int i = 2;i <= n;i++)
        arr[i] = (arr[i-2] + arr[i-1]) % 1234567;
    
    answer = arr[n] % 12345687;
    return answer;
}