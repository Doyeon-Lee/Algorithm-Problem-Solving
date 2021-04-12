#include <string>
#include <iostream>
using namespace std;

int solution(string name) { //왼쪽일 경우와 오른쪽일 경우 
    int answer = 0;
    int move = 0; //4가지 케이스에 대한 움직임의 개수
    int sub = 0;
    int AA = 0; //연속되어 A가 나오는 경우 그 갯수
    char c; //각 알파벳을 저장

    /*무조건 오른쪽으로 움직이는 경우*/
    for(int i = 0;i < name.length();i++){
        c = name[i];
        if(c == 'A') AA++; //A일 경우 개수 증가후 커서 이동
        else{
            sub = c - 'A';
            if(sub > 13) sub = 26 - sub; //Z로 거꾸로 가는게 빠른 경우
            move += sub;     
            AA = 0; //A가 아니면 초기화
        }
        move++; //커서 이동   
    }
    move = move - AA; //뒤쪽에 연속된 A가 있었다면 필요없는 움직임이었으므로 빼준다
    if(move == 0) return 0;
    else move--; //0이 아니면 마지막의 move++의 커서 이동은 없는 문자이므로 빼준다
    answer = move; //처음으로 구한 이동 횟수이므로 바로 answer에 저장해줌
    move = AA = 0; //변수 초기화


    /*무조건 왼쪽으로 움직이는 경우*/
    //첫 번째 문자를 먼저 처리해준 후 맨 뒤로 이동한다
    c = name[0];
    sub = c - 'A';
    if(sub > 13) sub = 26 - sub;
    move += sub;
    move++;

    for(int i = name.length()-1;i > 0;i--){
        c = name[i];
        if(c == 'A') AA++; //A일 경우 개수 증가후 커서 이동
        else{
            sub = c - 'A';
            if(sub > 13) sub = 26 - sub;
            move += sub;   
            AA = 0;
        }
        move++; //커서 이동   
    }
    move = move - AA;
    move--;
    answer = min(answer, move);
    move = AA = 0;    

    /*오른쪽으로 가다가 중간에 왼쪽으로 방향을 전환하는 경우*/
    int pos = 1; //방향을 전환한 위치; 첫 번째 위치에서 바로
    //방향을 전환할 경우 위와 같아지므로 두 번째 위치부터 시작한다
    int min_turn = 0; //각 pos마다 최소한의 횟수를 저장한다

    while(pos <= name.length()/2){ //문자열의 반 이상을 초과할 경우 비효율적임
        move = AA = 0;

        for(int i = 0;i <= pos;i++){ //pos만큼 오른쪽 이동 후 다시 pos만큼 첫 위치로 이동
            c = name[i];
            if(c != 'A'){
                sub = c - 'A';
                if(sub > 13) sub = 26 - sub;
                move += sub;
            }
            move++; //커서 이동
        } //for문 close
        move += pos; //오른쪽으로 이동한 만큼 다시 왼쪽으로 이동한다
        move--; //마지막은 필요 없는 이동임
        move++; //커서를 맨 뒤로 이동한다

        //pos위치까지 갔다왔으므로 pos+1까지 탐색한다
        for(int i = name.length()-1;i > pos;i--){
            c = name[i];
            if(c == 'A') AA++; //A일 경우 개수 증가후 커서 이동
            else{
                sub = c - 'A';
                if(sub > 13) sub = 26 - sub;
                move += sub;    
                AA = 0;
            }
            move++; //커서 이동   
        }
        move = move - AA; //연속된 A가 있었다면 빼준다
        move--;

        min_turn == 0 ? min_turn = move : min_turn = min(min_turn, move);
        pos++; //전환점의 위치를 하나 증가시킨다
    } //pos마다 모든 전환점을 반복함
    answer = min(answer, min_turn);

    /*왼쪽으로 갔다가 오른쪽으로 방향을 전환하는 경우*/
    pos = name.length()-1; //전환점은 맨 오른쪽부터 시작
    min_turn = 0; //초기화  

    while(pos >= name.length()/2){
        move = 0; AA = 0;

        //맨 처음 위치의 알파벳을 먼저 처리해준다
        c = name[0];
        sub = c - 'A';
        if(sub > 13) sub = 26 - sub;
        move += sub;
        move++;

        for(int i = name.length()-1;i >= pos;i--){
            c = name[i];
            if(c != 'A'){
                sub = c - 'A';
                if(sub > 13) sub = 26 - sub;
                move += sub;
            }
            move++; //커서 이동
        } //for문 close
        move += name.length()-pos; //이동한 칸만큼 더해준다. 다시 맨 앞 커서로 이동하는 것
        move--; //마지막은 필요없는 커서 이동
        move++; //이미 첫 알파벳은 처리해 주었으므로 두 번째로 이동

        //pos위치까지 갔다왔으므로 pos-1까지 탐색한다
        for(int i = 1;i < pos;i++){
            c = name[i];
            if(c == 'A') AA++; //A일 경우 개수 증가후 커서 이동
            else{
                sub = c - 'A';
                if(sub > 13) sub = 26 - sub;
                move += sub;     
                AA = 0;
            }
            move++; //커서 이동   
        }
        move = move - AA; //연속된 A가 있었다면 빼준다
        move--; //마지막 이동은 필요 없는 커서 이동

        min_turn == 0 ? min_turn = move : min_turn = min(min_turn, move);
        pos--; //전환점의 위치를 하나 감소시킨다
    } //pos마다 모든 전환점을 반복함
    answer = min(answer, min_turn);

    return answer;
}