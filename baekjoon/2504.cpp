#include <iostream>
#include <deque>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

stack<char> bracket;
deque<int> nums;
int small = 0; //여는 소괄호의 개수
int large = 0; //여는 대괄호의 개수


void mul(){
    int s = nums.size();
    //중첩된 괄호가 있으면 곱해야 한다
    if(!bracket.empty()){
        if(small > 0) nums[s-1] *= pow(2, small);
        if(large > 0) nums[s-1] *= pow(3, large);
    }
    bracket.push('n');
}


int main(){
    string str; cin >> str;
    int s = str.size();
    char c, tmp;
    int flag = 1; //0은 오류, 1은 성공
    char cflag; //소괄호면 s, 대괄호면 l
    
    for(int i = 0;i < s;i++){
        if(flag == 0) break;
        c = str[i];
        
        //여는 괄호
        if(c == '('){
            small++;
            bracket.push(c);
            flag = 1;
        }
        else if(c == '['){
            large++;
            bracket.push(c);
            flag = 1;
        }
        //여는 괄호 끝
        
        //닫는 괄호
        else{
            cflag = (c == ')') ? 's':'l';
            //괄호 열기 전에 닫으면 에러
            if(bracket.empty()){
                flag = 0;
                break;
            }
            
            int ncnt = 0;
            flag = 0; //정상 실행을 확인하기 위해 0으로 초기화
            while(!bracket.empty()){
                //여는 괄호와의 사이에 n(숫자)가 몇개 있는가?
                char tmp = bracket.top();
                bracket.pop();
                if(tmp == 'n') ncnt++;
                
                //소괄호면
                else if(tmp == '(' && cflag == 's'){
                    small--;
                    //사이에 숫자가 없었다면 삽입
                    if(ncnt == 0){
                        nums.push_back(2);
                        mul();
                    }
                    flag = 1; //정상적으로 작업 완료
                    break;
                }
                
                //대괄호면
                else if(tmp == '[' && cflag == 'l'){
                    large--;
                    if(ncnt == 0){
                        nums.push_back(3);
                        mul();
                    }
                    flag = 1; //정상적으로 작업 완료
                    break;
                }
				//해당 부분이 없으면 97%에서 오답 발생! 반례는 모르겠다.
                else break;
            }
            //뺀 숫자가 있다면 다시 넣어준다
            for(int i = 0;i < ncnt;i++)
                bracket.push('n');
        }
        //닫는 괄호 끝
    }
    
    if(small > 0 || large > 0) flag = 0;
    
    if(flag == 0) printf("0");
    else{
        int sum = 0;
        for(int i = 0;i < nums.size();i++)
            sum += nums[i];
        printf("%d", sum);
    }
}