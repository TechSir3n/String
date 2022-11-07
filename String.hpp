#ifndef STRING_HPP
#define STRING_HPP

#include <cstddef> // std::size_t
#include <iostream>
#include <cstring>

class String{
public:
    String() = default ;

    String(const String &);

    String(String&&);

    String & operator=(const String &);

    String & operator=(String &&);

    ~String();

public:
    String(const char *_str);

    String & push_back(char m_sym);

public:
    String &append(const char *_str);

    String & append(const char *_str,std::size_t _size);

public:
    friend  bool operator<(const String &_hrs,const String &_rhs);

    friend bool operator>(const String &_hrs,const String &_rhs);

    friend bool  operator==(const String& _hrs,const String &_rhs);

    friend bool  operator!=(const String &_hrs,const String & _rhs);

    friend bool operator<=(const String &_hrs,const String &_rhs);

    friend bool operator>=(const String &_hrs,const String &_rhs);

public:
    friend std::ostream & operator<<(std::ostream & out,const String &_str);

    friend std::istream & operator>>(std::istream &in,String &_str);

public:
    const char &operator[](std::size_t t_size)const;
    char &operator[](std::size_t t_size);

    const char &back()const;
    char &back();

    const char &front()const;
    char &front();

    const char &at(std::size_t t_index)const;
    char &at(std::size_t t_index);

public:
   std::size_t size()const;

   std::size_t length()const;

   bool empty()const;

private:
    char * m_str = nullptr; // c - string
    std::size_t m_len = 0; // length
    std::size_t m_cap= 0; // capacity

private:
    static constexpr int npos = -1;
};

#endif // STRING_HPP
