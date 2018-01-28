#include "utils.h"

namespace Utils {
    bool is_alpha(const char& chr) {
        return unsigned(chr - 'A') <= 'Z' - 'A' || unsigned(chr - 'a') <= 'z' - 'a';
    }

    bool is_digit(const char& chr) {
        return unsigned(chr - '0') <= '9' - '0';
    }

    bool is_space(const char& chr) {
        return chr == ' ' || unsigned(chr - '\t') <= '\r' - '\t';
    }

    const char* lookahead(const char* src) {
        return src + 1 == '\0' ? src : 0;
    }

    const char* is_delimiter(const char* src) {
        return (*src == ' ' || *src == 0 || *src == '\0') ? src : 0;
    }

    const char* end_of_line(const char* chr) {
      return *chr == 0 || *chr == '\n' || *chr == '\r' ? chr : 0;
    }

}