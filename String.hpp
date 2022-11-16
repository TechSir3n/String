#ifndef STRING_HPP
#define STRING_HPP

#include <cstddef> // std::size_t
#include <iostream>
#include <cstring>
#include "StringException.hpp"

class String{
private:
    using reference_type=char&;

    using value_type = char;

    using pointer_type = char*;

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
    String(const_pointer  _str);

    String(const_pointer _str,size_type _size);

    String(size_type _size,value_type _sym);

    String(size_type i);

public:
    String & append(const String &_str);

    String &append(const_pointer _str);

    String & append(const_pointer _str,size_type _size);

    String & append(size_type _size,value_type _sym);

    String &insert(size_type _pos,const_pointer _str);

    String & erase(size_type _pos=0,size_type _size=npos);

    String & replace(size_type _pos,size_type _size,const_pointer _str);

    String & push_back(value_type m_sym);

    String & pop_back();

   String substr(size_type _pos=0,size_type _size=npos)const;

public:
    String & operator+=(const String &_rhs);

    String &operator+=(const_pointer _str);

    String & operator+=(value_type _sym);

public:
   friend String operator+(const String &lhs,const String &rhs);

   friend String operator+(const String &lhs,const_pointer _str);

   friend String operator+(const_pointer _str,const String &lhs);

   friend String operator+(value_type _sym,const String &lhs);

   friend String operator+(const String _lhs,value_type _sym);

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

    friend std::istream & getline(std::istream &in,String& _str,value_type _sym);

public:
    const char &operator[](size_type t_index)const;
    char &operator[](size_type t_index);

    const char &back()const;
    char &back();

    const char &front()const;
    char &front();

    const char &at(size_type t_index)const;
    char &at(size_type t_index);

    char data();

    const char *c_str()const noexcept;

    const char *data()const noexcept ;

    const char * assign(const_pointer _str,size_type _size);

    const char * assign(const_pointer _str);

public:
   std::size_t size()const noexcept;

   std::size_t max_size()const noexcept;

   std::size_t length()const noexcept;

   std::size_t capacity()const noexcept;

   std::size_t find(value_type _sym,size_type _pos=0)const;

   std::size_t find(const_pointer _str,size_type _pos=0)const;

   std::size_t find_first_of(value_type _sym,size_type _pos=0)const;

   std::size_t find_first_of(const_pointer _str,size_type _pos=0)const;

   std::size_t find_last_of(value_type _sym,size_type _pos=0)const;

   std::size_t find_last_of(const_pointer _str,size_type _pos=0)const;

   std::size_t copy(pointer_type _str,size_type n_size,size_type _pos=0);

   bool empty()const noexcept;

public:
   int compare(const_pointer _str)const;

   int compare(size_type _pos,size_type _len,const_pointer _str)const;

public:
   void clear()noexcept;

   void swap(String &&_tmp)noexcept;

   void swap(String &&t_tmp,String &&_tmp);

   void resize(size_type _size);

   void reserve(size_type new_cap);

   void t_substr(char * _buffer,const char *t_str,size_type _pos,size_type _size)const;

public:

   struct String_iterator_type{
       char *_first;
       const size_type *_size;
       size_type _pos;

       String_iterator_type(char *m_first,const size_type *m_size,size_type m_pos):
           _first(m_first),_size(m_size),_pos(m_pos) {  }

       String_iterator_type() { _first = nullptr; _size=nullptr; _pos = 0; }

       ~String_iterator_type() { delete _first; delete _size; }
   };

    public:
       class Iterator
       {
       public:
         Iterator();

         Iterator(String_iterator_type _type);

       public:
         char &operator*();
         const char &operator*()const;

         char  & operator[](size_type i);
         const char & operator[](size_type i)const;

       public:
         Iterator &operator++();

         Iterator operator++(int);

         Iterator & operator--();

         Iterator operator--(int);

         Iterator operator+(size_type t_n);

         Iterator operator-(size_type t_n);

       protected:
         String_iterator_type m_current_pos;

       private:
         friend class String;
   };

public:
   Iterator begin()const;

   Iterator end()const;

private:
   String_iterator_type f_begin() const;

   String_iterator_type l_end() const ;

private:
   char * m_str; // c - string
   std::size_t m_len = { 0 }; // length
   std::size_t m_cap = { 0 }; // capacity
   StringException *str_err;
   using pointer = Iterator;

private:
    static constexpr int npos = -1;
};

#endif // STRING_HPP
