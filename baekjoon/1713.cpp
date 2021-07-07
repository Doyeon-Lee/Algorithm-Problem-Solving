#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int del_cand(vector<int> &frame, map<int, pair<int, int>> &m){
    int s = frame.size();
    int min_id = frame[0];
    
    for(int idx = 0;idx < s;idx++){
        int cur_id = frame[idx];
        //추천수가 가장 작은 후보 찾기
        if(m[cur_id].first < m[min_id].first)
            min_id = cur_id;
        //추천수가 같다면 더 오래된 후보 찾기
        else if(m[cur_id].first == m[min_id].first && m[cur_id].second < m[min_id].second)
            min_id = cur_id;
    }
    return min_id;
}


int main(){
    int n; //사진틀의 개수
    int num; //총 추천 횟수
    int tmp;
    
    cin >> n >> num;
    map<int, pair<int, int>> m; //후보 번호, <추천수, 등록 시점>
    vector<int> frame; //사진틀
    
    for(int i = 0;i < num;i++){
        cin >> tmp;
        
        //새로운 후보라면
        auto iter = find(frame.begin(), frame.end(), tmp);
        if(iter == frame.end()){
               //사진틀에 공간이 있다면
            if(frame.size() < n){
                frame.push_back(tmp);
                m[tmp] = make_pair(1, i);
            }
            else{ //사진틀이 모두 찼다면 새로 등록하기
                int del_id = del_cand(frame, m);
                replace(frame.begin(), frame.end(), del_id, tmp);
                m[del_id] = make_pair(0, 0);
                m[tmp] = make_pair(1, i);
            }
        }
        else m[tmp].first += 1; //이미 있는 후보라면
    }
    
    sort(frame.begin(), frame.end());
    for(int i = 0;i < n;i++)
        cout << frame[i] << " ";
}