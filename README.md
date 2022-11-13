# Full implementation of the String class

##### Equality operator

```plaintext
 String & operator=(const String &amp;); 
 String & operator=(String &&)noexcept;
```

##### **Get character of string**

```plaintext
const char & operator[](std::size_t t_index)const;
char & operator[](std::size_t t_index);
```

##### **Get character of string**

```plaintext
const char & at(std::size_t t_index)const;
char & at(std::size_t t_index);
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
String & operator+=(const char *_str);
String & operator+=(char _sym);
```

#### **Swap String values**

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

##### Concatenated strings
```
friend std::ostream & operator<<(std::ostream & out,const String &_str);
friend std::istream & operator>>(std::istream &in,String &_str);
friend std::istream & getline(std::istream &in,String &_str);
friend std::istream & getline(std::istream &in,String& _str,char _sym);
```

##### Insert string into stream
```
friend std::ostream & operator<<(std::ostream & out,const String &_str);
```

##### Extract string from stream
```
friend std::istream & operator>>(std::istream &in,String &_str);
```

##### Get line from stream into string
```  
friend std::istream & getline(std::istream &in,String &_str);
friend std::istream & getline(std::istream &in,String& _str,char _sym);
```
##### Returns concatenated Strings
```
friend String operator+(const String &lhs,const String &rhs);
friend String operator+(const String &lhs,const char *_str);
friend String operator+(const char *_str,const String &lhs);
friend String operator+(char _sym,const String &lhs);
friend String operator+(const String &_lhs,char _sym);
```
