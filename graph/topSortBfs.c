
 // Online C++ compiler to run C++ program online
 #include <iostream>
 #include<unordered_map>
 #include<stack>
 #include<map>
 #include<queue>
 #include<list>
 using namespace std;
 
 
 
 class Graph{
     public:
     unordered_map<int,list<int>>adj;
     
     
     void addEdge(int u,int v,bool direction){
         if(direction==1){
             adj[u].push_back(v);
         }
         else{
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
     }
     void printadjList(){
         for(auto i:adj){
             cout<<i.first<<":{";
             for(auto j:i.second){
                 cout<<j<<",";
             }
             cout<<"}"<<endl;
         }
     }
     void topSortBfs(int n,vector<int>& topOrder){
         queue<int>q;
         map<int,int>indegree;
         
         for(auto i:adj){
             for(auto nbr:i.second){
                 indegree[nbr]++;
             }
         }
         for(int node = 0;node<n;node++){
             if(indegree[node]==0){
                     q.push(node);
             }
         }
         while(!q.empty()){
             int frontNode = q.front();
             q.pop();
             topOrder.push_back(frontNode);
             
             for(auto nbr:adj[frontNode]){
                 indegree[nbr]--;
                 if(indegree[nbr]==0){
                     q.push(nbr);
                 }
             }
         }
     }
   
     
 };
 
 
 
 
 
 
 
 
 
 
 int main() {
     Graph g;
     g.addEdge(0,1,1);
     g.addEdge(1,2,1);
     g.addEdge(2,3,1);
     g.addEdge(3,5,1);
     g.addEdge(3,4,1);
     g.addEdge(4,6,1);
     g.addEdge(5,6,1);
     g.addEdge(6,7,1);
     g.printadjList();
     
     int n=8;
     vector<int>topOrder;
     g.topSortBfs(n,topOrder);
     cout<<"printing toporder:"<<endl;
     for(auto i :topOrder){
         cout<<i<<endl;
     }
     
     
     
     
     
     
     return 0;
 }     
       
       
       
 
 