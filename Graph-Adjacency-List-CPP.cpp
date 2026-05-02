#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<vector<int>>& adj_list, int u, int v){
    
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
    
}

void Display_list(vector<vector<int>>& adj_list, int V){
    
    for(int i=0; i<V; i++){
        
        cout<<i<<"-> ";
        
        for(int j=0; j<adj_list[i].size(); j++){
            
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
    
    for(int i=0; i<E; i++){
        
        int u {}, v {};
        cin>>u>>v;
        
        addEdge(adj_list, u, v);
        
    }
    
    Display_list(adj_list, V);
    
    return 0;
}