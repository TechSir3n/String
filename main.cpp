#include <iostream>
#include <String.hpp>


using std::cout;
using std::cin;
using std::endl;

int main()
{
   try{
    String s;
    s.append("Hello_world",3);
    s.assign("Good_night",4);
    //cout<<s<<endl;
    }catch(const StringException &_error){
        std::cerr<<_error.what();
    }

    String str("Good_String_Yes");
    cout<<str.replace(0,5,"hello")<<endl;

    return 0;
}
