#include <iostream>
#include <String.hpp>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    String s;
    char buffer[20]="hello_world";
    s.copy(buffer,10,2);
    cout<<s;


    return 0;
}
