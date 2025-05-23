// Online C++ compiler to run C++ program online
#include <iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<limits.h>
using namespace std;


class Graph{
    public:
    unordered_map<int,list<pair<char,int>>>adjList;
    
    void addEdge(char u,char v,int wt,bool direction){
        if(direction==0){
            adjList[v].push_back({v,wt});
            adjList[u].push_back({u,wt});
        }
        else{
            adjList[v].push_back({v,wt});
        }
    }
    void printAdjList(){
        for(auto i :adjList){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"{"<<j.first<<","<<j.second<<"},";
            }
            cout<<endl;
        }
    }
    
    void bellmanford(int n,char src){
        vector<int>dist(n,INT_MAX);
        dist[src-'A']= 0;
        for(int i =1;i<n;i++){
            for(auto a:adjList){
                for(auto b :a.second){
                    char u = a.first;
                    char v = b.first;
                    int wt = b.second;
                    if(dist[u-'A']!= INT_MAX && dist[u-'A']+ wt<dist[v-'A']){
                        dist[v-'A'] = dist[u-'A']+wt;
                    }
                }
            }
        }
        bool anyUpdate = false;
        for(auto a :adjList){
            for(auto b :a.second){
                char  u =a.first;
                char v = b.first;
                int wt= b.second;
                if(dist[u-'A']!=INT_MAX && dist[u-'A']+wt<dist[v-'A']){
                    anyUpdate = true;
                    break;
                    dist[v-'A'] = dist[u-'A']+wt;
                }
            }
        }
        if(anyUpdate==true){
            cout<<"Negative cycle present"<<endl;
        }
        else{
            cout<<"No negative cycle present"<<endl;
            cout<<"Printing distance array"<<endl;
            for(auto i : dist){
                cout<<i<<",";
            }
        }
        cout<<endl;
    }
};



#include <iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std; 



class Graph{
    public:
    unordered_map<int,<list<pair<char,int>>>adjList;
    void addEdge(char u,char v,int wt,bool direction){
        if(direction==0){
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else{
            adjList[u].push_back({v,wt});
        }
    }
    void printAdjList(){
        for(auto i:adjList){
            cout<<i.first<<"->";
            for(auto j :i.second){
                cout<<"{"<<j.first<<","<<j.second<<"},";
            }
            cout<<endl;
        }
    }
    void fldWarshal(int n){
        vector<vector<int>> dist(n,vector<int>(n,1e9))){
            for(int i = 0;i<n;i++){
                dist[i][i]=0 ;
                
            }
            for(auto a :adjList){
                for(auto b:a.second){
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    dist[u][v] = wt;
                }
            }
            for(int helper = 0;helper<n;helper++){
                for(int src = 0;src<n;src++){
                    for(int dest = 0;dest<n;dest++){
                        dest[src][dest] = min(dist[src][dest],dist[src][helper]+dist[helper][dist]);
                    }
                }
            }
            for(int i =0;i<n;i++){
                for(int j = 0;j<n;j++){
                    cout<<dist[i][j]<<" ";
                }
                cout<<endl;
                
            }
            
        }
        
        
    }
};


int main() {
    

    return 0;
}














































int main() {
    
    Graph g;
    g.addEdge('A','B',-1,1);
    g.addEdge('A','E',4,1);


    return 0;
}




