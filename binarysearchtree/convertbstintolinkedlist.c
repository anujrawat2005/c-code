#include <iostream>
#include<queue>
using namespace std;




class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;""
    }
};

void levelorder(Node* root){
    queue<Node*> q;
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

Node* bstfrominorder(int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);
    
    root->left = bstfrominorder(inorder,s,mid-1);
    root->right = bstfrominorder(inorder,mid+1,e);
    return root;
}

void convertbstintoDLL(Node* root,Node* &head){
    if(root==NULL){
        return ;
    }
    
    convertbstintoDLL(root->right,head);
    
    root->right = head;
    if(head!=NULL){
        head->left = root;
        head = root;
    }
    convertbstintoDLL(root->left,head);
}
void printlinkedlist(Node* head){
    Node* temp = head;
    cout<<"printing linked list:"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
        }
        cout<<endl;
}








int main() {
    int inorder[6] = {10,20,30,40,50,60};
    int size = 6;
    int start= 0;
    int end = size-1;
    Node* root = bstfrominorder(inorder,start,end);
    levelorder(root);
    Node* head= NULL;
    convertbstintoDLL(root,head);
    printlinkedlist(head);
  

    return 0;
}
















































































