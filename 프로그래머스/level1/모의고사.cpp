#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = { 2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int a = 0, b = 0, c = 0; //1, 2, 3번 수포자가 맞춘 개수
    int i = 0; //문제의 번호

    while(answers.size() != i){
        if(answers[i] == one[i % 5])
            a++;
        if(answers[i] == two[i % 8])
            b++;
        if(answers[i] == three[i % 10])
            c++;
        i++;
    }

    int result = max(max(a, b), c);

    if(result == a)
        answer.push_back(1);
    if(result == b)
        answer.push_back(2);
    if(result == c)
        answer.push_back(3);
    
    return answer;
}