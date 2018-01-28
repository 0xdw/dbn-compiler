#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "syntax_analyzer.h"

class Lexer : public SyntaxAnalyzer {

    public:
        
        Lexer();
        ~Lexer();
        
        struct Token {
            const char* type;
            std::string value;
        };

        std::vector<Token> tokenize(const char* src);
        
    private:
        bool EOS = false;
        std::string current_token = "";
        char* source;
        // token stream
        std::vector<Lexer::Token> tokens;
        
        const char* get_token(const char* src);
        void mk_token(std::vector<Token>& tokens, Token token);

};

#endif // LEXER_H
