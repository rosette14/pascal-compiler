#pragma once
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "hash_fun.h"
#include "hash_table.h"

#include <fstream>
using std::ofstream;
using std::ios;
static ofstream vout("code.txt", ios::out);

class Node;
class Ident;
class Program;
class Declarations;
class Subprogram_head;
class Function;
class Procedure;
class Arguments;
class Parameter_list;
class Statement_list;
class Variable;
class Expression;
class ExpIdent;
class ExpInt;
class ExpReal;
class ExpChar;
class ExpStr;
class ExpTrue;
class ExpFalse;
class ExpInner;
class Expr;
class ExpOpt;
class ExpNot;
class Identifier_list;
class Type;
class Array;
class Subprogram_declaration;
class Subprogram_declarations;
class Procedure_statement;
class Expression_list;
class Statement;
class StmtAssign;
class StmtProcedure;
class StmtCompound;
class StmtIf;
class StmtIfElse;
class StmtWhile;
class StmtFor;
class StmtWriteStr;
class StmtWriteId;
class StmtWriteExp;
class Compound_statement;
class Return_stmt;

class Visitor;
class PrintVisitor;
class TypeVisitor;
class Symbol;
typedef CHashTable<Symbol> HashTab;


class Node
{
public:
	int line;
	int column;
	Node* father;
	Node(int, int);
	virtual void accept(Visitor *);
};
class Ident : public Node
{
public:
	//int type ;
	string name;
	Symbol *symbol;
	Ident(string, int, int);
	virtual void accept(Visitor *);
};
class Program : public Node
{
public:
	Ident *name;
	Declarations *declarations;
	Subprogram_declarations *subprogram_declarations;
	Compound_statement *compound_statement;
	Program(Ident *, Declarations*, Subprogram_declarations*, Compound_statement*, int, int);
	virtual void accept(Visitor *);
};

class Declarations : public Node
{
public:
	vector <Identifier_list *>* identifier_list;
	vector <Type *>* type;
	Declarations(Identifier_list *, Type*, int, int);
	Declarations(int, int);
	void AddDeclarations(Identifier_list *, Type*);
	virtual void accept(Visitor *);
};

class Subprogram_head : public Node
{
public:
	Ident *name;
	Arguments *arg;
	Declarations * declarations=NULL;
	Subprogram_head(int, int);
	virtual void accept(Visitor *);
};
class Function : public Subprogram_head
{
public:
	int standard;
	int visited = 0;
	Function(int, Ident *, Arguments*, Declarations *, int, int);
	virtual void accept(Visitor *);
};
class Procedure : public Subprogram_head
{
public:
	int visited = 0;
	Procedure(Ident *, Arguments*, Declarations *, int, int);
	virtual void accept(Visitor *);
};
class Arguments : public Node
{
public:
	Parameter_list *parameter_list;
	Arguments(int, int);
	Arguments(Parameter_list *, int, int);
	virtual void accept(Visitor *);
};

class Parameter_list : public Node
{
public:
	vector <Identifier_list *>* identifier_list;
	vector <Type *>* type;
	Parameter_list(Identifier_list *, Type*, int, int);
	void AddParameter_list(Identifier_list *, Type*);
	virtual void accept(Visitor *);
};

class Statement_list : public Node
{
public:
	vector <Statement *>* optional_statements;
	Statement_list(Statement*, int, int);
	Statement_list(int, int);
	void AddStatement_list(Statement*);
	virtual void accept(Visitor *);
};

class Variable : public Node
{
public:
	Ident *name;
	Expression *expression = NULL;
	Variable(Ident *, int, int);
	Variable(Ident *, Expression *, int, int);
	virtual void accept(Visitor *);
};

class Expression : public Node
{
public:
	int type=0;
	int value = 0;
	Expression(int, int);
	virtual void accept(Visitor *);
};

class ExpIdent : public Expression
{
public:

	Ident* name;
	ExpIdent(Ident*, int, int);

	virtual void accept(Visitor *);
};

class ExpInt : public Expression
{
public:
	int num;
	ExpInt(int, int, int);

	virtual void accept(Visitor *);
};

class ExpReal : public Expression
{
public:

	double num;
	ExpReal(double, int, int);

	virtual void accept(Visitor *);
};

class ExpChar : public Expression
{
public:

	char ch;
	ExpChar(char, int, int);

	virtual void accept(Visitor *);
};

class ExpStr : public Expression
{
public:

	string str;
	ExpStr(string, int, int);

	virtual void accept(Visitor *);
};

class ExpTrue : public Expression
{
public:
	ExpTrue(int, int);

	virtual void accept(Visitor *);
};

class ExpFalse : public Expression
{
public:
	ExpFalse(int, int);

	virtual void accept(Visitor *);
};

class ExpInner : public Expression
{
public:
	Ident *name;
	Expression_list *expression_list;
	Subprogram_head *func;
	ExpInner(Ident*, Expression_list *, int, int);

	virtual void accept(Visitor *);
};

class Expr : public Expression
{
public:
	Expression *expression;
	Expr(Expression*, int, int);
	virtual void accept(Visitor *);
};

class ExpOpt : public Expression
{
public:
	Expression *left;
	Expression *right;
	int op;
	ExpOpt(Expression*, int, Expression*, int, int);
	virtual void accept(Visitor *);
};

class ExpNot : public Expression
{
public:
	Expression *expression;
	ExpNot(Expression*, int, int);
	virtual void accept(Visitor *);
};

class Identifier_list : public Node
{
public:
	vector<Ident*>* idents;
	Identifier_list(int, int);
	Identifier_list(Ident*, int, int);
	void AddIdent(Ident*);
	virtual void accept(Visitor *);
};

class Type : public Node
{
public:
	int type = 0;
	int isArray = 0;
	ExpInt* beginning = NULL;
	ExpInt* end = NULL;
	Type(int, int);
	Type(int, int, int);
	virtual void accept(Visitor *);
};

class Array : public Type
{
public:
	//int type;
	Array(ExpInt*, ExpInt*, int, int, int);
	virtual void accept(Visitor *);
};

class Subprogram_declaration : public Node
{
public:
	Subprogram_head* subprogram_head;
	Compound_statement* compound_statement;
	Return_stmt* return_stmt;
	Subprogram_declaration(Subprogram_head*, Compound_statement*, Return_stmt*, int, int);
	virtual void accept(Visitor *);
};

class Subprogram_declarations : public Node
{
public:
	vector<Subprogram_declaration*>* subprogram_declarations;
	Subprogram_declarations(int, int);
	Subprogram_declarations(Subprogram_declaration*, int, int);
	void AddSubprogram_declaration(Subprogram_declaration*);
	virtual void accept(Visitor *);
};

class Procedure_statement : public Node
{
public:
	Ident* ident;
	Expression_list* expression_list = NULL;
	Procedure_statement(Ident*, int, int);
	Procedure_statement(Ident*, Expression_list*, int, int);
	virtual void accept(Visitor *);
};

class Expression_list : public Node
{
public:
	vector<Expression*>* expressions;
	Expression_list(int, int);
	Expression_list(Expression*, int, int);
	void AddExpression(Expression*);
	virtual void accept(Visitor *);
};

class Statement : public Node
{
public:
	Statement(int, int);
	virtual void accept(Visitor *);
};

class StmtAssign :public Statement
{
public:
	Variable* variable;
	Expression* expression;
	StmtAssign(Variable*, Expression*, int, int);
	virtual void accept(Visitor *);
};

class StmtProcedure : public Statement
{
public:
	Procedure_statement* procedure_statement;
	StmtProcedure(Procedure_statement*, int, int);
	virtual void accept(Visitor *);
};

class StmtCompound : public Statement
{
public:
	Compound_statement*  compound_statement;
	StmtCompound(Compound_statement*, int, int);
	virtual void accept(Visitor *);
};

class StmtIf : public Statement
{
public:
	Expression* expression;
	Compound_statement* statement_list;
	StmtIf(Expression*, Compound_statement*, int, int);
	virtual void accept(Visitor *);
};

class StmtIfElse : public Statement
{
public:
	Expression* expression;
	Compound_statement* statement_list1;
	Compound_statement* statement_list2;
	StmtIfElse(Expression*, Compound_statement*, Compound_statement*, int, int);
	virtual void accept(Visitor *);
};

class StmtWhile : public Statement
{
public:
	Expression* expression;
	Compound_statement* statement_list;
	StmtWhile(Expression*, Compound_statement*, int, int);
	virtual void accept(Visitor *);
};

class StmtFor : public Statement
{
public:
	ExpInt* int1 = NULL;
	ExpInt* int2 = NULL;
	ExpChar* char1 = NULL;
	ExpChar* char2 = NULL;
	Ident* ident;
	Compound_statement* statement_list;
	StmtFor(Ident*, ExpInt*, ExpInt*, Compound_statement*, int, int);
	StmtFor(Ident*, ExpChar*, ExpChar*, Compound_statement*, int, int);
	virtual void accept(Visitor *);
};

class StmtWriteStr : public Statement
{
public:
	ExpStr* str;
	StmtWriteStr(ExpStr*, int, int);
	virtual void accept(Visitor *);
};

class StmtWriteId : public Statement
{
public:
	Ident *name;
	StmtWriteId(Ident*, int, int);
	virtual void accept(Visitor *);
};

class StmtWriteExp : public Statement
{
public:
	Expression *left;
	int op;
	Expression *right;
	StmtWriteExp(Expression*, int, Expression*, int, int);
	virtual void accept(Visitor *);
};

class Compound_statement : public Node
{
public:
	Statement_list* statement_list;
	Compound_statement(Statement_list*, int, int);
	virtual void accept(Visitor *);
};

class Return_stmt : public Node
{
public:
	Variable* variable;
	Return_stmt(Variable*, int, int);
	Return_stmt( int, int);
    virtual void accept(Visitor *);
};
/////////visitor/////////////

class Visitor
{
public:
	virtual void Visit(Node*) = 0;
	virtual void Visit(Ident*) = 0;
	virtual void Visit(Program*) = 0;
	virtual void Visit(Declarations*) = 0;
	virtual void Visit(Function*) = 0;
	virtual void Visit(Procedure*) = 0;
	virtual void Visit(Identifier_list*) = 0;
	virtual void Visit(Type*) = 0;
	virtual void Visit(Arguments*) = 0;
	virtual void Visit(Parameter_list*) = 0;
	virtual void Visit(Statement*) = 0;
	virtual void Visit(Statement_list*) = 0;
	virtual void Visit(Variable*) = 0;
	virtual void Visit(Expression*) = 0;
	virtual void Visit(ExpIdent*) = 0;
	virtual void Visit(ExpInt*) = 0;
	virtual void Visit(ExpReal*) = 0;
	virtual void Visit(ExpChar*) = 0;
	virtual void Visit(ExpStr*) = 0;
	virtual void Visit(ExpTrue*) = 0;
	virtual void Visit(ExpFalse*) = 0;
	virtual void Visit(ExpInner*) = 0;
	virtual void Visit(Expr*) = 0;
	virtual void Visit(ExpOpt*) = 0;
	virtual void Visit(ExpNot*) = 0;
	virtual void Visit(Expression_list*) = 0;
	virtual void Visit(Subprogram_declarations*) = 0;
	virtual void Visit(Subprogram_declaration*) = 0;
	virtual void Visit(Subprogram_head*) = 0;
	virtual void Visit(Array*) = 0;
	virtual void Visit(Procedure_statement*) = 0;
	virtual void Visit(StmtAssign*) = 0;
	virtual void Visit(StmtProcedure*) = 0;
	virtual void Visit(StmtCompound*) = 0;
	virtual void Visit(Compound_statement*) = 0;
	virtual void Visit(StmtIf*) = 0;
	virtual void Visit(StmtIfElse*) = 0;
	virtual void Visit(StmtWhile*) = 0;
	virtual void Visit(StmtFor*) = 0;
	virtual void Visit(StmtWriteStr*) = 0;
	virtual void Visit(StmtWriteId*) = 0;
	virtual void Visit(StmtWriteExp*) = 0;
	virtual void Visit(Return_stmt*) = 0;

};


class PrintVisitor :public Visitor
{
public:
	virtual void Visit(Node*);
	virtual void Visit(Ident*);
	virtual void Visit(Program*);
	virtual void Visit(Declarations*);
	virtual void Visit(Function*);
	virtual void Visit(Procedure*);
	virtual void Visit(Identifier_list*);
	virtual void Visit(Type*);
	virtual void Visit(Arguments*);
	virtual void Visit(Parameter_list*);
	virtual void Visit(Statement*);
	virtual void Visit(Statement_list*);
	virtual void Visit(Variable*);
	virtual void Visit(Expression*);
	virtual void Visit(ExpIdent*);
	virtual void Visit(ExpInt*);
	virtual void Visit(ExpReal*);
	virtual void Visit(ExpChar*);
	virtual void Visit(ExpStr*);
	virtual void Visit(ExpTrue*);
	virtual void Visit(ExpFalse*);
	virtual void Visit(ExpInner*);
	virtual void Visit(Expr*);
	virtual void Visit(ExpOpt*);
	virtual void Visit(ExpNot*);
	virtual void Visit(Expression_list*);
	virtual void Visit(Subprogram_declarations*);
	virtual void Visit(Subprogram_declaration*);
	virtual void Visit(Subprogram_head*);
	virtual void Visit(Array*);
	virtual void Visit(Procedure_statement*);
	virtual void Visit(StmtAssign*);
	virtual void Visit(StmtProcedure*);
	virtual void Visit(StmtCompound*);
	virtual void Visit(Compound_statement*);
	virtual void Visit(StmtIf*);
	virtual void Visit(StmtIfElse*);
	virtual void Visit(StmtWhile*);
	virtual void Visit(StmtFor*);
	virtual void Visit(StmtWriteStr*);
	virtual void Visit(StmtWriteId*);
	virtual void Visit(StmtWriteExp*);
	virtual void Visit(Return_stmt*) ;

};


class TypeVisitor :public Visitor
{
public:
	string types[8];
	string operators[16];
	TypeVisitor();
	virtual void Visit(Node*);
	virtual void Visit(Ident*);
	virtual void Visit(Program*);
	virtual void Visit(Declarations*);
	virtual void Visit(Function*);
	virtual void Visit(Procedure*);
	virtual void Visit(Identifier_list*);
	virtual void Visit(Type*);
	virtual void Visit(Arguments*);
	virtual void Visit(Parameter_list*);
	virtual void Visit(Statement*);
	virtual void Visit(Statement_list*);
	virtual void Visit(Variable*);
	virtual void Visit(Expression*);
	virtual void Visit(ExpIdent*);
	virtual void Visit(ExpInt*);
	virtual void Visit(ExpReal*);
	virtual void Visit(ExpChar*);
	virtual void Visit(ExpStr*);
	virtual void Visit(ExpTrue*);
	virtual void Visit(ExpFalse*);
	virtual void Visit(ExpInner*);
	virtual void Visit(Expr*);
	virtual void Visit(ExpOpt*);
	virtual void Visit(ExpNot*);
	virtual void Visit(Expression_list*);
	virtual void Visit(Subprogram_declarations*);
	virtual void Visit(Subprogram_declaration*);
	virtual void Visit(Subprogram_head*);
	virtual void Visit(Array*);
	virtual void Visit(Procedure_statement*);
	virtual void Visit(StmtAssign*);
	virtual void Visit(StmtProcedure*);
	virtual void Visit(StmtCompound*);
	virtual void Visit(Compound_statement*);
	virtual void Visit(StmtIf*);
	virtual void Visit(StmtIfElse*);
	virtual void Visit(StmtWhile*);
	virtual void Visit(StmtFor*);
	virtual void Visit(StmtWriteStr*);
	virtual void Visit(StmtWriteId*);
	virtual void Visit(StmtWriteExp*);
	virtual void Visit(Return_stmt*) ;

};



///////////////////////////////symbol table classes/////////////////////////////////////////


class Symbol
{
public:
	string name;
	int type=0;
	int kind;
	int location;
	int begin = 0;
	int end = 0;
	Subprogram_head * function;
	Symbol(string, int, int, int, int);
	Symbol(string, int, int, Subprogram_head *);
};


class Scope
{
public:
	HashTab	*hashTab;
	Scope();
};



class SymbolTable
{
public:
	HashTab *hashTab;
	vector<Scope *> * scopes;
	string kindes[15];
	string types[15];
	Scope * current;
	//Errors * errors;
	SymbolTable();
	bool AddSymbol(Ident *, int, int, int, int);
	//bool AddArray(Ident *, int, int,int,int);
	Symbol * LookUpSymbol(Ident *);
	Symbol * LookUpFunc(Ident *, Expression_list *);
	bool AddFunc(Ident *, int kind, Arguments *, int type, Subprogram_head *);
	//Symbol * LookupConstructor(Id *);
	void NewScope();
	void CloseScope();
};




//////////////////////////////////code generation/////////////////////////////


class CodeVisitor :public Visitor
{
public:
	//CodeVisitor();
	int f = 0;
	int fp = -1;
	int gp = 999;
	int label_if=0;
	int label_else = 0;
	int label_while = 0;
	int label_for = 0;
	virtual void Visit(Node*);
	virtual void Visit(Ident*);
	virtual void Visit(Program*);
	virtual void Visit(Declarations*);
	virtual void Visit(Function*);
	virtual void Visit(Procedure*);
	virtual void Visit(Identifier_list*);
	virtual void Visit(Type*);
	virtual void Visit(Arguments*);
	virtual void Visit(Parameter_list*);
	virtual void Visit(Statement*);
	virtual void Visit(Statement_list*);
	virtual void Visit(Variable*);
	virtual void Visit(Expression*);
	virtual void Visit(ExpIdent*);
	virtual void Visit(ExpInt*);
	virtual void Visit(ExpReal*);
	virtual void Visit(ExpChar*);
	virtual void Visit(ExpStr*);
	virtual void Visit(ExpTrue*);
	virtual void Visit(ExpFalse*);
	virtual void Visit(ExpInner*);
	virtual void Visit(Expr*);
	virtual void Visit(ExpOpt*);
	virtual void Visit(ExpNot*);
	virtual void Visit(Expression_list*);
	virtual void Visit(Subprogram_declarations*);
	virtual void Visit(Subprogram_declaration*);
	virtual void Visit(Subprogram_head*);
	virtual void Visit(Array*);
	virtual void Visit(Procedure_statement*);
	virtual void Visit(StmtAssign*);
	virtual void Visit(StmtProcedure*);
	virtual void Visit(StmtCompound*);
	virtual void Visit(Compound_statement*);
	virtual void Visit(StmtIf*);
	virtual void Visit(StmtIfElse*);
	virtual void Visit(StmtWhile*);
	virtual void Visit(StmtFor*);
	virtual void Visit(StmtWriteStr*);
	virtual void Visit(StmtWriteId*);
	virtual void Visit(StmtWriteExp*);
	virtual void Visit(Return_stmt*) ;


};
