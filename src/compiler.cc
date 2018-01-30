#include <iostream>
#include "constants.h"
#include "compiler.h"
#include "lexer.h"

DBNCompiler::DBNCompiler() { }
DBNCompiler::~DBNCompiler() { }


void DBNCompiler::compile(const char* source) {
	try {
		this->compiled_source = this->generate(this->transform(this->parse(this->tokenize(source))));
	} catch (...) {
		std::cout << "Compilation failed." << std::endl;
		EXIT
	}
}

std::string DBNCompiler::get_compiled_source() const {
	return this->compiled_source;
}
