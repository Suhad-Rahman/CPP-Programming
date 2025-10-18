#include<iostream>

using namespace std;

int main(){
    
    
        
    cout<<"Enter 2 numbers for arithmetic operations: ";
    
    int x,y;
    
    //For faster input using cin instead of scanf
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>x>>y;
    
    int sum {x+y};
    int sub {x-y};
    int multi {x*y};
    int division {x/y};
    
    cout<<endl;
    
    cout<<"The Sum is= "<<sum<<endl<<"The Subtraction is= "<<sub<<endl;
    cout<<"The Multiplication is= "<<multi<<endl<<"The Division is= "<<division<<endl;
    
    
    
    return 0;
}