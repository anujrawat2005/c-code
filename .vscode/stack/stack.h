#include <iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st,int &pos,int &ans){
    if(pos==1){
        ans = st.top();
        return;
    }
    pos--;
    int temp = st.top();
    st.pop();
    
    solve(st,pos,ans);
    st.push(temp);
}
int getmiddle(stack<int> &st){
    int size= st.size();
    if(st.empty()){
        cout<<"stack empty"<<endl;
        return -1;
    }
    else{
        int pos = 0;
        if(size & 1){
            pos = size/2 +1 ;
        }
        else{
            pos = size/2;
        }
        int ans = -1;
        solve(st,pos,ans);
        return ans;
    }
}

void insertbootom(stack<int> &st,int &element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    insertbootom(st,element);
    st.push(temp);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverse(st);
    insertbootom(st,temp);
}
int main() {
    stack<int>st;
    st.push(12);
    st.push(18);
    st.push(16);
    st.push(20);
    int element = 1234;
    //insertbootom(st,element);
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
        
    };

    return 0;
}
