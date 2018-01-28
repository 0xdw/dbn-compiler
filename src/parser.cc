#include <iostream>
#include "constants.h"
#include "parser.h"

Parser::Parser() { }
Parser::~Parser() { }


Parser::AST Parser::parse(token_stream tokens) {
    // optimize tokens for parser by adding new lines
    this->optimize_tokens(tokens);
    // abstract syntax tree
    AST ast;
    ast.type = DRAWING;
    // store length of tokens
    this->length = tokens.size();

    // Loop until we are out of tokens.
    while (this->length > this->m_offset) {
        Lexer::Token current_token = tokens[this->m_offset++];

        if (current_token.type == identifier) {
            if (current_token.value == paper_kwd) { // parse paper keyword
                Expression exp;
                exp.type = CALL_EXPRESSION;
                exp.name = current_token.value;

                Lexer::Token argument = tokens[this->m_offset++];

                if (argument.type == number) {
                    // analyze range of paper keyword
                    this->analyze_range(paper_kwd, argument.value.c_str());
                    exp.arguments.push_back({ NUMBER_LITERAL, argument.value });
                    ast.body.push_back(exp);
                } else {
                    this->parse_error("Paper command must be followed by a number.");
                }
                
            } else if (current_token.value == pen_kwd) { // parse pen keyword
                Expression exp;
                exp.type = CALL_EXPRESSION;
                exp.name = current_token.value;

                Lexer::Token argument = tokens[this->m_offset++];

                if (argument.type == number) {
                    this->analyze_range(pen_kwd, argument.value.c_str());
                    exp.arguments.push_back({ NUMBER_LITERAL, argument.value });
                    ast.body.push_back(exp);
                } else {
                    this->parse_error("Pen command must be followed by a number.");
                }
            } else if (current_token.value == line_kwd) { // parse line keyword
                
                Expression exp;
                exp.type = CALL_EXPRESSION;
                exp.name = current_token.value;

                Lexer::Token argument = tokens[this->m_offset++];
                do {
                    if (argument.type == number) {
                        exp.arguments.push_back({ NUMBER_LITERAL, argument.value });
                    } else {
                        this->parse_error("Line command must be followed by numbers.");
                    }
                    argument = tokens[this->m_offset++];
                } while (argument.value != NEW_LINE);
                
                if (exp.arguments.size() < 4) {
                    this->parse_error("Unexpected number of arguments for Line keyword.");
                }
                ast.body.push_back(exp);
            }
        }

    }
    
    return ast;
}