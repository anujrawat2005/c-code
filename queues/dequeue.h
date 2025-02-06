// Online C++ compiler to run C++ program online
#include <iostream>
#include<deque>
using namespace std;


class dequeue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    dequeue(int size){
        arr = new int[size];
        this->size = size;
        front= -1;
        rear = -1;
    }
    void pushfront(int val){
        if((front==0 && rear==size-1)||(rear==front-1)){
            cout<<"overflow"<<endl;
            return;
        }
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[front] = val;
        }
        else if(front==0 &&rear!=size-1){
            front=size-1;arr[front] = val;
        }
        else{
            front--;
            arr[front] = val;
        }
    }
    void pushback(int val){
        if((front==0 && rear==size-1)||(rear==front-1)){
            cout<<"overflow"<<endl;
            return;
        }
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else if(rear==size-1& front!=0){
            rear=0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }
    void popfront(){
        if(rear==-1&&front==-1){
            cout<<"underflow"<<endl;
            return;
        }
        else if(front==size-1){
            arr[front]  = -1;
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
    void popback(){
        if(front==-1&&rear==-1){
            cout<<"underflow"<<endl;
            return;
        }
        else if(front==rear){
            arr[rear] = -1;
            front=-1;
            rear = -1;
        }
        else if(rear==0){
            arr[rear] = -1;
            rear = size-1;
        }
        else{
            arr[rear] = -1;
            rear--;
        }
    }
    void print(){
        for(int i =0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};













int main() {
    dequeue  dq(5);
    dq.pushback(89);
    dq.print();
    

    return 0;
}
