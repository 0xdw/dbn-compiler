#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <vector>
#include <string>
#include "syntax_analyzer.h"
#include "parser.h"
#include "lexer.h"

class Transformer: public SyntaxAnalyzer {
    public:
        Transformer();
        ~Transformer();

        struct SVG_AST {
            std::string tag;
            std::vector<Lexer::Token> attrs;
            std::vector<SVG_AST> body;
        };

        int pen_color = 100; // default pen color is black
        SVG_AST transform(Parser::AST ast);
    
    private:
        std::string make_color();
        std::string flip(int value);
};

#endif // TRANSFORMER_H
