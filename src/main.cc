#include <iostream>
#include "compiler.h"
#include "file.h"

int main(int argc, char* argv[]) {

    try {
        std::string command = argv[1];
		const char* src = argv[2];
		const char* dist = argv[3];

        if (command == "compile") {

			DBNCompiler* compiler = new DBNCompiler();
			std::string source = get_file_content(src);
			compiler->compile(source.c_str());

			write_file(compiler->get_compiled_source(), dist);
            return 0;
        }
    } catch (...) {
        std::cout << "Compilation failed." << std::endl;
    }

    system("pause");
    return 0;
}