#include<iostream>
#include<vector>

using namespace std;

void AddEdge(vector<vector<int>>& adj_list, int u, int v){
    
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
    
}

void DFS(vector<vector<int>>& adj_list, int node, vector<bool>& visited){
    
    visited[node] = true;
    cout<<node<<" ";
    
    for(int neighbor : adj_list[node]){
        
        if(!visited[neighbor]){
            
            DFS(adj_list, neighbor, visited);
            
        }
        
    }
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V {};
    cin>>V;
    
    vector<vector<int>>adj_list(V+1, vector<int>());
    vector<bool>visited(V+1, false);
    
    for(int i = 0; i<V; i++){
        
        int u, v;
        cin>>u>>v;
        
        AddEdge(adj_list, u, v);
    }
    
    int node = 1;
    
    DFS(adj_list, node, visited);
    
    return 0;
}