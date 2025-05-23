// Online C++ compiler to run C++ program online
#include <iostream>
#include<unordered_map>
#include<list>
#include<map>
#include<vector>
#include<set>
#include<limits.h>
#include<stack>
using namespace std;





class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;
    void addEdge(int u,int v,int wt,bool direction){
        if(direction==1){
            adj[u].push_back({v,wt});
        }
        else{
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }
    void printadj(){
        for(auto i:adj){
            cout<<i.first<<":{";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<endl;
        }
    }
    
    void dijkestrashortestdistance(int n,int src,int dest){
        vector<int>dist(n+1,INT_MAX);
        
        set<pair<int,int>>st;
        
        st.insert({0,src});
        dist[src] = 0;
        
        while(!st.empty()){
            auto topElement = st.begin();
            pair<int,int>topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;
            st.erase(st.begin());
            
            for(pair<int,int>nbrPair:adj[topNode]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if(topDist+nbrDist<dist[nbrNode]){
                    auto previousEntry = st.find({dist[nbrNode],nbrNode});
                    if(previousEntry!=st.end()){
                        st.erase(previousEntry);
                    }
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        cout<<"shortest Distance from"<<src<<"Node to"<<dest<<"Node"
        <<dist[dest]<<endl;
    }
};















int main() {
    Graph g;
	g.addEdge(1,6,14,0);
	g.addEdge(1,3,9,0);
	g.addEdge(1,2,7,0);
	g.addEdge(2,3,10,0);
	g.addEdge(2,4,15,0);
	g.addEdge(3,4,11,0);
	g.addEdge(6,3,2,0);
	g.addEdge(6,5,9,0);
	g.addEdge(5,4,6,0);
  
  
    int n = 6;
    int src = 5;
    int dest = 2;
    g.dijkestrashortestdistance(n,src,dest);
    return 0;
}




