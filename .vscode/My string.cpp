#include <iostream>
using namespace std;



class Node{
    public:
    int data;
    Node* next;
    
    Node(){
        this->next = NULL;
        
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
int getlength(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    return length;
}
void inserthead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head  = newNode;
    }
}

void inserttail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}
void insertposition(Node* &head,Node* &tail,int data,int position){
    int length = getlength(head);
    if(position==1){
        inserthead(head,tail,data);
    }
    else if(position==length+1){
        inserttail(head,tail,data);
    }
    else{
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node* curr = head;
        while(position!=1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}
void deletenode(Node* &head,Node* &tail,int position){
    if(head==NULL){
        return;
    }
    int len = getlength(head);
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if(position==len){
        Node* prev = head;
        while(prev->next!=tail){
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        while(position!=1){
            position--;
            prev= curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void printll(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}





int main() {
   
    Node* first = new Node(12);
    Node* second = new Node(190);
    Node* third = new Node(12);
    Node* head = first;
    Node* tail = third;
    
    first->next = second;
    second->next = third;
    
    inserthead(head,tail,23);
    inserttail(head,tail,89);
    insertposition(head,tail,122,2);
    printll(head);
    deletenode(head,tail,7);
    printll(head);

    return 0;
}




















