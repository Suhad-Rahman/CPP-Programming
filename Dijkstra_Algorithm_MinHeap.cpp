#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int>>>& adj, int src){
    
    int V = adj.size();
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int>dist(V, INT_MAX);
    
    dist[src] = 0;
    pq.emplace(0, src);
    
    while(!pq.empty()){
        
        auto top = pq.top();
        pq.pop();
        
        int d = top.first;
        int u = top.second;
        
        if(d < dist[u]){
            continue;
        }
        
        for(auto &neighbors : adj[u]){
            
            int v = neighbors.first;
            int w = neighbors.second;
            
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
            
        }
        
    }
    return dist;
}

void AddEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int wt){
    
    //For undirected graph
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int node {}, edge {};
    cout<<"Enter the number of Nodes & Edges: ";
    cin>>node>>edge;
    
    vector<vector<pair<int, int>>> adj(node);
    
    cout<<"\nEnter the from node --> to node & weight of the edge[Format -> 0 1 4]: \n";
    
    for(int i=0; i<edge; i++){
        
        int u, v, wt;
        cin>>u>>v>>wt;
        
        AddEdge(adj, u, v, wt);
        
    }
    
    cout<<"\nEnter the source node: ";
    int src {};
    cin>>src;
    
    vector<int>answer = Dijkstra(adj, src);
    
    cout<<"\n\n\n";
    
    for(int x : answer){
        cout<<x<<" ";
    }
    
    return 0;
}