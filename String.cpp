#include "String.hpp"
#include <stdexcept>
#include <assert.h>


String::String()
{
   m_str=new char[1];
   m_len=0;
   m_cap=0;
}

String::String(const char *_str)
{
   if(_str!=nullptr){
    m_len=strlen(_str);
    m_str=new char[m_len+1];
    strncpy(m_str,_str,m_len);
   }
   else{
       std::cerr<<"string equals nullptr !";
   }
}


String::String(const char *_str, std::size_t t_sym)
{
   if(t_sym<0)
      throw std::out_of_range("Wrong input index line !");

   if(_str!=nullptr){
       m_len=strlen(_str);
       m_str=new char[m_len+1];
       strncpy(m_str,_str,t_sym);
   }else{
      std::cerr<<"string equals nullptr !";
   }

}

String::String(const String &_other)
{
    m_len=_other.m_len;
    m_cap=_other.m_cap;

    std::memcpy(m_str,_other.m_str,m_len);
}

String::String(String &&rhs)noexcept
{

    m_str=new char[rhs.m_len+1];
    m_str=std::move(rhs.m_str);
    m_len=std::move(rhs.m_len);
    m_cap=std::move(rhs.m_cap);
    m_str=nullptr;
}

String &String::operator=(const String &rhs)
{
  if(this!=&rhs){
      delete []m_str;

      m_str=new char[rhs.m_len+1];
      strncpy(m_str,rhs.m_str,rhs.m_len);
      m_len=rhs.m_len;
      m_cap=rhs.m_cap;

      std::memcpy(this->m_str,rhs.m_str,m_len);
  }

  return *this;
}

String & String::operator=(String &&rhs)noexcept
{
    if(this!=&rhs){
        delete [] m_str;

        m_str=new char[rhs.m_len+1];
        m_str=std::move(rhs.m_str);
        m_len=std::move(rhs.m_len);
        m_cap=std::move(rhs.m_cap);
        m_str=nullptr;
    }

    return *this;
}

String &String::push_back(char m_sym)
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

String &String::append(const char *_str)
{
   if(_str!=nullptr){
    m_len=strlen(_str);
    m_str=new char[m_len+1];
    strncpy(m_str,_str,m_len);
   }else{
       std::cerr<<"string equals nullptr !";
   }

    return *this;
}

String &String::append(const char *_str, std::size_t _size)
{
   if(_str!=nullptr){
    m_len=strlen(_str);

    m_str=new char[_size+1];
    strncpy(m_str,_str,_size);
   }else{
       std::cerr<<"string nullptr !";
   }

    return *this;
}

String &String::insert(std::size_t _pos, const char *_str)
{
    if(_pos<0 && _pos<m_len)
        throw std::logic_error("Wrong input position !");

  if(_str!=nullptr){
   strncat(m_str,_str,strlen(_str));
  }else{
      std::cerr<<"string equals nullptr !";
  }
   return *this;
}

String &String::operator+=(const String &_rhs)
{
   if(!_rhs.m_str){
       throw std::runtime_error("String from _rhs empty () ");
   }

  std::size_t temp_size = this->m_len + _rhs.m_len;

  delete this->m_str;

  m_str=new char[temp_size+1];

  std::memcpy(m_str,_rhs.m_str,m_len);
  std::memcpy(m_str+_rhs.m_len,_rhs.m_str,_rhs.m_len+1);

  return *this;
}

String &String::operator+=(const char *_str)
{
    if(_str==nullptr){
        assert("String empty !");
    }

    m_len+=std::strlen(_str);

    delete []m_str;
    m_str=new char[m_len+1];

    strncat(m_str,_str,m_len);
    strncat(m_str+m_len,_str,m_len+1);

    return *this;
}

String & String::operator+=(char _sym)
{
    if(_sym!=' '){
        assert("Empty Symbol !");
    }

    m_str+=sizeof(_sym);
    delete m_str;
    m_str=new char[m_len+1];

    m_str+=_sym;

    return  *this;
}

String operator+(const String &lhs,const String &rhs)
{
   String total_str=lhs;
   total_str+=rhs;
   return total_str;
}

String operator+(const String &lhs,const char *_str)
{

}

String operator+(const char *_str,const String &lhs)
{

}

String operator+(const String &lhs,char _sym)
{

}

String operator+(char _sym,const String &lhs)
{

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

char &String::operator[](std::size_t t_index)
{
    return *(m_str+t_index);
}

const char &String::operator[](std::size_t t_index)const
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

char &String::at(std::size_t t_index)
{
    if(t_index<0 && t_index>m_len)
        throw std::logic_error("Wrong input index line");
    return operator[](t_index);
}

const char *String::c_str() const
{
    return m_str;
}

const char &String::at(std::size_t t_index) const
{
    if(t_index<0 && t_index>m_len)
        throw std::logic_error("Wrong input index line");
    return operator[](t_index);
}

std::size_t String::size() const
{
    return m_len;
}

std::size_t String::max_size() const
{
    return String::npos;
}

std::size_t String::length() const
{
    return m_len;
}

std::size_t String::capacity() const
{
    return m_cap;
}

std::size_t String::find(char _sym, std::size_t _pos) const
{
    if(_pos<0 && _pos>m_len){
        throw std::logic_error("Wrong input position !");
    }

    for(std::size_t i=0;i<m_len;i++){
         if(m_str[i]==_sym)
             return _pos;
    }

    return String::npos;
}

bool String::empty() const
{
    return m_len ? false:true;
}

void String::clear()
{
    for(std::size_t i=0;i<m_len;i++){
        m_str[i]=0;
    }
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

void String::resize(std::size_t _size)
{
    if(m_len==_size)
        return;

   m_len=_size;
   char *_temp=new char[m_len+1];

   strncpy(_temp,m_str,m_len);
   delete [] m_str;
   m_str=_temp;
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
         throw std::runtime_error("Error on input !");
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

std::istream & getline(std::istream &in,String &_str,char _sym)
{
    _str.clear();

    if(!in){
        throw std::runtime_error("Error on input !");
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
