#include <string>
#include <vector>
using namespace std;

void convert(int n, vector <int> &vec, int **arr){
    int binary;   
    for(int i = 0;i < n;i++){
        binary = vec[i];
        for(int j = 0;j < n;j++){
            if(binary % 2 == 1) arr[i][j] = 1;
            binary /= 2;}
    } //for문 close
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string buf = "";
    int **map= new int*[n]; //2차원 배열 동적 할당
    int binary = 0;
    
    for(int i = 0;i < n;i++)
        map[i] = new int[n];
    
    convert(n,arr1, map);
    convert(n,arr2, map);
        
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(map[i][j] == 1) buf = "#" + buf;
            else buf = " " + buf;
        }
        answer.push_back(buf);
        buf = "";
    }
    delete[] map;
    return answer;
}