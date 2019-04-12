#include<iostream>



/*
Note:

A derived class exception should be caught before a base class Exception

Like Java, C++ library has a standard exception class which is base class for all standard exceptions. All objects thrown by components of the standard library are derived from this class. Therefore, all standard exceptions can be caught by catching this type

Unlike Java, in C++, all exceptions are unchecked. Compiler doesn’t check whether an exception is caught or not (See this for details). For example, in C++, it is not necessary to specify all uncaught exceptions in a function declaration. Although it’s a recommended practice to do so

 In C++, try-catch blocks can be nested. Also, an exception can be re-thrown using “throw; ”

 A function can also re-throw a function using same “throw; “. A function can handle a part and can ask the caller to handle remaining.

When an exception is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.

n C++, a function can specify the list of exceptions that it can throw using comma separated list like following.

  void fun(int a, char b) throw (Exception1, Exception2, ..)



  When an exception is thrown, destructors of the objects (whose scope ends with the try block) is automatically called before the catch block gets exectuted

*/

class Base{};
class Derived : public Base{};


class test{
    public:
    test(){ std::cout << "constructor call \n";};
    ~test(){std::cout << "destructor called \n";};
};
int main(){
    Derived D;
    try{
        throw D;
    }
    catch(Derived D){
        std::cout << "From Derived Class \n";
    }
    catch(Base B){
        std::cout << "From Base Class \n";
    }
    int i=7;
    test T;
    try{
        if(i>6){   //Basic Exception
            throw i;
        }
        if(i== 5){ //Catch all
            throw "a";
        }
        else{
            throw 'a';
        }
    }

    catch(int x){
        std::cout << "Exception Caught \n";
        //throw;    // this is for throwing same exception
    }

    catch(...){

        std::cout << "Exception Caught by catch all \n";
    }
}