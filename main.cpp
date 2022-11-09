#include <iostream>
#include <String.hpp>


using std::cout;
using std::cin;
using std::endl;

int main()
{
   // std::string str3;


    String str("Hello world");
    String str2("Hello_Friend");

    str.swap(std::forward<String>(str2));

    String temp;
    temp.swap(std::forward<String>(str2),std::forward<String>(str));
    cout<<str2;

    const char *str5=nullptr;
    String str3(str5);

    return 0;
}
