
#include "String.hpp"
#include <stdexcept>

String::String(const char *_str)
{
    m_len=strlen(_str);
    m_str=new char[m_len];
    strncpy(m_str,_str,m_len);
}


String &String::push_back(char m_sym)
{
    m_str[m_len++]=m_sym;
    return *this;
}

String &String::append(const char *_str)
{
    m_len=strlen(_str);
    m_str=new char[m_len];
    strncpy(m_str,_str,m_len);

    return *this;
}

String &String::append(const char *_str, std::size_t _size)
{
    m_len=std::move(_size);

    m_str=new char[_size];
    strncpy(m_str,_str,_size);

    return *this;
}

bool operator<(const String &_hrs,const String &_rhs)
{
    return _hrs.m_str<_rhs.m_str;
}

bool operator>(const String &_hrs,const String &_rhs)
{
    return _hrs.m_str>_rhs.m_str;
}

bool operator>=(const String &_hrs,const String &_rhs)
{
    return _hrs.m_str>=_rhs.m_str;
}

bool operator<=(const String &_hrs,const String &_rhs)
{
    return _hrs.m_str<=_rhs.m_str;
}

bool operator!=(const String &_hrs,const String &_rhs)
{
    return _hrs.m_str!=_rhs.m_str;
}

bool operator==(const String &_hrs,const String & _rhs)
{
    return _hrs.m_str==_rhs.m_str;

}

char &String::operator[](std::size_t t_size)
{
    return *(m_str+t_size);
}

const char &String::operator[](std::size_t t_size)const
{
       return *(m_str+t_size);
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
        throw std::out_of_range("Wrong input index line");
    return operator[](t_index);
}

std::size_t String::size() const
{
    return strlen(m_str);
}

std::size_t String::length() const
{
    return m_len;
}

bool String::empty() const
{
    return m_len ? false:true;
}

const char &String::at(std::size_t t_index) const
{
    if(t_index<0 && t_index>m_len)
        throw std::out_of_range("Wrong input index line");
    return operator[](t_index);
}

String::String(const String &_other)
{
    m_str=_other.m_str;
    m_len=_other.m_len;
    m_cap=_other.m_cap;
}

String::String(String &&rhs)
{
   *this=std::move(rhs);
}

String &String::operator=(const String &rhs)
{
    if(this!=&rhs){
        rhs.~String();
      *this=operator=(rhs);
   }
    return *this;
}

String & String::operator=(String &&rhs)
{
    if(this!=&rhs){
        rhs.~String();
        *this=operator=(std::move(rhs));
    }

    return *this;
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
    if(!in){
        throw std::runtime_error("Error on input !");
    }

    char m_sym;

    while(true){
        m_sym=in.get();

        if(m_sym=='\n' && m_sym==' ')
            break;

        _str.push_back(m_sym);
    }

    return in;
}

String::~String()
{
    delete  m_str;
    m_len=0;
    m_cap=0;
}
