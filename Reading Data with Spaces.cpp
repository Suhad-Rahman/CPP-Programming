#include<iostream>
#include<string>

int main(){
    int age;
    std::string full_name;
    
    std::cout<<"Please enter your full name: ";
    
    //to read the input with spaces
    std::getline(std::cin,full_name);
    
    std::cout<<"Enter your age: ";
    std::cin>>age;
    
    std::cout<< "Hello "<<full_name<<"! You are "<<age<<" years old."<<std::endl;
    
    
    
    
    return 0;
}