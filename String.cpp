#include "String.hpp"
#include <stdexcept>
#include "StringException.hpp"

String::String()
{
   str_err = new StringException();
   m_str=new char[1];
   m_len=0;
   m_cap=0;
}

String::String(const_pointer _str)
{
   if(_str!=nullptr){
    m_len=strlen(_str);
    m_cap=m_len;
    m_str=new char[m_len+1];
    strncpy(m_str,_str,m_len);
   }
   else{
       throw StringException(
                   "String equals nullptr, ::String(const char *_str)");
   }
}

String::String(const_pointer _str, size_type _size)
{
   if(_size<0)
      throw std::logic_error("Wrong input size string") ;

   if(_str!=nullptr){
       m_len=strlen(_str);
       m_cap=m_len;
       m_str=new char[m_len+1];
       strncpy(m_str,_str,_size);
   }else{
       throw StringException(
                   "String equals nullptr, ::String(const char *_str,std::size_t t_size)");
   }

}

String::String(size_type n_size, value_type _sym)
{
   m_len=n_size;
   m_cap=m_len;
   m_str=new char[m_len+1];

   for(std::size_t i=0;i<m_len;i++){
       m_str[i]=_sym;
   }
}

String::String(size_type i)
{
    m_len=i;
    m_str=new char[m_len+1];
}

String &String::append(const String &_str)
{
    operator=(_str);
    return *this;
}

String::String(const String &_other)
{
    m_len=_other.m_len;
    m_cap=_other.m_cap;

    std::memcpy(m_str,_other.m_str,m_len);
}

String::String(String &&rhs)noexcept
{
    m_str=rhs.m_str;
    m_len=rhs.m_len;
    m_cap=rhs.m_cap;
    rhs.m_str=nullptr;
    rhs.m_cap=0;
    rhs.m_len=0;
}

String &String::operator=(const String &rhs)
{
  if(this!=&rhs){
      delete []m_str;

      m_str=new char[rhs.m_len+1];
      m_str=rhs.m_str;
      m_len=rhs.m_len;
      m_cap=rhs.m_cap;
  }

  return *this;
}

String & String::operator=(String &&rhs)noexcept
{
    if(this!=&rhs){
        delete [] m_str;

        m_str=rhs.m_str;
        m_len=rhs.m_len;
        m_cap=rhs.m_cap;
        rhs.m_str=nullptr;
        rhs.m_cap=0;
        rhs.m_len=0;
    }

    return *this;
}

String &String::push_back(value_type m_sym)
{
    m_str[m_len++]=m_sym;
    return *this;
}

String &String::pop_back()
{
    if(empty())
        throw std::logic_error("String empty ");

    m_str[m_len]=m_str[m_len--];

    return *this;
}

String String::substr(size_type _pos, size_type _size) const
{
    if(_pos>m_len && _size>m_len){
        throw std::logic_error("Incorrect input position or size to string,::substr(...)");
    }

   char *_buffer=new char[_size+1];
   t_substr(_buffer,m_str,_pos,_size);

   String t_str(_buffer);

    delete[]_buffer;

   return t_str;
}

String &String::append(const_pointer _str)
{
   if(_str!=nullptr){
    m_len=strlen(_str);
    m_cap=m_len;
    m_str=new char[m_len+1];
    strncpy(m_str,_str,m_len);
   }else{
       throw StringException(
                   "String equals nullptr, ::append(const char *_str)");
   }

    return *this;
}

String &String::append(const_pointer _str, size_type _size)
{
   if(_str!=nullptr){
    m_len=strlen(_str);
    m_cap=m_len;

    m_str=new char[_size+1];
    strncpy(m_str,_str,_size);
   }else{
      throw StringException(
                   "String equals nullptr, ::append(const char*_str, std::size_t _size)");
   }

   return *this;
}

String &String::append(size_type _size, value_type _sym)
{
   if(_size>m_len && _size<0){
       throw std::logic_error("Wrong number of characters to add to string");
   }

   m_len=_size;
   m_cap=m_len;
   m_str=new char[m_len+1];

   for(size_type i=0;i<m_len;i++){
       m_str[i]=_sym;
   }

   return *this ;
}

String &String::insert(size_type _pos, const_pointer _str)
{
    if(_pos<0 && _pos<m_len)
        throw std::logic_error("Wrong input position !");

  if(_str!=nullptr){
   strncat(m_str,_str,strlen(_str));
  }else{
      throw StringException("String equals nullptr !");
  }
  return *this;
}

String &String::replace(size_type _pos, size_type _size, const_pointer _str)
{

}

String &String::operator+=(const String &_rhs)
{
   if(!_rhs.m_str){
       throw StringException("String from lhs nullptr,"
                             " ::operator+=(const String &_rhs)");
   }

   if(this!=&_rhs){

     std::size_t total_length=m_len+_rhs.m_len;
     char *_buffer=new char[total_length+1];

     std::copy(m_str,m_str+m_len,_buffer);
     std::copy(_rhs.m_str,_rhs.m_str+_rhs.m_len,_buffer+m_len);
     std::swap(m_str,_buffer);
     m_len=total_length;

     delete[]_buffer;
   }

  return *this;
}

String operator+(const String &lhs,const String &rhs)
{
    String temp(lhs.size()+rhs.size());
    strncat(temp.m_str,lhs.m_str,temp.m_len);
    strncat(temp.m_str,rhs.m_str,temp.m_len);
    return temp;
}

String operator+(const String &lhs,String::const_pointer _str)
{
     String temp(_str);
     temp+=lhs;
     return temp;
}

String operator+(String::const_pointer _str,const String &lhs)
{
     String temp(_str);
     temp+=lhs;
     return temp;
}

String operator+(String::value_type _sym,const String &lhs)
{
    String temp(_sym);
    temp+=lhs;
    return temp;
}

String operator+(const String _lhs,String::value_type _sym)
{
     String temp(_sym);
     temp+=_lhs;
     return temp;
}

String &String::operator+=(const_pointer _str)
{
    if(_str==nullptr){
        throw StringException(
                    "String equals nullptr, ::operator+=(const char*_str)");
    }

    m_len+=strlen(_str);
    m_str=new char[m_len+1];

    strncat(m_str,_str,m_len);
    strncat(m_str,_str,m_len+1);

    return *this;
}

String & String::operator+=(value_type _sym)
{
    m_len+=sizeof(_sym);
    m_str=new char[m_len+1];

   for(std::size_t i=0;i<m_len;i++){
     m_str[i]+=_sym;
   }

    return  *this;
}

bool operator<(const String &_hrs,const String &_rhs)
{
    return (std::strcmp(_hrs.m_str,_rhs.m_str)<0);
}

bool operator>(const String &_hrs,const String &_rhs)
{
    return (std::strcmp(_hrs.m_str,_rhs.m_str)>0);
}

bool operator>=(const String &_hrs,const String &_rhs)
{
    return (std::strcmp(_hrs.m_str,_rhs.m_str)>=0);
}

bool operator<=(const String &_hrs,const String &_rhs)
{
    return (std::strcmp(_hrs.m_str,_rhs.m_str)<=0);
}

bool operator!=(const String &_hrs,const String &_rhs)
{
    return (std::strcmp(_hrs.m_str,_rhs.m_str)!=0);
}

bool operator==(const String &_hrs,const String & _rhs)
{
    return (std::strcmp(_hrs.m_str,_rhs.m_str)==0);

}

char &String::operator[](size_type t_index)
{
    return *(m_str+t_index);
}

const char &String::operator[](size_type t_index)const
{
       return *(m_str+t_index);
}

const char &String::back() const
{
    return operator[](m_len-1);
}

char &String::back()
{
    return operator[](m_len-1);
}

const char &String::front() const
{
    return operator[](0);
}

char &String::front()
{
    return operator[](0);

}

char &String::at(size_type t_index)
{
    if(t_index<0 && t_index>m_len)
        throw std::logic_error("Wrong input index line ::at(std::size_t t_index)");
    return operator[](t_index);
}

const char *String::c_str() const noexcept
{
    return m_str;
}

const char *String::data() const noexcept
{
    return m_str;
}

const char *String::assign(const_pointer _str, size_type _size)
{
    if(!_str){
        throw StringException("String equals nullptr,"
                              "::assign(const char*_str,std::size_t n_size)");
    }

    m_len=_size;
    m_cap=m_len;
    m_str=new char[m_len+1];

    strncpy(m_str,_str,m_len);

    return _str;
}

const char * String::assign(const_pointer _str)
{
    if(!_str){
        throw StringException("String equals nullptr,"
                              "::assign(const char *_str,std::size_t n_size)");
    }

   m_len=strlen(_str);
   m_cap=m_len;

   m_str=new char[m_len+1];
   strncpy(m_str,_str,m_len);

   return _str;
}

String::Iterator String::begin() const
{
    return f_begin();
}

String::Iterator String::end() const
{
    return l_end();
}

String::String_iterator_type String::f_begin() const
{
    return String_iterator_type(m_str,&m_len,0);
}

String::String_iterator_type String::l_end() const
{
    return String_iterator_type(m_str,&m_len,m_len);
}

const char &String::at(size_type t_index) const
{
    if(t_index<0 && t_index>m_len)
        throw std::logic_error("Wrong input index string ::at(std::size_t t_index)");
    return operator[](t_index);
}

std::size_t String::size() const noexcept
{
    return m_len;
}

std::size_t String::max_size() const noexcept
{
    return String::npos;
}

std::size_t String::length() const noexcept
{
    return m_len;
}

std::size_t String::capacity() const noexcept
{
    return m_cap;
}

std::size_t String::find(value_type _sym, size_type _pos) const
{
    if(_pos<0 && _pos>m_len){
        throw std::logic_error(
                    "Wrong input position, ::find(char _sym,std::size_t _pos)");
    }

    for(size_type i =_pos;i<m_len;i++){
        if(m_str[i]==_sym){
            return _pos;
        }
    }

    return String::npos;
}

std::size_t String::find(const_pointer _str, size_type _pos) const
{
    if(!_str){
        throw StringException("String passed to the "
                              "::find(const_pointer _str,size_type _pos) equals nullptr");
    }

    if(_pos>0 && _pos>m_len){
        throw std::logic_error("Wrong input the position of the search string,"
                               "::find(const_pointer _str,size_type _pos)");
    }

    char *pos=strstr(m_str,_str);

    if(pos!=nullptr){
        return pos-m_str;
    }

    return String::npos;
}

std::size_t String::find_first_of(value_type _sym, size_type _pos) const
{
    if(_pos>m_len){
        throw std::logic_error("Incorrect input position,"
                               "::find_first_of(value_type _sym,size_type _pos)");
    }

    for(size_type i = _pos;i<m_len;i++){
        if(m_str[i]==_sym){
            return _pos;
        }
    }

    return String::npos;
}

std::size_t String::find_first_of(const_pointer _str, size_type _pos) const
{
    if(!_str){
        throw StringException("String equal nullptr,"
                              "::find_first_of(const_pointer _str,size_type _pos)");
    }

    for(size_type i =_pos;i<m_len;i++){
        for(size_type j=0;j<strlen(_str);j++){
        if(m_str[i]==_str[j]){
            return _pos;
        }
      }
    }

    return String::npos;
}

std::size_t String::find_last_of(value_type _sym, size_type _pos) const
{

    if(_pos>m_len){
        for(size_type i =m_len;i>_pos;--i){
            if(m_str[i]==_sym){
                  return _pos;
            }
        }
    }else{
        throw std::logic_error("Incorrenct input postition,"
                               "::find_last_of(value_type _str,size_type _pos)");
    }

    return String::npos;
}

std::size_t String::find_last_of(const_pointer _str, size_type _pos) const
{
    if(!_str){
        throw StringException("String equals nullptr,"
                              "::find_last_of(const_pointer _str,size_type _pos)");
    }

    if(_pos<m_len){
         for(size_type i =m_len;i>_pos;--i){
             for(size_type j=strlen(_str);j>0;--j){
                 if(m_str[i]==_str[j]){
                     return _pos;
                 }
             }

         }
    }
    else{
        throw std::logic_error("Incorrenct input postition,"
                               "::find_last_of(const_pointer _str,size_type _pos)");
    }

    return String::npos;
}

std::size_t String::copy(pointer_type  _str, size_type n_size, size_type _pos)
{
    if(!_str){
        throw StringException("String equals nullptr,"
                              "::copy(pointer_type _str,size_type n_size,size_type _pos)");
    }

    m_len=n_size;
    m_str=new char[m_len+1];

    for(std::size_t i=0;i<m_len;i++){
        m_str[i]=_str[_pos+i];
     }

     return n_size;
 }

 bool String::empty() const noexcept
 {
     return m_len ? false:true;
 }

 int String::compare(const_pointer _str)const
 {
     if(!_str){
         throw StringException(
                     "String equals nullptr, ::compare(const char *_str)");
     }

     int m_result = strcmp(m_str,_str);

     if(m_result==0){
         return 1;
     }else{
         return -1;
     }

     return 0;

 }

 int String::compare(size_type _pos, size_type _len, const_pointer _str) const
 {
     if(!_str){
         throw StringException("String equals nullptr,"
                               "::compare(size_type _pos ,size_type len,const char *_str)");
     }

     if(_len>m_len && m_len>0 && _pos>m_len && _pos<0){
         throw std::logic_error("Wrong input position or string size,"
                                "::compare(size_type _pos ,size_type len,const char *_str)");
     }

    int m_result = 0;

    for(size_type i=_pos;i<_len;i++){

     m_result=strncmp(m_str,_str,i);

     if(m_result==0){
         return 1;
     }else{
         return -1;
     }
   }

    return 0;
 }

 void String::clear()noexcept
 {
     delete[]m_str;
     m_str=nullptr;
     m_cap=0;
     m_len=0;
 }

 void String::swap(String &&_tmp) noexcept
 {
     std::swap(m_str,_tmp.m_str);
     std::swap(m_len,_tmp.m_len);
     std::swap(m_len,_tmp.m_len);

 }

 void String::swap(String &&t_tmp, String &&_tmp)
 {
     t_tmp.swap(std::forward<String>(_tmp));
 }

 void String::resize(size_type _size)
 {
     if(m_len==_size)
         return;

     while(m_len>m_cap){
         m_cap*=2;
     }

    m_len=_size;
    char *_temp=new char[m_cap+1];

    strncpy(_temp,m_str,m_len);
    delete [] m_str;

    m_str=_temp;
 }

 void String::reserve(size_type new_cap)
 {
     if(new_cap>m_cap){
         char *temp_string=new char[new_cap+1];
         strncpy(temp_string,m_str,m_len);
         delete[]m_str;
         m_str=temp_string;
         m_cap=new_cap;
     }else{
         throw std::runtime_error("Capacity size corresponds to the original size,let's do more");
     }
 }

 void String::t_substr(char *_buffer, const char *t_str, size_type _pos, size_type _size)const
 {
    if(!t_str){
         throw StringException("t_substr got nullptr string");
     }

     for(size_type i =0;i<_size;i++){
         _buffer[i]=t_str[_pos+i];
     }
 }

 String::~String()
 {
     delete [] m_str;
     m_str=nullptr;
     m_len=0;
     m_cap=0;
 }

 std::istream & getline(std::istream &in,String &_str)
 {
     in.clear();

      if(!in){
          throw std::runtime_error("Error input");
      }

      char m_sym;

      while(true){
          in.get(m_sym);
          if(std::isspace(m_sym,in.getloc())|| in.eof()){
              break;
          }
          _str.push_back(m_sym);
      }

      return in;
 }

 std::istream & getline(std::istream &in,String &_str,String::value_type _sym)
 {
     _str.clear();

     if(!in){
         throw std::runtime_error("Error on input");
     }

     char m_sym;

     while(true){
         in.get(m_sym);

        if(m_sym==_sym){
             break;
         }

          _str.push_back(m_sym);
     }

     return in;
 }

 std::ostream & operator<<(std::ostream & out,const String &_str)
 {
     for(std::size_t i = 0;i<_str.size();i++){
         out<<_str[i];
     }

     return out;
 }

 std::istream & operator>>(std::istream &in,String &_str)
 {
     _str.clear();

     if(!in){
         throw std::runtime_error("Error on input !");
     }

    char m_sym;

    while(true){
        in.get(m_sym);

        if(std::isspace(m_sym,in.getloc())|| in.eof())
              break;

         _str.push_back(m_sym);
    }

     return in;
 }

String::Iterator::Iterator() { }


String::Iterator::Iterator(String_iterator_type _type):m_current_pos(_type) {  }


const char &String::Iterator::operator*()const
{
 return *(m_current_pos._first+m_current_pos._pos);
}

char &String::Iterator::operator[](size_type i)
{
    if(i<0 && i>*m_current_pos._size){
           throw StringException::IteratorException(
                    "Wrong input index to iterator, ::operator[](size_type i)");
    }

    return *(m_current_pos._first+i);
}

String::Iterator &String::Iterator::operator++()
{
    if(m_current_pos._pos>*m_current_pos._size){
            throw StringException::IteratorException(
                    "Iterator ouf of range of the string, ::operator++()");
    }

    m_current_pos._pos++;
    return *this;
}

String::Iterator &String::Iterator::operator--()
{
    if(m_current_pos._pos==0){
        throw StringException::IteratorException(
                    "String empty decrement error,::operator--()");
    }

    --m_current_pos._pos;
    return *this;
}

String::Iterator String::Iterator::operator--(int)
{
    if(m_current_pos._pos==0){
        throw StringException::IteratorException(
                    "String empty decrement error,::operator--(int)");
    }
    --m_current_pos._pos;
    return *this;
}

String::Iterator String::Iterator::operator++(int)
{
    if(m_current_pos._pos>*m_current_pos._size){
            throw StringException::IteratorException(
                    "Iterator ouf of range of the string,::operator++(int)");
    }

    m_current_pos._pos++;
    return *this;
}

char &String::Iterator::operator*()
{
    return *(m_current_pos._first+m_current_pos._pos);
}

const char & String::Iterator::operator[](size_type i)const
{
     if(i<0 && i>*m_current_pos._size){
            throw StringException::IteratorException(
                     "Wrong input position in iterator,::operator[](size_type i)");
     }

     return *(m_current_pos._first+i);
}
