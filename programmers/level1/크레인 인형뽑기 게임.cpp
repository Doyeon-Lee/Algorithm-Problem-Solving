#include <string>
#include <vector>
#include <stack>
using namespace std;

int pick_up(int n, vector<vector<int>> &board){ //가장 위에 있는 인형의 번호를 반환
    int res = 0;
    for(int i = 0;i < board.size();i++){
        if(board[i][n] != 0){
            res = board[i][n];
            board[i][n] = 0;
            break;}
    } //for문 close
    return res;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> doll; //인형 바구니
    int n = 0; //잡은 인형
  
    for(int i = 0;i < moves.size();i++){
        n = pick_up(moves[i]-1, board);
        if(n == 0) continue; //비어있는 칸
        
        if(!doll.empty()){
            if(doll.top() == n){
                doll.pop();
                answer+= 2;}
            else doll.push(n);
        }
        else doll.push(n);
        
    } //for문 close
    return answer;
}