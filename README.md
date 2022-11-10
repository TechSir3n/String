Full implementation of the String class

## Equality operator

```plaintext
 String & operator=(const String &amp;); 
 String & operator=(String &amp;&amp;)noexcept;
```

## **Get character of string**

```plaintext
const char & operator[](std::size_t t_index)const;
char & operator[](std::size_t t_index);
```

## **Get character of string**

```plaintext
const char & at(std::size_t t_index)const;
char & at(std::size_t t_index);
```

## **Access first character**

```plaintext
const char & front();
char & front();
```

## **Access back character**

```plaintext
const char &amp; back()const;
char back();
```

## **Append to String**

```plaintext
String &amp; operator+=(const String &amp;_rhs);
String &amp; operator+=(const char *_str);
String &amp; operator+=(char _sym);
```

## **Swap String values**

```plaintext
void swap(String &amp;&amp;_tmp)noexcept;
void swap(String &amp;&amp; t_tmp,String &amp;&amp;_tmp)noexcept;
```

##  **Comparisions String** 

```plaintext

friend  bool operator<(const String &_hrs,const String &_rhs);
friend bool operator>(const String &_hrs,const String &_rhs);
friend bool  operator==(const String& _hrs,const String &_rhs);
friend bool  operator!=(const String &_hrs,const String & _rhs);
friend bool operator<=(const String &_hrs,const String &_rhs);
friend bool operator>=(const String &_hrs,const String &_rhs);
```