#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void Merge(vector<int>&arr, int lowerb, int mid, int upperb){
    
    int n1 = mid - lowerb + 1;
    int n2 = upperb - mid;
    
    
    
    vector<int>L (n1), R (n2);
    
    for(int i=0; i<n1; i++){
        L[i] = arr[lowerb+i];
    }
    
    for(int j=0; j<n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    
    int i {}, j {}, k=lowerb;
    
    while(i < n1 && j < n2){
        
        
        if(L[i] <= R[j]){
            
            arr[k] = L[i];
            i++;
            
        }
        
        else{
            
            arr[k] = R[j];
            j++;
            
        }
        
        k++;
        
    }
    
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2) {
        
        arr[k] = R[j];
        j++;
        k++;
        
    }
    
}


void MergeSort(vector<int>&arr, int lowerb, int upperb){
    
    if(lowerb >= upperb){
        return;
    }
    
    int mid = lowerb + (upperb - lowerb) / 2;
    
    MergeSort(arr, lowerb, mid);
    MergeSort(arr, mid+1, upperb);
    Merge(arr, lowerb, mid, upperb);
    
    
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int>arr;
    int n;
    
    cout<<"Enter the number of Elements: ";
    cin>>n;
    
    cout<<"Enter the Elements: ";
    
    for(int i=0; i<n; i++){
        
        int input;
        cin >> input;
        arr.push_back(input);
        
    }
    
    cout<<"After Merge Sort\n__________________________________\n";
    
    MergeSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    
    return 0;
}