#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include "constants.h"

class Exception {
    public:
        Exception();
        ~Exception();

        void parse_error(const char* msg);
        void range_error(const char* kwd, const char* msg);

        template <class T>
        void syntax_error(const char* msg, T syntax, int column, int line) {
            std::cout << "Syntax Error : " << msg << "\"" << syntax << "\"" << " at Ln " << line << ", Col " << column << "." << std::endl;
            EXIT
        }


};

#endif // EXCEPTION_H
