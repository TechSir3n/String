## Class String

### Equality operator

```plaintext
 String &amp; operator=(const String &amp;); 
 String &amp; operator=(String &amp;&amp;)noexcept;
```

### Element access

**Get character of string**

```plaintext
const char &amp;operator[](std::size_t t_index)const;
char &amp;operator[](std::size_t t_index);
```

**Get character of string**

```plaintext
const char &amp;at(std::size_t t_index)const;
char &amp;at(std::size_t t_index);
```

**Access first character**

```plaintext
const char &amp;front();
const char &amp;front();
```

\_\_Access back character\_\_

```plaintext
const char &amp;back()const;
char &amp;back();
```

### Modifiers

**Append to String**

```plaintext
String &amp; operator+=(const String &amp;_rhs);
String &amp;operator+=(const char *_str);
String &amp; operator+=(char _sym);
```

\_\_Swap String values\_\_

```plaintext
void swap(String &amp;&amp;_tmp)noexcept;
void swap(String &amp;&amp;t_tmp,String &amp;&amp;_tmp);
```