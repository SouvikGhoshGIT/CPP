#include<iostream>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<ctime>

int fun(){
    return 3;
}

void pass_by_value(int x){

    x=30;
}

void pass_by_reference(int *p){

    *p=30;
}

void example(int);

void example(int a=10){

    std::cout << a << "\n";
}
//Default arguments are different from constant arguments as constant arguments can’t be changed whereas default arguments can be overwritten if required.
void exam(int const a=5){

    std::cout << a << "\n";


}
/*

Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances like:
1) If a function contains a loop. (for, while, do-while)
2) If a function contains static variables.
3) If a function is recursive.
4) If a function return type is other than void, and the return statement doesn’t exist in function body.
5) If a function contains switch or goto statement.


It is also possible to define the inline function inside the class. In fact, all the functions defined inside the class are implicitly inline. Thus, all the restrictions of inline functions are also applied here. If you need to explicitly declare inline function in the class then just declare the function inside the class and define it outside the class using inline keyword.
For example:

filter_none
edit
play_arrow

brightness_4
class S
{
public:
    inline int square(int s) // redundant use of inline
    {
        // this function is automatically inline
        // function body
    }
};

C++ compiler checks the argument types of inline functions and necessary conversions are performed correctly. Preprocessor macro is not capable for doing this. One other thing is that the macros are managed by preprocessor and inline functions are managed by C++ compiler.

Remember: It is true that all the functions defined inside the class are implicitly inline and C++ compiler will perform inline call of these functions, but C++ compiler cannot perform inlining if the function is virtual. The reason is call to a virtual function is resolved at runtime instead of compile time. Virtual means wait until runtime and inline means during compilation, if the compiler doesn’t know which function will be called, how it can perform inlining?

One other thing to remember is that it is only useful to make the function inline if the time spent during a function call is more compared to the function body execution time. An example where inline function has no effect at all:
*/

class inline_practice{

public:
    void show();
};

inline void inline_practice::show(){

std::cout <<"calling from inline fucntion \n";
}

void a(){
    std::cout << "From void function \n";
    return;
}

//A Void function can return another void function

void b(){
    return a();
}


//returning multiple vslue from a function 1)Using tuple/pair 2)using pointer 3)structue 4)array
std::tuple<int,int,bool> multi_tuple(int n,int m){
return std::make_tuple(n,m,true);
};

void multi_pointer(int a,int b,int* c){
*c=a+b;
};

class inc{
    private:
        int x;
    public:
        inc(int a){
            x=a;
        }

        int operator () (int x1){
            return x+x1;
        }
};
//functor
int increment(int x){
return x+1;
};
int main(){

    clock_t start_t,end_t;
    start_t=clock();
    time_t start,end;
    time(&start);
    int a=fun();
    std ::cout << a <<"\n" ;
    pass_by_value(a);
    std ::cout << a <<"\n" ;
    pass_by_reference(&a);
    std ::cout << a <<"\n" ;
    example(10);
    example();
    exam();
    exam(2);
    inline_practice ip;
    ip.show();
    b();
    int p,q;
    bool cc;
    std::tie(p,q,cc)=multi_tuple(2,3);
    std::cout << p << " " <<q <<" " <<cc <<"\n";
    int sum;
    multi_pointer(2,3,&sum);
    std::cout << sum <<"\n";

    int arr[6]={10,11,12,13,14,16};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res[n];

    std::transform(arr,arr+n,res,increment);
    for(int i=0;i<n;i++){
        std::cout << res[i] <<" " ;

    }
    std::cout << "\n";


        std::transform(arr,arr+n,res,inc(5));
    for(int i=0;i<n;i++){
        std::cout << res[i] <<" " ;

    }
    std::cout << "\n";

    // exploring floor and ciel
    std::cout << floor(2.5) <<"\n";
    std::cout << ceil(2.5) <<"\n";
    std::cout << floor(-2.5) <<"\n";
    std::cout << ceil(-2.5) <<"\n";

    time(&end);
    std::cout <<difftime(start,end) <<"\n";
    std::cout<< scalbn(2,4) <<"\n";

    std::cout << ctime(&start) <<"\n";
    end_t=clock();

    std::cout << (end_t-start_t)/CLOCKS_PER_SEC <<"\n";

    std::cout << (end_t-start_t)/CLOCKS_PER_SEC <<"\n";
    
}

