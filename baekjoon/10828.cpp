#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<int> s;
    string str;
    int n, tmp;
    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> str;
        if(str == "push"){
            cin >> tmp;
            s.push(tmp);
        }
        else if(str == "pop"){
            if(s.empty()) cout << -1 << endl;
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(str == "size")
            cout << s.size() << endl;
        else if(str == "empty")
            cout << s.empty() << endl;
        else{ //top
            if(s.empty()) cout << -1 << endl;
            else cout << s.top() << endl;
        }
    }
}