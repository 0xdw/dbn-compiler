#include "constants.h"
#include "exception.h"
#include "lexer.h"
#include "utils.h"

#define CONTINUE this->current_token = (std::string)empty_str; \
        src++; \
        continue;

Lexer::Lexer() { }
Lexer::~Lexer() {
    delete this->source;
}

const char* Lexer::get_token(const char* src) {
    
    // check end of source
    if (*src == 0) this->EOS = true;
    // skip white spaces
    while (*src && Utils::is_space(*src)) src++, this->column++;
    
    // loop until delimiter
    while (*src && !Utils::is_delimiter(src)) {

        // skip white spaces
        while (*src && Utils::is_space(*src) && !Utils::end_of_line(src)) src++, this->column++;

        // skip single line comment expression
        if (Utils::exactly<slash_slash>(src)) while (!Utils::end_of_line(src)) src++;

        // skip multiline comment expression
        if (Utils::exactly<slash_star>(src)) {
            src += 2; // increment by slash_star length
            // loop until end of comment
            while (!Utils::exactly<star_slash>(src)) src++;
            src += 2; // increment by star_slash length
        }

        // match end of line
        if (Utils::end_of_line(src)) return ++this->line, this->column = 0, src;
        // analyze single character literal
        this->analyze_char(*src);
        // analyze first character literal of a line
        this->analyze_first_at(src);
        
        this->current_token += *src, src++, this->column++;
    }
    return src;
}

void Lexer::mk_token(std::vector<Lexer::Token>& tokens, Lexer::Token token) {
    // analyze token
    this->analyze_valid_kwd(this->current_token.c_str());
    // consume token
    this->tokens.push_back(token);
}

// In DBN each token delimited by white space & classified as either identifier or number
std::vector<Lexer::Token> Lexer::tokenize(const char* src) {
    // initialize source
    this->source = (char*)src;
        
    // loop until we find the EOS (End of source)
    while (!this->EOS) {
        // update source
        this->source = (char*)this->get_token(this->source);

        // match indentifier
        if (Utils::is_alpha(*this->current_token.c_str())) {
            this->mk_token(this->tokens, { identifier, this->current_token });
            CONTINUE
        }
        // match number literal
        if (Utils::is_digit(*this->current_token.c_str())) {
            this->mk_token(this->tokens, { number, this->current_token });
            CONTINUE
        }
        
        src++; // get next character
    }

    return this->tokens;
}