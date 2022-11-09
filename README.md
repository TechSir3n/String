# Class String 
***

### Equality operator
```
 String & operator=(const String &); 
 String & operator=(String &&)noexcept;
 ```
 ***

### Element access 
__Get character of string__
```
const char &operator[](std::size_t t_index)const;
char &operator[](std::size_t t_index);
```
__Get character of string__
```
const char &at(std::size_t t_index)const;
char &at(std::size_t t_index);
```

__Access first character__
```
const char &front();
const char &front();
```

___Access back character__
```
const char &back()const;
char &back();
```
***


### Modifiers
__Append to String__
```
String & operator+=(const String &_rhs);
String &operator+=(const char *_str);
String & operator+=(char _sym);
```

___Swap String values__
```
void swap(String &&_tmp)noexcept;
void swap(String &&t_tmp,String &&_tmp);
```
***

