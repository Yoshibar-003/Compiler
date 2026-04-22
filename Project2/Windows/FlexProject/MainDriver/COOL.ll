/*
 * Programmer: NinYo Sene Oudom
 * Course: CSCI 4160
 * Project: Project 2 – COOL Lexer
 *
 * Description:
 *   This program implements the lexical analyzer for the COOL language.
 *   It recognizes keywords, identifiers, integers, strings,
 *   comments (including nested comments), and reports lexical errors.
 */

%option noyywrap
%option c++
%option never-interactive
%option nounistd
%option yylineno

%{
#include <iostream>
#include <string>
#include <sstream>
#include "tokens.h"
#include "ErrorMsg.h"

using std::string;
using std::stringstream;

ErrorMsg	errormsg;		//objects to trace lines and chars per line so that
							//error message can refer the correct location 
int		comment_depth = 0;	// depth of the nested comment
string	buffer = "";		// the buffer to hold part of string that has been recognized

void newline(void);				//trace the line #
void error(int, int, string);	//output the error message referring to the current token

int			line_no = 1;		//line no of current matched token
int			column_no = 1;		//column no of the current matched token

int			tokenCol = 1;		//column no after the current matched token

int			beginLine=-1;		//beginning position of a string or comment
int			beginCol=-1;		//beginning position of a string or comment

//YY_USER_ACTION will be executed after each Rule is used. Good to track locations.
#define YY_USER_ACTION {column_no = tokenCol; tokenCol=column_no+yyleng;}
%}


/* defined regular expressions */
NEWLINE			[\n]
WHITESPACES		[ \t\f\v\r]
TYPESYMBOL		[A-Z][_A-Za-z0-9]*
OBJECTSYMBOL	[a-z][_A-Za-z0-9]*

/*exclusive start conditions to recognize comment and string */
%x COMMENT
%x LINE_COMMENT
%x STRING


%%
{NEWLINE}			{ newline(); }
{WHITESPACES}+		{}


 /*
  *  If it is a token with a single character, just return the character itself.
  */

"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"=" {return '=';}
"<" {return '<';}
"~" {return '~';}
"(" {return '(';}
")" {return ')';}
"{" {return '{';}
"}" {return '}';}
":" {return ':';}
";" {return ';';}
"," {return ',';}
"." {return '.';}
"@" {return '@';}

 /*
  * Add here other rules for tokens with a single character
  *
  */

"--"[^\n]*    {}


"(*"    {comment_depth = 1; beginLine = line_no; beginCol = column_no; BEGIN(COMMENT);}



"*)"      { error(line_no, column_no, "Unmatched *)"); yylval.symbol = stringTable.add_string("Unmatched *)"); return ERROR; }

<COMMENT>"(*"      { comment_depth++; }
<COMMENT>"*)"      { comment_depth--; if (comment_depth == 0) {BEGIN(INITIAL); }}
<COMMENT>{NEWLINE} {newline(); }
<COMMENT>.         {/*to ignore other character*/}
<COMMENT><<EOF>>   {
                    error(beginLine, beginCol, "unclosed comments");
                    yylval.symbol = stringTable.add_string("unclosed comments");
                    BEGIN(INITIAL);
                    return ERROR;
                  }


 /*
  *  The multiple-character operators.
  */
"=>"				{ return (DARROW); }
"<="				{ return (LE); }
"<-"				{ return (ASSIGN); }




 /*
  *  integers should be added to the "intTable" (check stringtab.h file) 
  *  so that there is only one copy of the same interger literal.
  *  Similarly, string literals should be added to "stringTable", and 
  *  typeid and objectid should be added to "idTable".
  *	 
  *	 yylval is a variable of YYSTYPE structure is used to hold values 
  *	 of tokens if a token is a collection of lexemes.
  *
  *  check YYSTYPE definition in tokens.h
  */

[0-9][0-9]*			{ yylval.symbol = intTable.add_string(YYText()); return INTCONST; }

 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */
[Cc][Aa][Ss][Ee]			{ return (CASE); }
[Cc][Ll][Aa][Ss][Ss] 		{ return (CLASS); }

 /*
  * Add all missing rules here
  *
  */

[Ee][Ll][Ss][Ee]       { return ELSE; }
[Ff][Ii]               { return FI; }
[Ii][Ff]               { return IF; }
[Ii][Nn]               { return IN; }
[Ii][Nn][Hh][Ee][Rr][Ii][Tt][Ss] { return INHERITS; }
[Ii][Ss][Vv][Oo][Ii][Dd] { return ISVOID; }
[Ll][Ee][Tt]           { return LET; }
[Ll][Oo][Oo][Pp]       { return LOOP; }
[Pp][Oo][Oo][Ll]       { return POOL; }
[Tt][Hh][Ee][Nn]       { return THEN; }
[Ww][Hh][Ii][Ll][Ee]   { return WHILE; }
[Ee][Ss][Aa][Cc]       { return ESAC; }
[Nn][Ee][Ww]           { return NEW; }
[Oo][Ff]               { return OF; }
[Nn][Oo][Tt]           { return NOT; }



t[Rr][Uu][Ee]     { yylval.boolean = true; return BOOLCONST; }
f[Aa][Ll][Ss][Ee] { yylval.boolean = false; return BOOLCONST; }



"SELF_TYPE"     {yylval.symbol = idTable.add_string(YYText()); return TYPEID; }
"self"          {yylval.symbol = idTable.add_string(YYText()); return OBJECTID; }

{TYPESYMBOL}    {yylval.symbol = idTable.add_string(YYText()); return TYPEID; }
{OBJECTSYMBOL}  {yylval.symbol = idTable.add_string(YYText()); return OBJECTID; }


\"  {buffer = ""; beginLine = line_no; beginCol = column_no; BEGIN(STRING); }

<STRING>\"  {
              yylval.symbol = stringTable.add_string(buffer.c_str());
              BEGIN(INITIAL);
              return STRCONST;
            }

<STRING>\\n   {buffer.push_back('\n');}
<STRING>\\t   { buffer.push_back('\t'); }
<STRING>\\\"  { buffer.push_back('\"'); }
<STRING>\\\\  { buffer.push_back('\\'); }


<STRING>\\[^nt\"\\\n]  {
                          string msg = string(YYText()) + " illegal escape sequence";
                          error(line_no, column_no, msg);
                          buffer.append(YYText());
                        }

<STRING>{NEWLINE}      {
                          error(beginLine, beginCol, "Unterminated string constant");
                          yylval.symbol = stringTable.add_string(buffer.c_str());
                          BEGIN(INITIAL);
                          newline();
                          return STRCONST;
                        }

<STRING>[^\\\"\n]+     { buffer.append(YYText()); }


<STRING><<EOF>>        {
                          error(beginLine, beginCol, "EOF in string constant");
                          yylval.symbol = stringTable.add_string("EOF in string constant");
                          BEGIN(INITIAL);
                          return ERROR;
                        }

<STRING>.                  { buffer.push_back(yytext[0]); }



.     {
        string msg = "illegal character: ";
        msg.push_back(yytext[0]);
        error(line_no, column_no, msg);
        yylval.symbol = stringTable.add_string(msg.c_str());
        return ERROR;
      }

%%

void newline()
{
	line_no ++;
	column_no = 1;
	tokenCol = 1;
}

void error(int line, int col, string msg)
{
	errormsg.error(line, col, msg);
}
