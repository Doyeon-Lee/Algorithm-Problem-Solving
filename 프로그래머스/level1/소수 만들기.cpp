//next_permutation을 사용해서 조합을 구하는 방법:
//새로운 임의 접속이 가능한 컨테이너를 생성하고
//nCr에서 r개만큼의 1, n-r개만큼의 0을 넣고 정렬한다
//do while문으로 next_permutation을 반복하며, 1에 해당하는
//인덱스의 수를 참조하여 원하는 작업을 실행해준다
#include <vector>
#include <algorithm>
using namespace std;
#define MAXSUM 3001
bool prime[3001]; //1000이하의 자연수이므로

//소수 구하기는 에라토스테네스의 방법을 사용한다
void CheckPrime(){
    fill(prime, prime+MAXSUM, 1);
    for(int i = 2;i < MAXSUM;i++){
        if(prime[i] == 0) continue;
        for(int j = i+i;j <= MAXSUM;j += i)
            prime[j] = 0;
    }
}
/*
void Combination(vector<int> &nums, int pos, int r, int sum, int &answer){
    if(r == 0){ //3개를 다 선택함
        if(prime[sum]){
            answer++;
            return;
        }
    }
    if(pos == nums.size()) return; //끝까지 확인함
    
    Combination(nums, ++pos, r, sum, answer); //현재 숫자를 선택하지 않음
    sum += nums[pos-1]; //하나를 선택함
    Combination(nums, pos, --r, sum, answer);   
}
*/

void Combination(vector<int> nums, int &answer){
    int sum = 0;
    int s = nums.size();
    vector<int> per(s-3);
    for(int i = 0;i < 3;i++) per.push_back(1);
    
    do{
        sum = 0;
        for(int i = 0;i < per.size();i++)
            if(per[i] == 1) sum += nums[i];
        if(prime[sum]) answer++;
    }while(next_permutation(per.begin(), per.end()));
}


int solution(vector<int> nums) {
    int answer = 0; int pos = 0;
    int sum = 0; int r = 3;
    
    CheckPrime();
    Combination(nums, answer);
    return answer;
}