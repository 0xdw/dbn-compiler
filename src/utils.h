#ifndef UTILS_H
#define UTILS_H

namespace Utils {
    
    bool is_alpha(const char& chr);
    bool is_digit(const char& chr);
    bool is_space(const char& chr);
    const char* lookahead(const char* src);
    const char* is_delimiter(const char* src);
    const char* end_of_line(const char* src);

    template <const char* str>
    const char* exactly(const char* src) {
        if (str == 0) return 0;
        const char* pre = str;
        if (src == 0) return 0;
        while (*pre && *pre == *src) ++pre, ++src;
        return *pre == 0 ? src : 0;
    }


}

#endif // UTILS_H
