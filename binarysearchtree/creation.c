#include<stdio.h>
//#include <iostream>
//#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* Insertintobst(Node* root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(data>root->data){
        root->right = Insertintobst(root->right,data);
    }
    else{
        root->left = Insertintobst(root->left,data);
    }
    return root;
}

void createbst(Node* &root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        root = Insertintobst(root,data);
        cout<<"enter the data"<<endl;
        cin>>data;
    }
    
}
 void levelorder(Node* root){
     queue<Node*>q;
     q.push(root);
     q.push(NULL);
     
     while(!q.empty()){
         Node* front = q.front();
         q.pop();
         
         if(front==NULL){
             cout<<endl;
             if(!q.empty()){
                 q.push(NULL);
             }
         }
         else{
             cout<<front->data<<" ";
             if(front->left!=NULL){
                 q.push(front->left);
             }
             if(front->right!=NULL){
                 q.push(front->right);
             }
             
         }
         
         
     }
 }







































int main() {
    Node* root = NULL;
    createbst(root);
    levelorder(root);
    
    return 0;
}

