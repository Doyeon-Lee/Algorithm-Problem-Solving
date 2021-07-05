#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    //정렬해서 비교하기
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0;i < completion.size();i++){
    if(participant[i] != completion[i])
        return participant[i];   
    }
    return participant.back();

}