#include <iostream>
#include <String.hpp>


using std::cout;
using std::cin;
using std::endl;

int main()
{
   String str;
   cout<<"My name is : "<<str.append("Make")
      <<endl;

   String str_t("Hello_world");
   cout<<"Size:"<<str_t.size()<<"Length: "
      <<str_t.length()<<endl;

   String str_t2;
   str_t2.append("Good",5);

   cout<<str_t2<<" ";

   str_t2.resize(20);
   str_t2.append("Night",6);

   cout<<str_t2;

   cout<<str_t2.pop_back()<<endl;

   str_t2.clear();

    return 0;
}
