# Full implementation of the String class

##### Equality operator

```plaintext
 String & operator=(const String &); 
 String & operator=(String &&)noexcept;
```

##### **Get character of string**

```plaintext
const char &operator[](size_type t_index)const;
char &operator[](size_type t_index);
```

##### **Get character of string**

```plaintext
const char & at(size_type t_index)const;
char & at(size_type t_index);
```

##### **Access first character**

```plaintext
const char & front();
char & front();
```

##### **Access back character**

```plaintext
const char & back()const;
char back();
```

##### **Append to String**

```plaintext
String & operator+=(const String &_rhs);
String &operator+=(const_pointer _str);
String & operator+=(value_type _sym);
```
#####  **Swap String values**

```plaintext
void swap(String && _tmp)noexcept;
void swap(String && _tmp,String && _tmp)noexcept;
```

#####  **Comparisions String**

```plaintext

friend bool  operator<(const String &_hrs,const String &_rhs);
friend bool  operator>(const String &_hrs,const String &_rhs);
friend bool  operator==(const String& _hrs,const String &_rhs);
friend bool  operator!=(const String &_hrs,const String & _rhs);
friend bool  operator<=(const String &_hrs,const String &_rhs);
friend bool  operator>=(const String &_hrs,const String &_rhs);
```

##### **Concatenated strings**
```
friend std::ostream & operator<<(std::ostream & out,const String &_str);
friend std::istream & operator>>(std::istream &in,String &_str);
friend std::istream & getline(std::istream &in,String &_str);
friend std::istream & getline(std::istream &in,String& _str,char _sym);
```

##### **Insert string into stream**
```
friend std::ostream & operator<<(std::ostream & out,const String &_str);
```

##### Extract string from stream
```
friend std::istream & operator>>(std::istream &in,String &_str);
```

##### **Get line from stream into string**
```  
friend std::istream & getline(std::istream &in,String &_str);
friend std::istream & getline(std::istream &in,String& _str,char _sym);
```
##### **Returns concatenated Strings**
```
friend String operator+(const String &lhs,const String &rhs);
friend String operator+(const String &lhs,const_pointer _str);
friend String operator+(const_pointer _str,const String &lhs);
friend String operator+(value_type _sym,const String &lhs);
friend String operator+(const String _lhs,value_type _sym);
```
##### **Append to String**
```
String & append(const String &_str);
String &append(const_pointer _str);
String & append(const_pointer _str,size_type _size);
String & append(size_type _size,value_type _sym);
```

##### **Assign to String**
```
const char * assign(const_pointer _str,size_type n_size);
const char * assign(const_pointer _str);
```

##### **Search in String**
```
std::size_t find(value_type _sym,size_type _pos)const;
std::size_t find(const_pointer _str,size_type _pos)const;
std::size_t find_first_of(value_type _sym,size_type _pos=0)const;
std::size_t find_first_of(const_pointer _str,size_type _pos=0)const;
std::size_t find_last_of(value_type _sym,size_type _pos=0)const;
std::size_t find_last_of(const_pointer _str,size_type _pos=0)const;
std::size_t find_first_nof_of(value_type _sym,size_type _pos=0)const;
std::size_t find_last_not_of(value_type _sym,size_type _pos=0)const;
```

##### **Iterator String**
```
Iterator &operator++();
Iterator operator++(int); 
Iterator & operator--();
Iterator operator--(int);
Iterator operator+(size_type t_n);
Iterator operator-(size_type t_n);

```