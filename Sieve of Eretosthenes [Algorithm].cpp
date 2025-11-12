#include<iostream>
#include<vector>

using namespace std;

//Sieve of Eretosthenes

vector<bool> sieve(int num){
    
    vector<bool>prime(num+1, true);
    
    prime[0] = prime [1] = false;
    
    for(int i=2; (long long)i*i<=num; i++){
        
        if(prime[i]){
            
            for(int j= i*i; j<=num; j += i) {
                prime[j] = false;
            }
            
        }
        
    }
    
    return prime;
    
}





int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cout<<"Please enter n to get prime numbers from zero(0) to n: ";
    cin>>n;
    
    vector<bool>prime_storage = sieve(n);
    
    cout<<"The Primes between 0 and "<<n<<" are:\n\n";
    
    for(int i =2; i<=n; i++){
    
        if(prime_storage[i]) {
            cout<<i<<"\n";
        }
    
    }
    return 0;
}