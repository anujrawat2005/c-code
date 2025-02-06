#include <iostream>
#include<stack>
using namespace std;


void solve(stack<int>st,int& pos,int& ans){
    if(pos==1){
        ans = st.top();
        return ;
    }
    pos--;
    int temp = st.top();
    st.pop();
    solve(st,pos,ans);
    st.push(temp);
}

int getMiddleElement(stack<int>&st){
    int size = st.size();
    if(st.empty()){
        cout<<"stack empty"<<endl;
        return -1;
    }
    else{
        int pos = 0;
        if(size&1){
            pos = size/2+1;
            
        }
        else{
            pos = size/2;
        }
        int ans = -1;
        solve(st,pos,ans);
        return ans;
        
    }
}






int main() {
 stack<int> st;
 st.push(12);
 st.push(18);
 st.push(49);
 st.push(67);
 st.push(78);
 int mid  = getMiddleElement(st);
 cout<<"MiddleElement"<<mid<<" ";

    return 0;
}