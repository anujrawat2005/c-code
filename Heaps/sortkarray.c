// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;



class Info{
    public:
    int data;
    int rowindex;
    int colindex;
    Info(int a,int b,int c){
        this->data = a;
        this->rowindex = b;
        this->colindex = c;
    }
};
class Compare{
    public:
    bool operator()(Info *a,Info *b){
        return a->data> b->data;
    }
};

void mergeSortarray(int arr[][4],int n,int k,vector<int> &ans){
    priority_queue<Info*,vector<Info*>,Compare> pq;
    
    for(int row = 0; row<k;row++){
        int element  = arr[row][0];
        Info* temp = new Info(element,row,0);
        pq.push(temp);
    }
    
    while(!pq.empty()){
        Info* temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowindex;
        int topCol = temp->colindex;
        
        ans.push_back(topData);
        if(topCol+1<n){
            Info* newInfo = new Info(arr[topRow][topCol+1],topRow,topCol+1);
            pq.push(newInfo);
        }
    }
}






int main() {
    int arr[4][3] = {
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };
    int n = 4;
    int k = 3;
    vector<int> ans;
    mergeSortArray(arr,n,k,ans);
    cout<<"printing array"<<endl;
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
 

    return 0;
}




