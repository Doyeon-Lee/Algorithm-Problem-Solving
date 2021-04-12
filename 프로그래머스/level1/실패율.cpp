#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int player = stages.size(); //총 사용자의 명수
    int tmp = 0;
    double f_rate = 0; //각 스테이지별 실패율
    int *success = new int[N+2]; //스테이지의 개수만큼 
    vector<pair<double, int>> f_sort; //실패율과 스테이지 정보 저장

    for(int i = 1;i <= N+1;i++) success[i] = count(stages.begin(), stages.end(), i); //i에 도착한 사람들의 명수
    
    for(int i = 1;i <= N;i++){
        tmp = success[i];
        f_rate = (double)(player-tmp) / player;
        f_sort.push_back(make_pair(f_rate,i));
        player -= tmp;
    }
    
    sort(f_sort.begin(), f_sort.end());
    for(int i = 0;i < N;i++) answer.push_back(f_sort[i].second);
    
    delete[] success;
    return answer;
}