
#include <iostream>
using namespace std;




class Heap{
    public:
    int capacity;
    int *arr;
    int size;
    Heap(int capacity){
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }
    void insert(int val){
        if(size==capacity){
            cout<<"Heap overflow"<<endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;
        
        while(index>1){
            int parentindex = index/2;
            if(arr[index]>arr[parentindex]){
                swap(arr[index],arr[parentindex]);
                index = parentindex;
            }
            else{
                break;
            }
        }
  
    }
    void printheap(){
        for(int i =0;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
    
    int deleteheap(){
        int answer = arr[1];
        arr[1] = arr[size];
        size--;
        int index= 1;
        while(index<=size){
            int leftindex = 2*index;
            int rightindex = 2*index+1;
            int largestindex = index;
            
            if(leftindex<=size && arr[largestindex]<arr[leftindex]){
                largestindex = leftindex;
            }
            if(rightindex<=size && arr[largestindex]<arr[rightindex]){
                largestindex = rightindex;
            }
            if(index==largestindex){
                break;
            }
            else{
                swap(arr[index],arr[largestindex]);
                index= largestindex;
            }
        }
        return answer;
    }
    
    
};








int main() {
    Heap h(20);
    h.insert(1);
    h.insert(20);
    h.insert(35);
    h.insert(40);
    cout<<"printing the heap"<<endl;
    h.printheap();
    
    int ans = h.deleteheap();
    cout<<"ans:"<<ans<<endl;
      cout<<"printing the heap"<<endl;
    h.printheap();
   

    return 0;
}

