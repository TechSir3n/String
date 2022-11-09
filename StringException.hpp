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

    const char *what()const { return message_error; }

private:
    const char* message_error;
};

#endif // STRINGEXCEPTION_HPP
