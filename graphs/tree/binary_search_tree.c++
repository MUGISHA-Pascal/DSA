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
       
    }
    return node;
}
void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* deleteNode(Node* root,int key){
    if(root == nullptr) return root;
    if(key < root->data){
        root->left = deleteNode(root->left,key);
        }else if(key > root->data){
            root->right = deleteNode(root->right,key);
        }else{
            if(root->left==nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
             Node* temp = root->left;
             delete root;
             return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        return root;

}

int main(){
    Node* root = nullptr;
    root = insert(root,50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Search for 60: " << (search(root, 60) ? "Found" : "Not Found") << endl;

    root = deleteNode(root, 70);
    cout << "After deleting 70, inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}