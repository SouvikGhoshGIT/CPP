#include<iostream>
using namespace std;
template<class T>
T myT(T a,T b){
std::cout << typeid(a).name() <<std::endl;
return (a>b)?a:b;
}

int main(){
    myT(2,3);
    myT("A","B");
     myT('A','B');
}