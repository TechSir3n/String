#include <iostream>
#include <String.hpp>


using std::cout;
using std::cin;
using std::endl;

int main()
{
   try{
    String s("Gs");
    s.assign("Hello_world");
    cout<<s;
    }catch(const StringException &_error){
        std::cerr<<_error.what();
    }


    return 0;
}
