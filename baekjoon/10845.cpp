#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    queue<int> q;
    string str;
    int n, tmp;
    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> str;
        if(str == "push"){
            cin >> tmp;
            q.push(tmp);
        }
        else if(str == "pop"){
            if(q.empty()) cout << -1 << endl;
            else{
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if(str == "size")
            cout << q.size() << endl;
        else if(str == "empty")
            cout << q.empty() << endl;
        else if(str == "front"){
            if(q.empty()) cout << -1 << endl;
            else cout << q.front() << endl;
        }
        else{
            if(q.empty()) cout << -1 << endl;
            else cout << q.back() << endl;
        }
    }
}