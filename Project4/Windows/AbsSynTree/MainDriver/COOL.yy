
%debug
%verbose

%code requires {
#include <iostream>
#include "ErrorMsg.h"
#include "StringTab.h"
#include "Absyn.h"

using namespace absyn;
}

%union {
	Symbol			symbol;
	bool			boolean;
	Program			program;
	Class_			class_;
	Classes			classes;
	Feature			feature;
	Features		features;
	Formal			formal;
	Formals			formals;
	Branch			branch;
	Branches		branches;
	Expression		expression;
	Expressions		expressions;
}

%{
extern string curr_filename;

int yylex(void);
void yyerror(char *s);

template<typename Item>
List<Item>* single_list(Item i);

template<typename Item>
List<Item>* pair_list(Item head, List<Item>* rest);

Program root;
%}

/* Non-terminal types */
%type <program>		program
%type <class_>		class
%type <classes>		class_list
%type <feature>		feature
%type <features>	feature_list optional_feature_list
%type <formal>		formal
%type <formals>		formal_list optional_formal_list
%type <expression>	expr let_binding let_list
%type <expressions>	expr_seq arg_list optional_arg_list
%type <branch>		case_branch
%type <branches>	case_branch_list

/* Terminal types */
%token <symbol>		STR_CONST TYPEID OBJECTID INT_CONST
%token <boolean>	BOOL_CONST

%token CLASS IF ELSE FI LET IN
%token INHERITS THEN WHILE LOOP POOL
%token CASE ESAC OF NOT NEW ISVOID
%token ASSIGN LE DARROW

/* Precedence - lowest to highest */
%right ASSIGN
%left NOT
%nonassoc LE '<' '='
%left '-' '+'
%left '*' '/'
%left ISVOID
%left '~'
%left '@'
%left '.'
%nonassoc LET_STMT

%start program

%%

/* A COOL program is a list of classes */
program : class_list
		{ root = new Program_class(@1.first_line, @1.first_column, $1); }
		;

class_list
		: class
			{ $$ = single_list($1); }
		| class class_list
			{ $$ = pair_list($1, $2); }
		;

/* If no parent specified, inherits from Object */
class
		: CLASS TYPEID '{' optional_feature_list '}' ';'
			{ $$ = new Class_class(@1.first_line, @1.first_column,
					stringtable.add_string(curr_filename),
					$2, idtable.add_string("Object"), $4); }
		| CLASS TYPEID INHERITS TYPEID '{' optional_feature_list '}' ';'
			{ $$ = new Class_class(@1.first_line, @1.first_column,
					stringtable.add_string(curr_filename),
					$2, $4, $6); }
		;

/* Feature list may be empty */
optional_feature_list
		: /* empty */
			{ $$ = nullptr; }
		| feature_list
			{ $$ = $1; }
		;

/* Non-empty list: each feature terminated by ';' */
feature_list
		: feature ';'
			{ $$ = single_list($1); }
		| feature ';' feature_list
			{ $$ = pair_list($1, $3); }
		;

/* Feature is a method or attribute */
feature
		: OBJECTID '(' optional_formal_list ')' ':' TYPEID '{' expr '}'
			{ $$ = new Method(@1.first_line, @1.first_column, $1, $3, $6, $8); }
		| OBJECTID ':' TYPEID
			{ $$ = new Attr(@1.first_line, @1.first_column, $1, $3, nullptr); }
		| OBJECTID ':' TYPEID ASSIGN expr
			{ $$ = new Attr(@1.first_line, @1.first_column, $1, $3, $5); }
		;

/* Formal (parameter) list may be empty */
optional_formal_list
		: /* empty */
			{ $$ = nullptr; }
		| formal_list
			{ $$ = $1; }
		;

/* Non-empty comma-separated formals */
formal_list
		: formal
			{ $$ = single_list($1); }
		| formal ',' formal_list
			{ $$ = pair_list($1, $3); }
		;

formal
		: OBJECTID ':' TYPEID
			{ $$ = new Formal_class(@1.first_line, @1.first_column, $1, $3); }
		;

/* Expressions */
expr
		/* Assignment */
		: OBJECTID ASSIGN expr
			{ $$ = new AssignExp(@1.first_line, @1.first_column, $1, $3); }

		/* Dispatch: obj.method(args) */
		| expr '.' OBJECTID '(' optional_arg_list ')'
			{ $$ = new CallExp(@1.first_line, @1.first_column, $1, $3, $5); }

		/* Static dispatch: obj@Type.method(args) */
		| expr '@' TYPEID '.' OBJECTID '(' optional_arg_list ')'
			{ $$ = new StaticCallExp(@1.first_line, @1.first_column, $1, $3, $5, $7); }

		/* Self dispatch: method(args) - must build "self" object */
		| OBJECTID '(' optional_arg_list ')'
			{
				Expression self_obj = new absyn::ObjectExp(@1.first_line, @1.first_column,
									idtable.add_string("self"));
				$$ = new CallExp(@1.first_line, @1.first_column, self_obj, $1, $3);
			}

		/* Control flow */
		| IF expr THEN expr ELSE expr FI
			{ $$ = new IfExp(@1.first_line, @1.first_column, $2, $4, $6); }

		| WHILE expr LOOP expr POOL
			{ $$ = new WhileExp(@1.first_line, @1.first_column, $2, $4); }

		/* Block */
		| '{' expr_seq '}'
			{ $$ = new BlockExp(@1.first_line, @1.first_column, $2); }

		/* Let */
		| LET let_list %prec LET_STMT
			{ $$ = $2; }

		/* Case */
		| CASE expr OF case_branch_list ESAC
			{ $$ = new CaseExp(@1.first_line, @1.first_column, $2, $4); }

		/* New object */
		| NEW TYPEID
			{ $$ = new NewExp(@1.first_line, @1.first_column, $2); }

		/* Unary operators */
		| ISVOID expr
			{ $$ = new IsvoidExp(@1.first_line, @1.first_column, $2); }

		/* ~expr means 0 - expr */
		| '~' expr
			{ $$ = new OpExp(@1.first_line, @1.first_column,
					new IntExp(@1.first_line, @1.first_column, inttable.add_int(0)),
					OpExp::MINUS, $2); }

		| NOT expr
			{ $$ = new NotExp(@1.first_line, @1.first_column, $2); }

		/* Binary arithmetic */
		| expr '+' expr
			{ $$ = new OpExp(@1.first_line, @1.first_column, $1, OpExp::PLUS, $3); }
		| expr '-' expr
			{ $$ = new OpExp(@1.first_line, @1.first_column, $1, OpExp::MINUS, $3); }
		| expr '*' expr
			{ $$ = new OpExp(@1.first_line, @1.first_column, $1, OpExp::MUL, $3); }
		| expr '/' expr
			{ $$ = new OpExp(@1.first_line, @1.first_column, $1, OpExp::DIV, $3); }

		/* Comparisons */
		| expr '<' expr
			{ $$ = new OpExp(@1.first_line, @1.first_column, $1, OpExp::LT, $3); }
		| expr LE expr
			{ $$ = new OpExp(@1.first_line, @1.first_column, $1, OpExp::LE, $3); }
		| expr '=' expr
			{ $$ = new OpExp(@1.first_line, @1.first_column, $1, OpExp::EQ, $3); }

		/* Parenthesized */
		| '(' expr ')'
			{ $$ = $2; }

		/* Atoms */
		| OBJECTID
			{ $$ = new ObjectExp(@1.first_line, @1.first_column, $1); }
		| INT_CONST
			{ $$ = new IntExp(@1.first_line, @1.first_column, $1); }
		| STR_CONST
			{ $$ = new StringExp(@1.first_line, @1.first_column, $1); }
		| BOOL_CONST
			{ $$ = new BoolExp(@1.first_line, @1.first_column, $1); }
		;

/* Optional argument list for dispatch */
optional_arg_list
		: /* empty */
			{ $$ = nullptr; }
		| arg_list
			{ $$ = $1; }
		;

/* Comma-separated argument list - right recursion */
arg_list
		: expr
			{ $$ = single_list($1); }
		| expr ',' arg_list
			{ $$ = pair_list($1, $3); }
		;

/* Block body: one or more exprs, each terminated by ';' */
expr_seq
		: expr ';'
			{ $$ = single_list($1); }
		| expr ';' expr_seq
			{ $$ = pair_list($1, $3); }
		;

/* let_list handles chained bindings:
   x:T [<- e], y:T2 [<- e2], ... IN body
   Each let_binding holds name/type/init.
   The body is filled in here. */
let_list
		/* Last binding before IN */
		: let_binding IN expr %prec LET_STMT
			{
				LetExp* let = dynamic_cast<LetExp*>($1);
				$$ = new LetExp(@1.first_line, @1.first_column,
						let->getVarName(), let->getVarType(),
						const_cast<Expression>(let->getInit()), $3);
			}
		/* More bindings follow after comma */
		| let_binding ',' let_list
			{
				LetExp* let = dynamic_cast<LetExp*>($1);
				$$ = new LetExp(@1.first_line, @1.first_column,
						let->getVarName(), let->getVarType(),
						const_cast<Expression>(let->getInit()), $3);
			}
		;

/* Single let binding: stores name, type, optional init. Body is nullptr for now. */
let_binding
		: OBJECTID ':' TYPEID
			{ $$ = new LetExp(@1.first_line, @1.first_column, $1, $3, nullptr, nullptr); }
		| OBJECTID ':' TYPEID ASSIGN expr
			{ $$ = new LetExp(@1.first_line, @1.first_column, $1, $3, $5, nullptr); }
		;

/* Case branches */
case_branch_list
		: case_branch
			{ $$ = single_list($1); }
		| case_branch case_branch_list
			{ $$ = pair_list($1, $2); }
		;

case_branch
		: OBJECTID ':' TYPEID DARROW expr ';'
			{ $$ = new Branch_class(@1.first_line, @1.first_column, $1, $3, $5); }
		;

%%

#include <FlexLexer.h>
extern yyFlexLexer lexer;

void yyerror(char *s)
{
	extern ErrorMsg errormsg;
	errormsg.error(yylloc.first_line, yylloc.first_column, s);
}

int yylex(void)
{
	return lexer.yylex();
}

template<typename Item>
List<Item>* single_list(Item i)
{
	return new List<Item>(i, nullptr);
}

template<typename Item>
List<Item>* pair_list(Item head, List<Item>* rest)
{
	return new List<Item>(head, rest);
}
