#ifndef __DMSCANNER_H__
#define __DMSCANNER_H__

#ifndef __FLEX_LEXER_H
//#define yyFlexLexer BaseLexer
#include <FlexLexer.h>
//#undef yyFlexLexer
#endif
#undef YY_DECL
#define YY_DECL \
DM::Parser::token_type \
DM::Lexer::lex( \
	DM::Parser::semantic_type* yylval, \
	DM::Parser::location_type* yylloc \
)
 
#include "parser.hpp"
namespace DM {
class Lexer : public yyFlexLexer
{
public:
	Lexer(std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0);
	~Lexer();
	/** This is the main lexing function. It is generated by flex according to
	* the macro declaration YY_DECL above. The generated bison parser then
	* calls this virtual function to fetch new tokens. */
	virtual Parser::token_type lex(Parser::semantic_type* yylval, Parser::location_type* yylloc);
	
	void set_debug_level(bool on);
	 
private:
	/* hide this one from public view */
	int yylex();
	/* yyval ptr */
	DM::Parser::semantic_type *yylval;
};
}
#endif