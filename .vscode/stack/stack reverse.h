#include <iostream>
#include<stack>
using namespace std;


int main() {
   string str = "Anujrawat";
   stack<char>st;
   
   for(int i =0;i<str.length();i++){
       char ch = str[i];
       st.push(ch);
   }
   cout<<endl;
   while(!st.empty()){
       cout<<st.top()<<" ";
       st.pop();
   }

    return 0;
}