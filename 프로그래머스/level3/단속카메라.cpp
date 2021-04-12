#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    return a[1] <= b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), compare);
    
    int i = 0;
    while(!routes.empty()){
        int cam = routes[0][1];
        answer++;

        auto iter = routes.begin();
        while(iter != routes.end()){
            if((*iter)[0] <= cam && cam <= (*iter)[1]) routes.erase(iter);
            else break;
        }
    }
    
    return answer;
}