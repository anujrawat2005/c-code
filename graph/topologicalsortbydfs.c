// Online C++ compiler to run C++ program online
#include <iostream>
#include<unordered_map>
#include<stack>
#include<map>
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
    void topSortdfs(int src,map<int,bool> &visited,stack<int> &st){
        visited[src] = true;
        
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                topSortdfs(nbr,visited,st);
            }
        }
        st.push(src);
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
    map<int, bool>visited;
    stack<int>st;
    for(int node = 0;node<n;node++){
        if(!visited[node]){
            g.topSortdfs(node,visited,st);
        }
    }
    cout<<"printing  topological order:"<<endl;
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    
    
    
    
    
    
    return 0;
}