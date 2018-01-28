#ifndef CODE_OPTIMIZER_H
#define CODE_OPTIMIZER_H

#include <vector>
#include "lexer.h"

class CodeOptimizer {
    public:
        CodeOptimizer();
        ~CodeOptimizer();

        void optimize_tokens(std::vector<Lexer::Token>& tokens);
};

#endif // CODE_OPTIMIZER_H
