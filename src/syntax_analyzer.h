#ifndef SYNTAX_ANALYZER_H
#define SYNTAX_ANALYZER_H
#include "exception.h"
#include "utils.h"

class SyntaxAnalyzer: public Exception {
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();
        
        int column = 1;
        int line = 1;

        void analyze_char(const char chr);
        void analyze_valid_kwd(const char* kwd);
        void analyze_first_at(const char* kwd);
        void analyze_range(const char* kwd, const char* value);

    private:
        bool paper_defined = false;
        
};

#endif // SYNTAX_ANALYZER_H
