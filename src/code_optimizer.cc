#include "constants.h"
#include "utils.h"
#include "code_optimizer.h"

#define MAKE_NEW_LINE_TOKEN optimized_tokens.push_back(token); \
                            optimized_tokens.push_back({ identifier, NEW_LINE });

CodeOptimizer::CodeOptimizer() { }
CodeOptimizer::~CodeOptimizer() { }

void CodeOptimizer::optimize_tokens(std::vector<Lexer::Token>& tokens) {
    std::vector<Lexer::Token> optimized_tokens;

    int current_position = 0;
    int length = tokens.size();
    Lexer::Token token = tokens[current_position];

    while (current_position < length) {
        token = tokens[current_position++];
        if (Utils::is_digit(*token.value.c_str())) {
            if (current_position == length) {
                MAKE_NEW_LINE_TOKEN
                break;
            }
            Lexer::Token* next = &tokens[current_position];
            if (Utils::is_alpha(*next->value.c_str())) {
                MAKE_NEW_LINE_TOKEN
                continue;
            }
        }
        optimized_tokens.push_back(token);
    }

    tokens = optimized_tokens;
}