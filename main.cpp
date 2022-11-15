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
    cout<<s<<endl;
    }catch(const StringException &_error){
        std::cerr<<_error.what();
    }


    String str("green Apple dfdf ");

    std::size_t m_result = str.find_first_of("M",3);
    if(m_result!=std::string::npos){
        cout<<"Found : "<<m_result<<endl;
    }


    return 0;
}
