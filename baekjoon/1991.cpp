#include <iostream>
using namespace std;

struct Node{
    char left;
    char right;
};
struct Node arr[26];


void preorder(char c){
    if(c == '.') return;
    cout << c;
    preorder(arr[c].left);
    preorder(arr[c].right);
}

void inorder(char c){
    if(c == '.') return;
    inorder(arr[c].left);
    cout << c;
    inorder(arr[c].right);
}

void postorder(char c){
    if(c == '.') return;
    postorder(arr[c].left);
    postorder(arr[c].right);
    cout << c;
}


int main(){
    int n;
    cin >> n;
    
    for(int i = 0;i < n;i++){
        char a, b, c;
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }
    preorder('A'); cout << endl;
    inorder('A'); cout << endl;
    postorder('A');
    
}