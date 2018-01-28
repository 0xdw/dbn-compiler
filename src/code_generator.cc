#include <sstream>
#include "code_generator.h"
#include "lexer.h"

CodeGenerator::CodeGenerator() { }
CodeGenerator::~CodeGenerator() { }

std::string CodeGenerator::generate(Transformer::SVG_AST ast) {

    std::ostringstream tag;
    // start of tag
    tag << "<" << ast.tag;
    // generate parent tag attributes
    for (size_t i = 0, length = ast.attrs.size(); i < length; i++) {
        Lexer::Token node = ast.attrs[i];
        tag << " " << node.type << "=\"" << node.value << "\"";
    }
    // end of parent tag
    tag << ">\n";
    // generate child nodes
    for (size_t i = 0, length = ast.body.size(); i < length; i++) {
        Transformer::SVG_AST svg_ast = ast.body[i];

        tag << "\t<" << svg_ast.tag;
        // generate child node attributes
        for (size_t i = 0, length = svg_ast.attrs.size(); i < length; i++) {
            Lexer::Token node = svg_ast.attrs[i];
            tag << " " << node.type << "=\"" << node.value << "\"";
        }
        tag << "></" << svg_ast.tag << ">\n";
    }
    // end of tag
    tag << "</" << ast.tag << ">";

    std::string source = tag.str();
    return source;
}