## Full implementation of the String class

### Equality operator

```plaintext
 String & operator=(const String &); 
 String & operator=(String &&)noexcept;
```

### Element access

**Get character of string**

```plaintext
const char & operator[](std::size_t t_index)const;
char & operator[](std::size_t t_index);
```

**Get character of string**

```plaintext
const char & at(std::size_t t_index)const;
char & at(std::size_t t_index);
```

**Access first character**

```plaintext
const char & front();
char & front();
```

__Access back character__

```plaintext
const char & back()const;
char back();
```

### Modifiers

**Append to String**

```plaintext
String & operator+=(const String &_rhs);
String & operator+=(const char *_str);
String & operator+=(char _sym);
```

__Swap String values__

```plaintext
void swap(String &&_tmp)noexcept;
void swap(String && t_tmp,String &&_tmp);
```