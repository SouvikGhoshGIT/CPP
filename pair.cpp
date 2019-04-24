#include<iostream>
#include<utility>
using namespace std;


pair<int,string> P;
int main(){
    cin >>P.first;
    cin>>P.second;
    cout <<P.first <<P.second <<"\n";
    pair<int,string> a= make_pair(2,"OK3");
    P.swap(a);
    cout <<P.first <<P.second <<"\n";

}
