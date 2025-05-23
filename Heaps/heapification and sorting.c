// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;



void heapify(int *arr, int n, int index) {
  int leftIndex = 2*index;
  int rightIndex = 2*index+1;
  int largestKaIndex = index;

  //teno me se max lao 
  if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]) {
    largestKaIndex = leftIndex;
  }
  if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]) {
    largestKaIndex = rightIndex;
  }
  //after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3 
  if(index != largestKaIndex) {
    swap(arr[index], arr[largestKaIndex]);
    //ab recursion sambhal lega
    index = largestKaIndex;
    heapify(arr, n, index);
  }
}

void buildHeap(int arr[], int n) {
  for(int index = n/2; index>0; index--) {
    heapify(arr, n, index);
  }
}

void heapSort(int arr[], int n) {
  while(n != 1 ) {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr,n,1);
  }
}


int main() {
    int arr[] = {-1,35,10,15,20,25,12};
    int n = 6;
    buildHeap(arr,6);
    
    cout<<"Printing the heap"<<endl;
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,n);
     cout<<"Printing the heap"<<endl;
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    


    return 0;
}


