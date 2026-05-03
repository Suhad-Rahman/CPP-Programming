//BFS for Directed + Disconnected Graph
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>BFS(vector<vector<int>>& adj_list){
    
    int V = adj_list.size();
    vector<bool>visited(V, false);
    queue<int>Q;
    
    vector<int>result;
    
    for(int i=0; i<V; i++){
        
        if(!visited[i]){
            
            visited[i] = true;
            Q.push(i);
            
            while(!Q.empty()){
                
                int current_node = Q.front();
                Q.pop();
                
                result.push_back(current_node);
                    
                for(int neighbor : adj_list[current_node]){
                        
                    if(!visited[neighbor]){
                        
                        visited[neighbor] = true;
                        Q.push(neighbor);
                        
                    }
                }
            }
            
        }
        
    }
    return result;
}

void addEdge(vector<vector<int>>& adj_list, int u, int v){
    
    adj_list[u].push_back(v);
    
}

void DisplayList(vector<vector<int>>& adj_list, int V){
    
    for(int i=0; i<V; i++){
        
        cout<<i<<"-> ";
        
        for(int j = 0; j<adj_list[i].size(); j++){
            
            cout<<adj_list[i][j]<<" ";
            
        }
        cout<<"\n";
    }
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V {}, E {};
    cin>>V>>E;
    
    vector<vector<int>>adj_list(V);
    vector<int>result;
    
    for(int i=0; i<E; i++){
        
        int u {}, v {};
        cin>>u>>v;
        
        addEdge(adj_list, u, v);
        
    }
    
    DisplayList(adj_list, V);
    
    result = BFS(adj_list);
    
    for(int x : result){
        
        cout<<x<<" ";
        
    }
    
    return 0;
}