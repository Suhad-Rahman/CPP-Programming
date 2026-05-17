#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> knapsack(int n, int cap, vector<int>& wt, vector<int>& val){
    
    vector<vector<int>>dp(n+1, vector<int>(cap+1, 0));
    
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=cap; j++){
            
            if(wt[i-1] <= j){
                
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
                
            }
            
            else{
                dp[i][j] = dp[i-1][j];
            }
            
        }
        
    }
    
    return dp;
}

vector<int>TraceBack(int n, int cap, vector<int>& wt, vector<vector<int>>& dp_table){
    
    int j = cap;
    vector<int>result;
    
    for(int i=n; i>=1; i--){
        
        if(dp_table[i][j] != dp_table[i-1][j]){
            
            result.push_back(i);
            j -= wt[i-1];
        }
        
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n {}, capacity {};
    cin>>n>>capacity;
    
    vector<int>wt(n), val(n);
    
    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }
    
    vector<vector<int>> dp_table = knapsack(n, capacity, wt, val);
    
    vector<int>items_taken = TraceBack(n, capacity, wt, dp_table);
    
    cout<<"Maximum Profit: "<<dp_table[n][capacity]<<"\n\n";
    cout<<"Items taken -> ";
    
    for(int i=0; i<items_taken.size(); i++){
        cout<<items_taken[i]<<" ";
    }
    
    return 0;
}