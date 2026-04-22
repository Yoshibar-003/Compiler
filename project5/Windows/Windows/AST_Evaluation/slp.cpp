#include <algorithm>
#include "slp.h"
#include <stdexcept>

using namespace std;

/* To be implemented by stduents */

// Run two statements in order
void CompoundStm::interp( SymbolTable& symbols )
{
	stm1->interp( symbols );
	stm2->interp( symbols );
}


/* To be implemented by stduents */
// Assign evaluated value to variable
void AssignStm::interp( SymbolTable& symbols )
{
	symbols[id] = exp->interp( symbols );
}


// Print all expressions
void PrintStm::interp( SymbolTable& symbols )
{
	exps->interp( symbols );
	cout << endl;
}

// Return variable value from table
int IdExp::interp( SymbolTable& symbols )
{
	auto it = symbols.find( id );
	if (it == symbols.end())
	{
		throw runtime_error("Undefined variable: " + id);
	}
	return it->second;
}

// Return numeric value
int NumExp::interp( SymbolTable& symbols )
{
	return num;
}

// Evaluate and apply an operator
int OpExp::interp( SymbolTable& symbols )
{
	int leftVal= left->interp( symbols );
	int rightVal= right->interp( symbols );

	switch (oper){
		case PLUS:
			return leftVal + rightVal;
		case MINUS:
			return leftVal - rightVal;
		case TIMES:
			return leftVal * rightVal;
		case DIV:
			if (rightVal == 0) {
				throw runtime_error("Division by zero");
			}
			return leftVal / rightVal;
		default:
			throw runtime_error("Unknown operator");
	}
}


// Run the statement, then return expression
int EseqExp::interp( SymbolTable& symbols )
{
	stm->interp( symbols );
	return exp->interp( symbols );
}

// Print head, then rest
void PairExpList::interp( SymbolTable& symbols)
{
	cout << head->interp( symbols ) << " ";
	tail->interp( symbols );
}

// Print last value
void LastExpList::interp( SymbolTable& symbols)
{
	cout << head->interp(symbols);
}

