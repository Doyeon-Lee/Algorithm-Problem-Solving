#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[1] == b[1]) //y좌표가 같다면
        return a[0] < b[0];
    else return a[1] > b[1]; //y좌표가 큰 놈이 먼저 온다
}

struct Node{
    Node(vector<int> &);
    int x, y, n;
    Node *leftChild = 0;
    Node *rightChild = NULL;
};

Node::Node(vector<int> &v){
    x = v[0];
    y = v[1];
    n = v[2];
}

class Tree{
public:
    Tree(){root = 0;}
    void Insert(Node *n){Insert(root, n);}
    void Preorder(vector<int> &v){Preorder(root, v);}
    void Postorder(vector<int> &v){Postorder(root, v);}
private:
    void Insert(Node* &, Node *);
    void Preorder(Node *, vector<int> &);
    void Postorder(Node *, vector<int> &);
    
    Node *root;
};

void Tree::Insert(Node* &ptr, Node *n){
    if(ptr == 0) ptr = n;
    else if(n->x < ptr->x) Insert(ptr->leftChild, n);
    else Insert(ptr->rightChild, n);
}

void Tree::Preorder(Node *curNode, vector<int> &v){
    if(curNode){
        v.push_back(curNode->n);
        Preorder(curNode->leftChild, v);
        Preorder(curNode->rightChild, v);
    }
}

void Tree::Postorder(Node *curNode, vector<int> &v){
    if(curNode){
        Postorder(curNode->leftChild, v);
        Postorder(curNode->rightChild, v);
        v.push_back(curNode->n);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int s = nodeinfo.size();
    
    //x, y, n 저장 후 y & x 크기가 큰 순서대로 정렬
    for(int i = 0;i < s;i++)
        nodeinfo[i].push_back(i+1);
 
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    //트리 형성
    Tree T; 
    Node *curNode;

    for(int i = 0;i < s;i++){
        curNode = new Node(nodeinfo[i]);    
        T.Insert(curNode);
    }
    
    //Preorder
    vector<int> v;
    T.Preorder(v);
    answer.push_back(v);
    
    //Postorder
    v.clear();
    T.Postorder(v);
    answer.push_back(v);
    
    return answer;
}