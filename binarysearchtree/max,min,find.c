//include<stdio.h>
#include <iostream>
#include<queue>
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
 
 void preorder(Node* root){
     if(root==NULL){
         return;
     }
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
 }
 void inorder(Node* root){
     if(root==NULL){
         return;
     }
     
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
 }
  void postorder(Node* root){
     if(root==NULL){
         return;
     }
     
     postorder(root->left);
     
     postorder(root->right);
     cout<<root->data<<" ";
 }
 Node* MinValue(Node* root){
     if(root==NULL){
         return NULL;
         }
         Node* temp = root;
         while(temp->left!=NULL){
             temp = temp->left;
         }
         return temp;
 }
 Node* Maxvalue(Node* root){
     if(root==NULL){
         return NULL;
         }
         Node* temp = root;
         while(temp->right!=NULL){
             temp = temp->right;
         }
         return temp;
 }
    

bool Searchinbst(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    
    if(target>root->data){
        rightAns = Searchinbst(root->right,target);
    }
    else{
        leftAns = Searchinbst(root->right,target);
    }
    return leftAns || rightAns;
}

Node* deletebst(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node* child = root->left;
            delete root;
            return child;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* child = root->right;
            delete root;
            return child;
        }
        else{
            Node* maxi = maxvalue(root);
            root->data = maxi->data;
            root->left = deletebst(root->left,maxi->data);
            return root;
        }
    }
    else if(target<root->data){
        root->left = deletebst(root->left,target);
    }
    else{
        root->right = deletebst(root->right,target);
    }
    return root;
}













































int main() {
    Node* root = NULL;
    createbst(root);
    levelorder(root);
    
    cout<<"preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"inorder"<<endl;
    
    inorder(root);
    cout<<endl;
    cout<<"postorder"<<endl;

    postorder(root);
    
    cout<<endl;
    Node* minimum = MinValue(root);
    if(minimum==NULL){
        cout<<"there is no null"<<endl;
    }
    else{
        cout<<"minimum value is"<<minimum->data<<endl;
    }
    
    cout<<endl;
    Node* maximum = Maxvalue(root);
    if(maximum ==NULL){
        cout<<"there is no null"<<endl;
    }
    else{
        cout<<"maximum value is"<<maximum->data<<endl;
    }
    
    int t;
    cout<<"enter the target"<<endl;
    cin>>t;
    
    if(t!=-1){
        bool ans = Searchinbst(root,t);
        if(ans==true){
            cout<<"element found"<<endl;
        }
        else{
            cout<<"element not found"<<endl;
        }
        cout<<"enter the target"<<endl;
        cin>>t;
    }
    
    return 0;
}










