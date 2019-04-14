#include<iostream>


/*

Operator Overloading can be done by using three approaches, they are

Overloading unary operator.
Overloading binary operator.
Overloading binary operator using a friend function.
Below are some criteria/rules to define the operator function:

In case of a non-static function, the binary operator should have only one argument and unary should not have an argument.
In the case of a friend function, the binary operator should have only two argument and unary should have only one argument.
All the class member object should be public if operator overloading is implemented.
Operators that cannot be overloaded are . .* :: ?:
Operator cannot be used to overload when declaring that function as friend function = () [] ->.


*/

class complex{

    private:
        int x,y;

    public:

        complex(int a=0,int b=0) {
            x=a;
            y=b;
        }

        //binary operator overloading
        complex operator + (complex const &obj ){
            complex res;
            res.x=x+ obj.x;
            res.y=y+obj.y;
            return res;
        }
        //unary operator overloading
        void operator -(){
            x--;
            y--;
        }

        void show(){
            std::cout << x <<" : " <<y <<"\n";
        }

friend complex operator / (complex const &d1,complex const &d2); // friend binary


};


complex operator / (complex const &d1,complex const &d2){
    complex res;
    res.x=d1.x / d2.x;
    res.y=d1.y/d2.y;
    res.show();
    return res;
}

int main(){
    complex c1(5,10),c2(3,4);
    c1.show();
    c2.show();
    complex c3=c1+c2;
    c3.show();
    -c1;
    c1.show();
    complex c4=c1/c2;
}