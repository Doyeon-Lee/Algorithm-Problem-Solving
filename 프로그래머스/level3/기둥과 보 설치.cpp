#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//!!!한 교차점에 기둥과 보 모두 올 수 있대!!!

vector<vector<bool>> col, carp; //기둥과 보의 존재를 나타내는 벡터

//보라면, 한쪽 끝 부분이 기둥 "위"거나, 양쪽이 모두 보인가?
bool isCarpet(int &i, int &j, int &n){
    if(i == n) return false; //보는 바닥에 설치 불가능하다
    else if(col[i+1][j] || col[i+1][j+1] && j < n || 
        j > 0 && j < n && carp[i][j-1] && carp[i][j+1]) return true;
    return false;
}

//기둥이라면 바닥, 기둥, 보 위인가?
bool isCol(int &i, int &j, int &n){
    if(i == n || col[i+1][j] && i < n ||
       carp[i][j-1] && j > 0 || carp[i][j])
        return true;
    return false;
}

bool checkVec(vector<vector<bool>> &v, int &n){
    int s = v.size();
    for(int i = 0;i < s;i++){
        for(int j = 0;j < s;j++){
            if(v[i][j] == 0) continue;
            
            if(col[i][j]) //기둥이면
                if(!isCol(i, j, n)) return false;
            if(carp[i][j]) //보이면
                if(!isCarpet(i, j, n)) return false;
        }
    }
    return true;
}

//일단 삭제해보고, 다른 구조물들이 조건을 만족하는지 전수 조사를 한다
void Del(int &i, int &j, int &n, int &a){    
    bool val;
    if(a){ //보이면
        if(!carp[i][j]) return;
        val = carp[i][j]; carp[i][j] = 0;
    }
    else{ //기둥이면
        if(!col[i][j]) return;
        val = col[i][j]; col[i][j] = 0;
    }
    
    if(!checkVec(col, n) || !checkVec(carp, n)){
        if(a) carp[i][j] = val;
        else col[i][j] = val;
        return;        
    }
}

void Sort(vector<vector<int>> &answer){
    int s = col.size();
    vector<int> v(3);
    cout << s << endl;

    for(int j = 0;j < s;j++){
        v[0] = j;
        
        for(int i = s-1;i >= 0;i--){
            v[1] = s - i - 1;
            if(col[i][j]) {
                v[2] = 0;
                answer.push_back(v);
            }
            if(carp[i][j]){
                v[2] = 1;
                answer.push_back(v);
            }
        }     
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> v) {
    //a = 0(기둥)/1(보); b = 0(삭제)/1(설치)  
    vector<vector<int>> answer; 
    
    //기둥과 보의 N+1xN+1 이차 배열을 생성 및 초기화
    vector<bool> tmp(n+1, 0);
    for(int i = 0;i <= n;i++)
        col.push_back(tmp);    
    
    carp = col;
    int i, j, a, b;
    
    
    for(int k = 0;k < v.size();k++){
        j = v[k][0]; i = n - v[k][1]; a = v[k][2]; b = v[k][3];

        if(b == 1){ //무언가를 설치하라
            if(a == 0){ //기둥이면
                if(col[i][j]) break; //이미 있을 경우
                else if(isCol(i, j, n)) col[i][j] = 1;
            }
            
            else{ //보이면
                if(carp[i][j]) break; //이미 있을 경우
                else if(isCarpet(i, j, n)) carp[i][j] = a;
            }
            
        }
        //무언가를 삭제하라
        else Del(i, j, n, a);
    }    
    Sort(answer);
    return answer;
}