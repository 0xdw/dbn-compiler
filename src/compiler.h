#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include "lexer.h"
#include "parser.h"
#include "transformer.h"
#include "code_generator.h"
#include "file.h"

class DBNCompiler: public Lexer, public Parser, public Transformer, public CodeGenerator {
    public:
        DBNCompiler();
        ~DBNCompiler();

		void compile(const char* source);
        std::string get_compiled_source() const;

    private:
		std::string compiled_source;
};

#endif // COMPILER_H
