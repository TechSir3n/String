#include <iostream>
#include <String.hpp>

int main()
{
    String str;
    str.push_back('o');

    //str.append("Hello");
    str.append("Hello",6);

    if(str.empty()){
        std::cout<<"Empty !";
    }else{
        std::cout<<"Not empty !";

    }


    std::cout<<str;



    return 0;
}
