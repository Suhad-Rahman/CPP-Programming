//shortest path using BFS (Unweighted)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void addEdge(vector<vector<int>>& adj_list, int u, int v){
    
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
    
}

void BFS_Shortest_path(vector<vector<int>>& adj_list, int source){
    
    int V = adj_list.size();
    
    vector<bool>visited(V, false);
    vector<int>parent(V, -1);
    vector<int>distance(V, -1);
    
    queue<int>Q;
    
    visited[source] = true;
    distance[source] = 0;
    
    Q.push(source);
    
    while(!Q.empty()){
        
        int current = Q.front();
        Q.pop();
        
        for(int neighbor : adj_list[current]){
            
            if(!visited[neighbor]){
                
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                parent[neighbor] = current;
                Q.push(neighbor);
                
            }
        }
    }
    
    cout<<"\n\nShortest distance from source node "<<source<<" : ";
    
    for(int i=0; i<V; i++){
        
        cout<<source<<" -> "<<i<<" : ";
        
        if(distance[i] == -1) {
            cout<<"Unreachable\n";
        }
        
        else{
            cout<<distance[i]<<" hops\n";
        }
    }
    
    cout<<"\n\nPath from source node -->\n";
    
    for(int i=0; i<V; i++){
        
        cout<<source<<" -> "<<i<<" : ";
        
        if(distance[i] == -1){
            cout<<"Unreachable\n";
            continue;
        }
        
        vector<int>path;
        
        for(int node = i; node != -1; node = parent[node]){
            
            path.push_back(node);
            
        }
        
        for(int j= path.size() - 1; j>=0; j--){
            cout<<path[j]<<(j==0 ? "\n" : " --> ");
        }
        
    }
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V {}, E {};
    cout<<"Please enter the number of Vertices & Edges: ";
    cin>>V>>E;
    
    vector<vector<int>>adj_list(V);
    
    cout<<"\nPlease enter the Edges: ";
    
    for(int i=0; i<E; i++){
        
        int u {}, v {};
        cin>>u>>v;
        
        addEdge(adj_list, u, v);
        
    }
    
    cout<<"Please enter the source node: ";
    int source {};
    cin>>source;
    
    BFS_Shortest_path(adj_list, source);
    
    return 0;
}