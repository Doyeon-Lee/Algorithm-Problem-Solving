#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    
    Node(int v) : val(v), left(NULL), right(NULL){}
};


Node* insert(Node *root, Node *node){
    if(root == NULL) return node;
    else if(node->val <= root->val)
        root->left = insert(root->left, node);
    else
        root->right = insert(root->right, node);
    return root;
}

void postorder(Node *root){
    if(root->left != NULL) postorder(root->left);
    if(root->right != NULL) postorder(root->right);
    printf("%d\n", root->val);
}

int main(){
    int val;
    Node *root = NULL;
    
    while(scanf("%d", &val) != EOF){
        root = insert(root, new Node(val));
    }
    postorder(root);
}