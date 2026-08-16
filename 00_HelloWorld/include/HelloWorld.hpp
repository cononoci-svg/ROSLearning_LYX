# include <string>
using namespace std;
class HelloWorld{
public:
    HelloWorld(string name,int age);
    void myPrint();
private:
    string name_;
    int age_;
};