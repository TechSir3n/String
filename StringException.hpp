#ifndef STRINGEXCEPTION_HPP
#define STRINGEXCEPTION_HPP

#include <stdexcept>

class StringException{
public:
    StringException():message_error(nullptr)  {  }

    StringException(const StringException &_rhs) = default;

    StringException & operator=(const StringException &rhs) = default;

    StringException & operator=(StringException && rhs) = default ;

    StringException(StringException &&rhs) = default;

   ~StringException() noexcept { delete message_error; }

    StringException(const char * _error):message_error(_error) {  }

public:
    const char *what()const { return message_error; }

public:
    class IteratorException{
    public:

       IteratorException() = default;

       ~IteratorException() noexcept  { delete iterator_error; }

       IteratorException(const char * _err):iterator_error(_err) { }

       IteratorException(const IteratorException &_rhs) = default;

       IteratorException(IteratorException &&_rhs) = default;

       IteratorException & operator =(IteratorException &&_rhs) = default;

       IteratorException & operator=(IteratorException &_rhs) =default;

     public:
           const char *what()const { return iterator_error; }

     private:
           const char * iterator_error;
    };

private:
    const char* message_error;
};

#endif // STRINGEXCEPTION_HPP
