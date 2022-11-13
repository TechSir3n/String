#include <iostream>
#include "String.hpp"


using std::cout;
using std::cin;
using std::endl;

int main()
{
   try{
    String s("Gs");
    s.assign("Hello_world");
    s.assign("Good_night",4);
    cout<<s<<endl;
    }catch(const StringException &_error){
        std::cerr<<_error.what();
    }


    // String s1;
     //String::String_iterator_type s2;
     //String::Iterator it;

    return 0;
}
