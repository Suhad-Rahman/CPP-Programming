//Euclid's Algorithm || Euclidian Algorithm

#include<iostream>
#include<algorithm>             //to use __gcd built in function

using namespace std;

int GCD(int a, int b) {
    while(b!=0) {
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main() {
    
    int n1, n2,gcd;
    
    cout<<"Enter two number to evaluate GCD(Greatest Common Divisor): ";
    cin>>n1>>n2;
    
    
    //GCD using user defined function
    
    gcd= GCD(n1, n2);
    cout<<"GCD("<<n1<<", "<<n2<<")= "<<gcd<<endl<<endl;
    
    //GCD using built in function
    
    cout<<__gcd(n1,n2)<<endl<<endl;
    
    //To evaluate LCM
    
    cout<<"LCM("<<n1<<", "<<n2<<")= "<<n1*n2/gcd<<endl;
    
    return 0;
}