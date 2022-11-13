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

    String(const char *_str,size_type t_size);

    String(size_type n_size,char _sym);

    String(size_type i);

public:
    String &append(const char *_str);

    String & append(const char *_str,size_type _size);

    String &insert(size_type _pos,const char *_str);

    String & erase(size_type _pos,size_type _size);

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

    const char * assign(const char*_str,std::size_t n_size);

    const char * assign(const char *_str);

public:
   std::size_t size()const noexcept;

   std::size_t max_size()const noexcept;

   std::size_t length()const noexcept;

   std::size_t capacity()const noexcept;

   std::size_t find(char _sym,size_type _pos)const;

   std::size_t copy(char *_str,size_type n_size,size_type _pos);

   bool empty()const noexcept;

public:
   int compare(const char *_str)const;

   int compare(size_type _pos,size_type _len,const char *_str,size_type n_size)const;

public:
   void clear()noexcept;

   void swap(String &&_tmp)noexcept;

   void swap(String &&t_tmp,String &&_tmp);

   void resize(size_type _size);

   void reverse(size_type _size);

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

   Iterator rbegin()const;

   Iterator rend()const;

   Iterator cend()const;

   Iterator cbegin()const;

private:
   String_iterator_type f_begin() const;
   String_iterator_type l_end() const ;

private:
   char * m_str; // c - string
   std::size_t m_len = { 0 }; // length
   std::size_t m_cap = { 0 }; // capacity
   StringException *str_err;
   using pointer = Iterator;
   //using const_pointer=Const_Iterator;

private:
    static constexpr int npos = -1;
};

#endif // STRING_HPP
