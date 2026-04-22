%debug
%verbose
%locations

%code requires {
#include <iostream>
#include "ErrorMsg.h"
#include "StringTab.h"

void yyerror(char *s);	//called by the parser whenever an eror occurs
int yylex(void); /* function prototype */

}

%union {
	Symbol		symbol;	
	bool		boolean;	
}

%token <symbol>		STR_CONST TYPEID OBJECTID INT_CONST 
%token <boolean>	BOOL_CONST

%token CLASS IF ELSE FI LET IN 
%token INHERITS THEN WHILE LOOP POOL
%token CASE ESAC OF NOT NEW ISVOID 
%token ASSIGN LE DARROW

/* Precedence declarations (lowest to highest). */
%left LET_STMT
%right ASSIGN
%left NOT
%nonassoc LE '<' '='
%left '+' '-'
%left '*' '/'
%left ISVOID
%left '~'
%left '@'
%left '.'

%start program

%%

/*
 * The following is CFG of COOL programming languages. 
 * Several simple rules in the following comments are given for 
 * demonstration purpose.
 * You can uncomment them and provide extra rules for the CFG. 
 * Please be noted that you uncomment without providing extra rules, 
 * BISON will report errors when compiling COOL.yy file since 
 * several non-terminals are not defined by productions.
 * 
 
 * No rule action needed in this assignment 
 * If a recusive rule is needed, for example, define a list of something, always use 
 * right recursion like:
 * class_list : class class_list
 *
 */

// A COOL program is a list of classes
program : class_list
        ;

class_list : class
           | error ';'
           | class class_list
           | class_list error ';'
           ;

// If no parent is specified, the class inherits from the Object class.
class : CLASS TYPEID '{' optional_feature_list '}' ';'
      | CLASS TYPEID INHERITS TYPEID '{' optional_feature_list '}' ';'
      ;

// Feature list may be empty, but no empty features in list.
optional_feature_list : /* empty */
                      | feature_list
                      ;

// non-empty list: each feature terminated by ';'
feature_list: feature ';'
			| error ';'
			| feature ';' feature_list
			| feature_list error ';'
			;

// feature method or attribute
feature: OBJECTID '(' optional_formal_list ')' ':' TYPEID '{' expr '}'
	   | OBJECTID ':' TYPEID
	   | OBJECTID ':' TYPEID ASSIGN expr
	   ;

// formal (parameter) lists

// formal list may be empty
optional_formal_list: 
					| formal_list
					;

// non-empty list separated by ','
formal_list: formal
		   | formal ',' formal_list
		   ;

formal: OBJECTID ':' TYPEID
	  ;

// Expressions

expr: OBJECTID ASSIGN expr

	// dispatch
	| expr '.' OBJECTID '(' optional_arg_list ')'
	| expr '@' TYPEID '.' OBJECTID '(' optional_arg_list ')'
	| OBJECTID '(' optional_arg_list ')'

	// control flow
	| IF expr THEN expr ELSE expr FI
	| WHILE expr LOOP expr POOL

	// block: sequence of exprs , each terminated by ';'
	| '{' expr_seq '}'

	// let - %prec LET_STMT resolves the dangling-else-stype conflict
	| LET let_binding_list IN expr %prec LET_STMT

	// case
	| CASE expr OF case_branch_list ESAC

	// new
	| NEW TYPEID

	// Unary
	| ISVOID expr
	| '~' expr
	| NOT expr

	// Binary arithmetic
	| expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| expr '<' expr
	| expr LE expr
	| expr '=' expr

	// Parenthesized
	| '(' expr ')'

	// Atoms
	| OBJECTID
	| INT_CONST
	| STR_CONST
	| BOOL_CONST
	;

// Argument list for dispatch

optional_arg_list :
				  | arg_list
				  | error
				  ;

// Comma-separated, with error recovery inside argument list
arg_list: expr
		| expr ',' arg_list
		| expr error arg_list
		| expr ',' error
		;

// Block body: one or more exprs, each terminated by ';'
expr_seq: expr ';'
		| error ';'
		| expr ';' expr_seq
		| expr_seq error ';'
		;

// let bindings ID: TYPE [<- expr] [[, ID: TYPE [<- expr]]]*
let_binding_list: let_binding
				| let_binding ',' let_binding_list
				;
let_binding: OBJECTID ':' TYPEID
		   | OBJECTID ':' TYPEID ASSIGN expr
		   ;

// case branches: [[ID : TYPE => expr ; ]]+

case_branch_list: case_branch
				| case_branch case_branch_list
				;

case_branch: OBJECTID ':' TYPEID DARROW expr ';'
		   ;

/* end of grammar */

%%
#include <FlexLexer.h>
extern yyFlexLexer	lexer;

void yyerror(char *msg)
{	
	extern ErrorMsg errormsg;
	errormsg.error(yylloc.first_line, yylloc.first_column, msg);
}

int yylex(void)
{
	return lexer.yylex();
}


