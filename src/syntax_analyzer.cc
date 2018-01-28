#include <stdio.h>
#include "syntax_analyzer.h"

SyntaxAnalyzer::SyntaxAnalyzer() { }
SyntaxAnalyzer::~SyntaxAnalyzer() { }

// analyze one character type
void SyntaxAnalyzer::analyze_char(const char chr) {
    if (!Utils::is_alpha(chr) && !Utils::is_digit(chr)) {
        this->syntax_error("Unexpected character ", chr, this->column, this->line);
    }
}

void SyntaxAnalyzer::analyze_first_at(const char* kwd) {
    if (!Utils::is_alpha(*kwd) && this->column == 1) {
        this->syntax_error("Unexpected start of line ", this->line, this->column, this->line);
    }
}

void SyntaxAnalyzer::analyze_valid_kwd(const char* kwd) {
    bool is_alpha = Utils::is_alpha(*kwd);
    bool is_digit = Utils::is_digit(*kwd);
    const char* pre = kwd;

    if (is_alpha) {
        while (*kwd) {
            if (!Utils::is_alpha(*kwd)) {
                this->syntax_error("Unexpected indentifier ", pre, this->column, this->line);
                break;
            }
            kwd++;
        }
    }

    if (is_digit) {
        while (*kwd) {
            if (!Utils::is_digit(*kwd)) {
                this->syntax_error("Unexpected indentifier ", pre, this->column, this->line);
                break;
            }
            kwd++;
        }
    }
}

void SyntaxAnalyzer::analyze_range(const char* kwd, const char* value) {
    int number;
    sscanf(value, "%d", &number);
    if (number < 0 || number > 100) {
        this->range_error(kwd, " takes one parameter - a number between 0 and 100");
    }
}