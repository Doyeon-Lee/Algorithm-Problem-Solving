#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//시계방향으로
void rotate(vector<vector<int>> &key){
     vector<vector<int>> rkey = key;
    int n = key.size();
    //초기화
    for(int i = 0;i < n;i++)
        fill(rkey[i].begin(), rkey[i].end(), 0); 
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            rkey[j][n-i-1] = key[i][j];
        }
    }
    key = rkey;
}

void initLockMap(vector<vector<int>> &map, vector<vector<int>> &lock, int &m, int &n){
    //(m, m)부터 n개까지가 lock 자리임
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            map[m+i][m+j] = lock[i][j];
        }
    }
}

void initKeyMap(vector<vector<int>> &map, vector<vector<int>> &key, int &m){
    for(int i = 0;i < m;i++)
        for(int j = 0;j < m;j++)
            map[i][j] = key[i][j];
}

bool moveKey(int &x, int &y, vector<vector<int>> &key, vector<vector<int>> map){
    int m = key.size();
    int n = map.size()-2*m;    
    
    for(int i = x;i < x+m;i++){
        for(int j = y;j < y+m;j++){
            map[i][j] += key[i-x][j-y];
        }
    }
    
    for(int i = m;i < m+n;i++){
        for(int j = m;j < m+n;j++){
            if(map[i][j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    int ms = 2*m+n;

    vector<int> v(ms);
    vector<vector<int>> map(ms);
    for(int i = 0;i < ms;i++)
        map[i] = v;
    
    initLockMap(map, lock, m, n);
    
    for(int i = 0;i < 4;i++){
        rotate(key);        
        initKeyMap(map, key, m);
        
        for(int i = 0;i < m+n;i++){
            for(int j = 0;j < m+n;j++)
                if(moveKey(i, j, key, map)) return true;
        }
    }
    return false;
}