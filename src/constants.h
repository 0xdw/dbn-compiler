#ifndef CONSTANTS_H
#define CONSTANTS_H

#define EXIT system("pause"); exit(1);
#define DRAWING "Drawing"
#define CALL_EXPRESSION "CallExpression"
#define NUMBER_LITERAL "NumberLiteral"
#define NEW_LINE "NEW_LINE"

// XML namespaces
#define NS_XMLNS "http://www.w3.org/2000/svg" // Required for image/svg+xml files.
#define NS_XMLNS_XLINK "http://www.w3.org/1999/xlink" // Required for image/svg+xml files with xlink: attributes.

// svg attributes/tag names/values
#define SVG "svg"
#define WIDTH "width"
#define HEIGHT "height"
#define VIEWBOX "viewBox"
#define XMLNS "xmlns"
#define VERSION "version"
#define RECT "rect"
#define X "x"
#define Y "y"
#define FILL "fill"
#define LINE "line"
#define X1 "x1"
#define Y1 "y1"
#define X2 "x2"
#define Y2 "y2"
#define STROKE "stroke"
#define STROKE_LINECAP "stroke-linecap"
#define ROUND "round"

// Zero-width tokens
extern const char EOS;

// Identifiers and literals
extern const char identifier[];
extern const char number[];

// keywords
extern const char paper_kwd[];
extern const char pen_kwd[];
extern const char line_kwd[];
extern const char set_kwd[];
extern const char repeat_kwd[];

// delimiters
extern const char empty_str[];
extern const char slash_slash[];
extern const char slash_star[];
extern const char star_slash[];

// miscellaneous punctuation and delimiters
extern const char lbrace_curly[];
extern const char rbrace_curly[];
extern const char p_open[];
extern const char p_close[];
extern const char sq_open[];
extern const char sq_close[];

// relational & logical operators
extern const char equal[];
extern const char star_equal[];
extern const char plus_equal[];
extern const char minus_equal[];

#endif // CONSTANTS_H
