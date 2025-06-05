#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=right=nullptr;
    }
};
Node* insert(Node* root,int value){
    if(root == nullptr){
        return new Node(value);
    }
    if(value < root->data){
        root->left = insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
bool search(Node* root,int key){
    if(root==nullptr) return false;
    if(root->data == key) return true;
    if(key<root->data) return search(root->left,key);
    else
    {
         return search(root->right,key);
    }
}
Node* findMin(Node* node){
    while(node && node->left!=nullptr){
         node=node->left;
         return node;
    }

void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
