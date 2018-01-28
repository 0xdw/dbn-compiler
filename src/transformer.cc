#include <string>
#include "constants.h"
#include "parser.h"
#include "transformer.h"

Transformer::Transformer() { }
Transformer::~Transformer() { }

std::string Transformer::make_color() {
    int level = this->pen_color;
    return "rgb(" + std::to_string(level) + "%, " + std::to_string(level) + "%, " + std::to_string(level) + "%)";
}

std::string Transformer::flip(int value) {
    int a = 100 - value;
    return std::to_string(a);
}

Transformer::SVG_AST Transformer::transform(Parser::AST ast) {
    SVG_AST svg_ast;

    svg_ast.tag = SVG;
       
    int current_position = 0;
    int length = ast.body.size();

    while (current_position < length) {
        Parser::Expression node = ast.body[current_position++];

        if (node.name == paper_kwd) {
            int paper_color = 100 - std::stoi(node.arguments[0].value);

			svg_ast.attrs.push_back({ WIDTH, node.arguments[0].value });
			svg_ast.attrs.push_back({ HEIGHT, node.arguments[0].value });
			svg_ast.attrs.push_back({ VIEWBOX, "0 0 "+node.arguments[0].value+" "+node.arguments[0].value+"" });
			svg_ast.attrs.push_back({ XMLNS, NS_XMLNS });
			svg_ast.attrs.push_back({ VERSION, "1.1" });

            SVG_AST body_ast;
            body_ast.tag = RECT;
            body_ast.attrs.push_back({ X, "0" });
            body_ast.attrs.push_back({ Y, "0" });
            body_ast.attrs.push_back({ WIDTH, node.arguments[0].value });
            body_ast.attrs.push_back({ HEIGHT, node.arguments[0].value });
            body_ast.attrs.push_back({ FILL, "rgb(" + std::to_string(paper_color) + "%," + std::to_string(paper_color) + "%," + std::to_string(paper_color) + "%)" });
            svg_ast.body.push_back(body_ast);
        } else if (node.name == pen_kwd) {
            // TODO
        } else if (node.name == line_kwd) {
            SVG_AST body_ast;
            body_ast.tag = LINE;
            if (node.arguments.size() < 4) {
                this->parse_error("Unexpected number of arguments.");
            }
            body_ast.attrs.push_back({ X1, node.arguments[0].value });
            body_ast.attrs.push_back({ Y1, this->flip(std::stoi(node.arguments[1].value)) });
            body_ast.attrs.push_back({ X2, node.arguments[2].value });
            body_ast.attrs.push_back({ Y2, this->flip(std::stoi(node.arguments[3].value)) });
            body_ast.attrs.push_back({ STROKE, this->make_color() });
            body_ast.attrs.push_back({ STROKE_LINECAP, ROUND });
            svg_ast.body.push_back(body_ast);
        }

    }

    return svg_ast;
}