#ifndef STRING_HPP
#define STRING_HPP

#include <cstddef> // std::size_t
#include <iostream>
#include <cstring>
#include "StringException.hpp"

class String{
public:
    using reference=char&;

    using value_type = char;

    using size_type=std::size_t;

    using const_pointer=const char*;

public:
    String() ;

    String(const String &);

    String(String&&)noexcept;

    String & operator=(const String &);

    String & operator=(String &&)noexcept;

    ~String();

public:
    String(const char *_str);

    String(const char *_str,std::size_t t_sym);

    String(std::size_t n_size,char _sym);

    String(std::size_t i);

public:
    String &append(const char *_str);

    String & append(const char *_str,std::size_t _size);

    String &insert(std::size_t _pos,const char *_str);

    String & erase(std::size_t _pos,std::size_t _size);

    String & push_back(char m_sym);

    String & pop_back();

public:
    String & operator+=(const String &_rhs);

    String &operator+=(const char *_str);

    String & operator+=(char _sym);

public:
   friend String operator+(const String &lhs,const String &rhs);

   friend String operator+(const String &lhs,const char *_str);

   friend String operator+(const char *_str,const String &lhs);

   friend String operator+(char _sym,const String &lhs);

   friend String operator+(const String _lhs,char _sym);

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

    friend std::istream & getline(std::istream &in,String &_str);

    friend std::istream & getline(std::istream &in,String& _str,char _sym);

public:
    const char &operator[](std::size_t t_index)const;
    char &operator[](std::size_t t_index);

    const char &back()const;
    char &back();

    const char &front()const;
    char &front();

    const char &at(std::size_t t_index)const;
    char &at(std::size_t t_index);

    const char *c_str()const;

public:
   std::size_t size()const;

   std::size_t max_size()const;

   std::size_t length()const;

   std::size_t capacity()const;

   std::size_t find(char _sym,std::size_t _pos)const;

   std::size_t copy(char *_str,std::size_t n_size,std::size_t _pos);

   bool empty()const;

public:
   void clear();

   void swap(String &&_tmp)noexcept;

   void swap(String &&t_tmp,String &&_tmp);

   void resize(std::size_t _size);

   void reverse(std::size_t _size);

public:

   struct String_iterator_type{
       char *_first;
       const size_type *_size;
       size_type _pos;

       String_iterator_type(char *m_first,const size_type *m_size,size_type m_pos):
           _first(m_first),_size(m_size),_pos(m_pos) {  }
   };

    public:
       class Iterator
       {
       public:
         friend class String;

         Iterator();

         Iterator(String_iterator_type _type);

       public:
         char &operator*();
         const char & operator*()const;

         char  & operator[](int);
         const char & operator[](int)const;

       public:
         Iterator & operator++();

         Iterator operator++(int);

         Iterator & operator--();

         Iterator operator--(int);

         Iterator operator+(std::size_t t_n);

         Iterator operator-(std::size_t t_n);

       protected:
         String_iterator_type m_current_pos;
   };

public:
      using pointer = Iterator;

public:
   Iterator begin()noexcept ;

   Iterator end()noexcept;

   Iterator rbegin()noexcept;

   Iterator rend()noexcept;

   Iterator cend()noexcept;

   Iterator cbegin()noexcept;

private:
   char * m_str; // c - string
   std::size_t m_len = { 0 }; // length
   std::size_t m_cap = { 0 }; // capacity
   StringException *str_err;

private:
    static constexpr int npos = -1;
};

#endif // STRING_HPP
