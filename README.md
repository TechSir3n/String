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
***



