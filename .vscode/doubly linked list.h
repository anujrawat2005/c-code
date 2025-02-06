#include <iostream>
using namespace std;



class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};



void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
int findlength(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    return length;
}
void inserthead(Node* &head, Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void inserttail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head=  newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void deleteNode(Node* &head,Node* &tail,int position){
    if(head==NULL){
        return;
    }
    if(head==tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    int len = findlength(head);
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position==len){
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position!=1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;
        prevNode ->next = nextNode;
        currNode->next = NULL;
        currNode -> next = NULL;
        nextNode->prev = prevNode;
        delete  currNode;
    }
}
void insertposition(Node* &head,Node* &tail,int data,int position){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        int len = findlength(head);
        if(position==1){
            inserthead(head,tail,data);
        }
        else if(position==len+1){
            inserttail(head,tail,data);
        }
        else{
            Node* newNode = new Node(data);
            Node* prevNode = NULL;
            Node* currNode = head;
            while(position!=1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void addone(Node* &head){
    head = reverse(head);
    int carry = 1;
    Node* temp = head;
    while(temp->next!=NULL){
        int totalsum = temp->data+carry;
        int digit = totalsum % 10;
        carry = totalsum / 10;
        temp->data = digit;
        temp = temp->next;
}
if(carry!=0){
    int totalsum = temp->data+carry;
    int digit = totalsum % 10;
    carry= totalsum/10;
    temp->data = digit;
    if(carry!=0){
        Node* newNode = new Node(carry);
        temp->next = newNode;
    }
}
      
    head = reverse(head);
    
}



int main() {
    Node* head = NULL;
    Node* tail = NULL;
    inserthead(head,tail,1);
    inserthead(head,tail,1);
    inserthead(head,tail,1);
    inserthead(head,tail,1);
    addone(head);
    
    print(head);
    

    return 0;
}



