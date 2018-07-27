// move_assignment.cpp
// compile with
// c++ -o ma move_assignment.cpp -std=c++11 -fno-elide-constructors
// execute with
// ./ma

#include<iostream>
class MyClass{
public:
 MyClass();
 MyClass(const MyClass &); 
 MyClass(MyClass &&);
 void operator=(const MyClass &);
 void operator=(MyClass &&);
 ~MyClass();
};
MyClass::MyClass(){
 std::cout<<"1";
}
MyClass::MyClass(const MyClass & copyFrom){
 std::cout<<"2";
}
MyClass::MyClass(MyClass && moveFrom){
 std::cout<<"3";
}
void MyClass::operator=(const MyClass & copyFrom){
 std::cout<<"4";
}
void MyClass::operator=(MyClass&& moveFrom){
 std::cout<<"5";
}
MyClass::~MyClass(){
 std::cout<<"6";
}
MyClass myFunction(){
 MyClass temp;
 return temp;
}
void heavyPrinting(){
 MyClass object1;
 MyClass object2;
 object1=object2;
 MyClass object3;
 object3=myFunction();
 std::cout<<"7";
}
int main(){
 heavyPrinting();
 std::cout<<std::endl;
 return 0;
}
