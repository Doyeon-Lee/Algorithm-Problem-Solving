#include <iostream>
#include <string>
#include <stack>
#include <queue>
#define ABS_MAX 1e9
using namespace std;
typedef long long ll;

bool f = false;

void num_f(stack<ll> &st, queue<ll> &q){
    ll a = q.front();
    st.push(a);
    q.pop();
}

void pop_f(stack<ll> &st){
    if(st.empty()) f = true;
    else st.pop();
}

void inv_f(stack<ll> &st){
    if(st.empty()) f = true;
    else{
        ll a = st.top();
        st.pop();
        st.push(-a);
    }
}

void dup_f(stack<ll> &st){
    if(st.empty()) f = true;
    else{
        ll a = st.top();
        st.push(a);
    }
}

void swp_f(stack<ll> &st){
    if(st.size() < 2) f = true;
    else{
        ll a, b;
        a = st.top(); st.pop();
        b = st.top(); st.pop();
        st.push(a);
        st.push(b);
    }
}

void add_f(stack<ll> &st){
    if(st.size() < 2) f = true;
    else{
        ll a, b, res;
        a = st.top(); st.pop();
        b = st.top(); st.pop();
        res = a+b;
        if(abs(res) > ABS_MAX) f = true;
        else st.push(res);
    }
}

void sub_f(stack<ll> &st){
    if(st.size() < 2) f = true;
    else{
        ll a, b, res;
        a = st.top(); st.pop();
        b = st.top(); st.pop();
        res = b-a;
        if(abs(res) > ABS_MAX) f = true;
        else st.push(b-a);
    }    
}

void mul_f(stack<ll> &st){
    if(st.size() < 2) f = true;
    else{
        ll a, b, res;
        a = st.top(); st.pop();
        b = st.top(); st.pop();
        res = a*b;
        if(abs(res) > ABS_MAX) f = true;
        else st.push(b*a);
    }    
}

void div_f(stack<ll> &st){
    if(st.size() < 2) f = true;
    else{
        ll a, b;
        a = st.top(); st.pop();
        b = st.top(); st.pop();
        if(a == 0) f = true;
        else st.push(b/a);
    }
}

void mod_f(stack<ll> &st){
    if(st.size() < 2) f = true;
    else{
        ll a, b;
        a = st.top(); st.pop();
        b = st.top(); st.pop();
        if(a == 0) f = true;
        else st.push(b%a);
    }    
}

void calc(string &inst, stack<ll> &st, queue<ll> &q){
    int s = inst.length()/3;
    f = false;
    for(int i = 0;i < s;i++){
        if(f) break;
        
        string buf = inst.substr(i*3, 3);
        if(buf == "NUM") num_f(st, q);
        else if(buf == "POP") pop_f(st);
        else if(buf == "INV") inv_f(st);
        else if(buf == "DUP") dup_f(st);
        else if(buf == "SWP") swp_f(st);
        else if(buf == "ADD") add_f(st);
        else if(buf == "SUB") sub_f(st);
        else if(buf == "MUL") mul_f(st);
        else if(buf == "DIV") div_f(st);
        else if(buf == "MOD") mod_f(st);
    }
}

int main(){
    string str, inst = ""; //instruction
    int cases; //명령어를 반복할 횟수
    ll tmp;
    stack<ll> st;
    queue<ll> q, q2; //NUM 명령어로 추가되는 숫자들
    
    while(1){
        cin >> str;
        if(str == "QUIT") break;
        else if(str == "END"){
            cin >> cases; //숫자가 몇 개인가
            for(int i = 0;i < cases;i++){
                q2 = q;
                cin >> tmp;
                st.push(tmp);
                calc(inst, st, q2);
                if(st.size() != 1 || f) cout << "ERROR\n";
                else cout << st.top() << endl;
                
                st = {}; //비우기(17버전 부터 가능?)
            }
            inst = ""; //초기화
            cout << endl;
            while(!q.empty()) q.pop();
        } //END가 나오면
        else if(str == "NUM"){
            cin >> tmp;
            q.push(tmp);
            inst += str;
        }
        else inst += str; //명령어 순서 누적
    }
}