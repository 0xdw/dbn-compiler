#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <string>
#include "transformer.h"

class CodeGenerator {
    public:
        CodeGenerator();
        ~CodeGenerator();

        std::string generate(Transformer::SVG_AST ast);
};

#endif // CODE_GENERATOR_H
