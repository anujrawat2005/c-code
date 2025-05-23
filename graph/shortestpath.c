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
    
    
    void shortestpathBfs(int src,int dest){
        queue<int> q;
        map<int,bool>visited;
        map<int,int>parent;
        
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr: adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
            }
        }
        vector<int>ans;
        while(dest!=-1){
            ans.push_back(dest);
            dest = parent[dest];
        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans){
            cout<<i<<" ";
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
    int src = 0;
    int dest = 3;
    g.shortestpathBfs(src,dest);
    
   
    
    
    
    
    
    
    return 0;
}     
      
      
      










