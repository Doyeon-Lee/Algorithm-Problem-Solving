#include <iostream>
#include <vector>
using namespace std;

int white, blue;

//시작점 [x][y]와 그 변의 길이 h
int recur(vector<vector<int>> &v, int x, int y, int h){
    //1또는 0의 개수 파악
    if(h == 1){
        if(v[x][y]) blue++;
        else white++;
        return v[x][y];
    }

    int val = 0;
    h /= 2;
    val += recur(v, x, y, h); //왼쪽 위
    val += recur(v, x, y+h, h); //오른쪽 위
    val += recur(v, x+h, y, h); //왼쪽 아래
    val += recur(v, x+h, y+h, h); //오른쪽 아래

    //정사각형이라면
    if(val == 4){
        blue -= 3;
        return 1;
    }
    else if(val == 0){
        white -= 3;
        return 0;
    }
    return -4;
}


int main(){
    int n;
    scanf("%d", &n);

    vector<int> tmp(n);
    vector<vector<int>> v(n, tmp);
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> v[i][j];

    white = blue = 0;
    recur(v, 0, 0, n);
    printf("%d\n%d", white, blue);
}