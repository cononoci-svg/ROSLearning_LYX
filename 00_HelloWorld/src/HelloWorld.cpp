# include "HelloWorld.hpp"
#include <iostream>
using namespace std;
HelloWorld::HelloWorld(string name,int age):name_(name),age_(age){}
void HelloWorld::myPrint(){
    cout<<"Hello World,my name is "<<name_<<",my age is "<<age_<<endl;
}