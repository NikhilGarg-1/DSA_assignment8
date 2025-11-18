#include <iostream>
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

Node* searchRec(Node* root,int x){
    if(!root || root->data==x) return root;
    if(x < root->data) return searchRec(root->left,x);
    return searchRec(root->right,x);
}

Node* searchNonRec(Node* root,int x){
    while(root){
        if(root->data==x) return root;
        if(x < root->data) root=root->left;
        else root=root->right;
    }
    return 0;
}

Node* findMin(Node* root){
    while(root && root->left) root=root->left;
    return root;
}

Node* findMax(Node* root){
    while(root && root->right) root=root->right;
    return root;
}

Node* inorderSuccessor(Node* root,int x){
    Node* curr=root;
    Node* succ=0;
    while(curr){
        if(x < curr->data){
            succ=curr;
            curr=curr->left;
        } else curr=curr->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root,int x){
    Node* curr=root;
    Node* pred=0;
    while(curr){
        if(x > curr->data){
            pred=curr;
            curr=curr->right;
        } else curr=curr->left;
    }
    return pred;
}

int main(){
    Node* root=0;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }
    
    int key;
    cin>>key;

    Node* r1=searchRec(root,key);
    if(r1) cout<<"Found Rec\n"; else cout<<"Not Found Rec\n";
    
    Node* r2=searchNonRec(root,key);
    if(r2) cout<<"Found NonRec\n"; else cout<<"Not Found NonRec\n";

    Node* mn=findMin(root);
    Node* mx=findMax(root);
    cout<<"Min "<<mn->data<<"\n";
    cout<<"Max "<<mx->data<<"\n";

    Node* succ=inorderSuccessor(root,key);
    if(succ) cout<<"Successor "<<succ->data<<"\n"; else cout<<"No Successor\n";

    Node* pred=inorderPredecessor(root,key);
    if(pred) cout<<"Predecessor "<<pred->data<<"\n"; else cout<<"No Predecessor\n";
}
