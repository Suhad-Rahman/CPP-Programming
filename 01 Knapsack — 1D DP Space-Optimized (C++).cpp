//1D Knapsack [when Tracing back is not required]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(int n, int cap, vector<int>& wt, vector<int>& val){
    
    vector<int>dp(cap+1, 0);
    
    for(int i=0; i<n; i++){
        
        for(int j=cap; j>=wt[i]; j--){
            
            dp[j] = max(dp[j], dp[j-wt[i]]+val[i]);
            
        }
        
    }
    
    return dp[cap];
}

int main() {
    
    int n {}, capacity {};
    cin>>n>>capacity;
    
    vector<int>wt(n), val(n);
    
    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }
    
    cout<<knapsack(n, capacity, wt, val);
    
    return 0;
}