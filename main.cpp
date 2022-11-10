#include <iostream>
#include <String.hpp>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    String str("Hello");
    String str2("World");


    String str_t=str+str2;
    cout<<str_t;


    return 0;
}
