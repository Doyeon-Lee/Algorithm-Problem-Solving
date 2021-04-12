#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, tmp;
    int a, b, c;
    
    for(int i = 0;i < commands.size();i++){
        a = commands[i][0]-1;
        b = commands[i][1]-1;
        c = commands[i][2]-1;
        for(int j = a; j <= b;j++)
            tmp.push_back(array[j]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[c]);
        tmp.clear();
    }
    return answer;
}