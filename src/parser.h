#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "exception.h"
#include "syntax_analyzer.h"
#include "code_optimizer.h"
#include "lexer.h"

typedef std::vector<Lexer::Token> token_stream;

class Parser: public SyntaxAnalyzer, public CodeOptimizer {
    public:
        Parser();
        ~Parser();

        struct Expression {
            std::string type;
            std::string name;
            token_stream arguments;
        };

        // Parser AST (Abstract Syntax Tree)
        struct AST {
            std::string type;
            std::vector<Expression> body;
        };

        AST parse(token_stream tokens);
    
    private:
        int length = 0;
        int m_offset = 0;
};

#endif // PARSER_H
