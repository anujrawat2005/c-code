



bool checkcycle(int src,unordered_map<int,bool>&vis,int parent,vector<int>adj[]){
    vis[src] = true;
    for(auto nbr:adj[src]){
        if(!vis[nbr]){
            bool ans = checkcycle(nbr,vis,src,adj);
            if(ans==true){
                return true;
            }
        }
        else if(vis[nbr]==1 && nbr!=parent){
            return true;
        }
    }
    return false;
    
    
    bool iscycle(int v,vector<int> adj[]){
        unordered_map<int,bool>vis;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                int parent = -1;
                bool iscyclic = checkcycle(i,vis,parent,adj);
                if(iscycle==true){
                    return true;
                }
            }
        }
        return false;
    }


