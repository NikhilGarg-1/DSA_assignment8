#include <iostream>
#include <limits.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){
    Node* t=new Node;
    t->data=x;
    t->left=t->right=0;
    return t;
}

Node* insert(Node* root,int x){
    if(!root) return newNode(x);
    if(x < root->data) root->left=insert(root->left,x);
    else root->right=insert(root->right,x);
    return root;
}

bool isBSTUtil(Node* root,long long minv,long long maxv){
    if(!root) return true;
    if(root->data <= minv || root->data >= maxv) return false;
    return isBSTUtil(root->left,minv,root->data) &&
           isBSTUtil(root->right,root->data,maxv);
}

bool isBST(Node* root){
    return isBSTUtil(root,LLONG_MIN,LLONG_MAX);
}

int main(){
    Node* root=0;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }
    if(isBST(root)) cout<<"BST";
    else cout<<"Not BST";
}
