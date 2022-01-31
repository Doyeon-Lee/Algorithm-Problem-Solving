#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, tmp;
    int answer = 0;
    scanf("%d", &n);
    priority_queue<int> card;

    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        card.push(-tmp);
    }

    while(card.size() > 1){
        int a = -card.top(); card.pop();
        int b = -card.top(); card.pop();
        answer += (a+b);
        card.push(-(a+b));
    }

    printf("%d", answer);
}