#include "ast.h"
extern SymbolTable * symbolTable;
extern int error;
extern int symErr;
extern int fErr;

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;
}
Ident::Ident(string s, int l, int c) : Node(l, c)
{
	this->name = s;
	this->symbol = NULL;
}
Program::Program(Ident *id, Declarations*d, Subprogram_declarations*sd, Compound_statement*cs, int l, int c) : Node(l, c)
{
	this->name = id;
	this->declarations = d;
	this->subprogram_declarations = sd;
	this->compound_statement = cs;
	id->father = this;
	d->father = this;
	sd->father = this;
	cs->father = this;
}

Declarations::Declarations(Identifier_list * il, Type* t, int l, int c) : Node(l, c)
{
	this->identifier_list = new vector<Identifier_list*>;
	this->type = new vector<Type*>;
	this->AddDeclarations(il, t);
}
Declarations::Declarations(int l, int c) : Node(l, c)
{
	this->identifier_list = NULL;
	this->type = NULL;
}
void Declarations::AddDeclarations(Identifier_list *i, Type *t)
{
	this->identifier_list->push_back(i);
	this->type->push_back(t);
	i->father = this;
	t->father = this;
}
Subprogram_head::Subprogram_head(int l, int c) : Node(l, c)
{

}
Function::Function(int s, Ident *id, Arguments *ar, Declarations *d, int l, int c) : Subprogram_head(l, c)
{
	this->standard = s;
	this->arg = ar;
	this->name = id;
	this->declarations = d;
	ar->father = this;
	d->father = this;
	id->father = this;
}
Procedure::Procedure(Ident *id, Arguments *ar, Declarations *d, int l, int c) : Subprogram_head(l, c)
{
	this->arg = ar;
	this->name = id;
	this->declarations = d;
	ar->father = this;
	d->father = this;
	id->father = this;
}
Arguments::Arguments(Parameter_list *p, int l, int c) : Node(l, c)
{
	this->parameter_list = p;
	p->father = this;
}
Arguments::Arguments(int l, int c) : Node(l, c)
{
	this->parameter_list = NULL;
}
Parameter_list::Parameter_list(Identifier_list * il, Type* t, int l, int c) : Node(l, c)
{
	this->identifier_list = new vector<Identifier_list*>;
	this->type = new vector<Type*>;
	this->AddParameter_list(il, t);
}
void Parameter_list::AddParameter_list(Identifier_list *i, Type *t)
{
	this->identifier_list->push_back(i);
	this->type->push_back(t);
	i->father = this;
	t->father = this;
}

Statement_list::Statement_list(Statement* os, int l, int c) : Node(l, c)
{
	this->optional_statements = new vector<Statement*>;
	this->AddStatement_list(os);
}
Statement_list::Statement_list(int l, int c) : Node(l, c)
{
	this->optional_statements = NULL;
}
void Statement_list::AddStatement_list(Statement *os)
{
	this->optional_statements->push_back(os);
	os->father = this;
}

Variable::Variable(Ident *id, int l, int c) : Node(l, c)
{
	this->name = id;
	id->father = this;
}

Variable::Variable(Ident *id, Expression* ex, int l, int c) : Node(l, c)
{
	this->name = id;
	this->expression = ex;
	id->father = this;
}

Expression::Expression(int l, int c) :Node(l, c)
{

}

ExpIdent::ExpIdent(Ident* id, int l, int c) : Expression(l, c)
{
	this->name = id;
	id->father = this;
}

ExpInt::ExpInt(int n, int l, int c) : Expression(l, c)
{
	this->num = n;
}

ExpReal::ExpReal(double n, int l, int c) : Expression(l, c)
{
	this->num = n;
}

ExpChar::ExpChar(char n, int l, int c) : Expression(l, c)
{
	this->ch = n;
}

ExpStr::ExpStr(string n, int l, int c) : Expression(l, c)
{
	this->str = n;
}

ExpTrue::ExpTrue(int l, int c) : Expression(l, c)
{
}

ExpFalse::ExpFalse(int l, int c) : Expression(l, c)
{
}

ExpInner::ExpInner(Ident* id, Expression_list *el, int l, int c) : Expression(l, c)
{
	this->name = id;
	this->expression_list = el;
	id->father = this;
	el->father = this;
}

Expr::Expr(Expression*e, int l, int c) : Expression(l, c)
{
	this->expression = e;
	e->father = this;
}

ExpOpt::ExpOpt(Expression* lef, int op, Expression* r, int l, int c) : Expression(l, c)
{
	this->left = lef;
	this->right = r;
	this->op = op;
	lef->father = this;
	r->father = this;
}

ExpNot::ExpNot(Expression * ex, int l, int c) : Expression(l, c)
{
	this->expression = ex;
	ex->father = this;
}


Identifier_list::Identifier_list(int l, int c) : Node(l, c)
{
	this->idents = new vector<Ident*>;
}
Identifier_list::Identifier_list(Ident* ident, int l, int c) : Node(l, c)
{
	this->idents = new vector<Ident*>;
	this->AddIdent(ident);
}
void
Identifier_list::AddIdent(Ident* ident)
{
	this->idents->push_back(ident);
	ident->father = this;
}

Type::Type(int type, int l, int c) : Node(l, c)
{
	this->type = type;
}

Type::Type(int l, int c) : Node(l, c)
{

}

Array::Array(ExpInt* beginning, ExpInt* end, int type, int l, int c) : Type(l, c)
{
	this->isArray = 1;
	this->type = type;
	this->beginning = beginning;
	this->end = end;
	//this->type = type;
	beginning->father = this;
	end->father = this;
}

Subprogram_declaration::Subprogram_declaration(Subprogram_head* sh, Compound_statement* cs,Return_stmt* re, int c, int l)
	: Node(l, c)
{
	this->subprogram_head = sh;
	this->compound_statement = cs;
	this->return_stmt = re;
	re->father = this;
	sh->father = this;
	cs->father = this;
}

Subprogram_declarations::Subprogram_declarations(int l, int c) : Node(l, c)
{
	this->subprogram_declarations = new vector<Subprogram_declaration*>;
}
Subprogram_declarations::Subprogram_declarations(Subprogram_declaration* sd, int l, int c) : Node(l, c)
{
	this->subprogram_declarations = new vector<Subprogram_declaration*>;
	this->AddSubprogram_declaration(sd);
}
void
Subprogram_declarations::AddSubprogram_declaration(Subprogram_declaration* sd)
{
	this->subprogram_declarations->push_back(sd);
	sd->father = this;
}

Procedure_statement::Procedure_statement(Ident* id, int l, int c) : Node(l, c)
{
	this->ident = id;
}
Procedure_statement::Procedure_statement(Ident* id, Expression_list* el, int l, int c) : Node(l, c)
{
	this->ident = id;
	this->expression_list = el;
}

Expression_list::Expression_list(int l, int c) : Node(l, c)
{
	this->expressions = new vector<Expression*>;
}
Expression_list::Expression_list(Expression* ex, int l, int c) : Node(l, c)
{
	this->expressions = new vector<Expression*>;
	this->AddExpression(ex);
}
void
Expression_list::AddExpression(Expression* ex)
{
	this->expressions->push_back(ex);
	ex->father = this;
}

Statement::Statement(int l, int c) :Node(l, c)
{

}

StmtAssign::StmtAssign(Variable* var, Expression* ex, int l, int c) : Statement(l, c)
{
	this->variable = var;
	this->expression = ex;
	var->father = this;
	ex->father = this;
}

StmtProcedure::StmtProcedure(Procedure_statement* procStmt, int l, int c) :Statement(l, c)
{
	this->procedure_statement = procStmt;
	procStmt->father = this;
}

StmtCompound::StmtCompound(Compound_statement* cs, int l, int c) :Statement(l, c)
{
	this->compound_statement = cs;
	cs->father = this;
}

StmtIf::StmtIf(Expression* ex, Compound_statement* stmtlist, int l, int c) :Statement(l, c)
{
	this->expression = ex;
	this->statement_list = stmtlist;
	ex->father = this;
	stmtlist->father = this;
}

StmtIfElse::StmtIfElse(Expression* ex, Compound_statement* st1, Compound_statement* st2, int l, int c) :Statement(l, c)
{
	this->expression = ex;
	this->statement_list1 = st1;
	this->statement_list2 = st2;
	ex->father = this;
	st1->father = this;
	st2->father = this;
}

StmtWhile::StmtWhile(Expression* ex, Compound_statement* stmtlist, int l, int c) :Statement(l, c)
{
	this->expression = ex;
	this->statement_list = stmtlist;
	ex->father = this;
	stmtlist->father = this;
}

StmtFor::StmtFor(Ident* ident, ExpChar* char1, ExpChar* char2, Compound_statement* stmtlist, int l, int c) :Statement(l, c)
{
	this->char1 = char1;
	this->char2 = char2;
	this->statement_list = stmtlist;
	this->ident = ident;
	ident->father = this;
	char1->father = this;
	char2->father = this;
	stmtlist->father = this;
}

StmtFor::StmtFor(Ident* ident, ExpInt* int1, ExpInt* int2, Compound_statement* stmtlist, int l, int c) :Statement(l, c)
{
	this->int1 = int1;
	this->int2 = int2;
	this->statement_list = stmtlist;
	this->ident = ident;
	ident->father = this;
	int1->father = this;
	int2->father = this;
	stmtlist->father = this;
}

StmtWriteStr::StmtWriteStr(ExpStr* s, int l, int c) :Statement(l, c)
{
	this->str = s;
	s->father = this;
}

StmtWriteId::StmtWriteId(Ident * id, int l, int c) : Statement(l, c)
{
	this->name = id;
	id->father = this;
}

StmtWriteExp::StmtWriteExp(Expression* lef, int op, Expression* r, int l, int c) : Statement(l, c)
{
	this->left = lef;
	this->right = r;
	this->op = op;
	lef->father = this;
	r->father = this;
}

Compound_statement::Compound_statement(Statement_list* s, int l, int c) : Node(l, c)
{
	this->statement_list = s;
	s->father = this;
}


Return_stmt::Return_stmt(Variable* v, int l, int c) : Node(l, c)
{
	this->variable = v;
	v->father = this;
}

Return_stmt::Return_stmt( int l, int c) : Node(l, c)
{
	this->variable = NULL;
}
/////////////////visitor////////////////////


void
Node::accept(Visitor *v)
{
	v->Visit(this);
}
void
Ident::accept(Visitor *v)
{
	v->Visit(this);
}
void
Program::accept(Visitor *v)
{
	v->Visit(this);
}
void
Declarations::accept(Visitor *v)
{
	v->Visit(this);
}
void
Function::accept(Visitor *v)
{
	v->Visit(this);
}
void
Procedure::accept(Visitor *v)
{
	v->Visit(this);
}
void
Identifier_list::accept(Visitor *v)
{
	v->Visit(this);
}
void
Type::accept(Visitor *v)
{
	v->Visit(this);
}
void
Arguments::accept(Visitor *v)
{
	v->Visit(this);
}
void
Parameter_list::accept(Visitor *v)
{
	v->Visit(this);
}
void
Statement::accept(Visitor *v)
{
	v->Visit(this);
}
void
Statement_list::accept(Visitor *v)
{
	v->Visit(this);
}
void
Variable::accept(Visitor *v)
{
	v->Visit(this);
}
void
Expression::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpIdent::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpInt::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpReal::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpChar::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpStr::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpTrue::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpFalse::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpInner::accept(Visitor *v)
{
	v->Visit(this);
}
void
Expr::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpOpt::accept(Visitor *v)
{
	v->Visit(this);
}
void
ExpNot::accept(Visitor *v)
{
	v->Visit(this);
}
void
Expression_list::accept(Visitor *v)
{
	v->Visit(this);
}
void
Subprogram_declarations::accept(Visitor *v)
{
	v->Visit(this);
}
void
Subprogram_declaration::accept(Visitor *v)
{
	v->Visit(this);
}
void
Subprogram_head::accept(Visitor *v)
{
	v->Visit(this);
}
void
Array::accept(Visitor *v)
{
	v->Visit(this);
}
void
Procedure_statement::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtAssign::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtProcedure::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtCompound::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtIf::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtIfElse::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtWhile::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtFor::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtWriteStr::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtWriteId::accept(Visitor *v)
{
	v->Visit(this);
}
void
StmtWriteExp::accept(Visitor *v)
{
	v->Visit(this);
}
void
Compound_statement::accept(Visitor *v)
{
	v->Visit(this);
}
void
Return_stmt::accept(Visitor *v)
{
	v->Visit(this);
}


//////////////////////////print visitor//////////////////////////////

void
PrintVisitor::Visit(Node*n)
{
}
void
PrintVisitor::Visit(Ident*n)
{
	cout << n->name;
}
void
PrintVisitor::Visit(Program*n)
{
	cout << "This is the Program:";
	n->name->accept(this);
	cout << endl;
	n->declarations->accept(this);
	cout << endl;
	n->subprogram_declarations->accept(this);
	n->compound_statement->accept(this);
	//n->accept(this);
}
/*void
PrintVisitor::Visit(Right_program*n)
{
cout << "the number of subprograms is :" << n->subprogram_declarations->size() << endl;
for (int i = 0; i < n->subprogram_declarations->size(); i++) {
n->declarations->at(i)->accept(this);
n->subprogram_declarations->at(i)->accept(this);
n->compound_statement->at(i)->accept(this);
}
n->accept(this);
}*/
void
PrintVisitor::Visit(Declarations*n)
{
	//for (int i = 0; i < n->identifier_list->size(); i++)
	//{
	//	cout << "the type of identifier variables ";
	//	for (int j = 0; j < n->identifier_list->at(i)->idents->size(); j++)
	//		cout << n->identifier_list->at(i)->idents->at(j)->name << ", ";
	//	cout << "is " << n->type->at(i)->type << endl;
	//}
	//for (int i = 0; i < n->identifier_list->size(); i++)
	//{
	//	n->identifier_list->at(i)->accept(this);
	//	n->type->at(i)->accept(this);
	//}
	cout << "the variables declared in this subprogram " << endl;
	for (int i = 0; i < int(n->identifier_list->size()); i++)
	{
		n->identifier_list->at(i)->accept(this);
		cout << "of type: ";
		n->type->at(i)->accept(this);
		cout << endl;
	}
	//n->accept(this);
}
void
PrintVisitor::Visit(Function*n)
{
	cout << "the name of function is ";
	n->name->accept(this);
	cout << endl;
	cout << "the return type of previous function is " << n->standard << endl;
	cout << "the arguments of function are " << endl;
	/*for (int i = 0; i < n->arg->parameter_list->identifier_list->size(); i++)
	{
	for (int j = 0; j < n->arg->parameter_list->identifier_list->at(i)->idents->size(); j++)
	{
	cout << n->arg->parameter_list->identifier_list->at(i)->idents->at(j)->name << ", ";
	}
	cout << " of type: " << n->arg->parameter_list->type->at(i)->type << endl;
	}*/
	n->arg->accept(this);
	//n->accept(this);
	n->declarations->accept(this);

}
void
PrintVisitor::Visit(Procedure*n)
{
	cout << "the name of procedure is ";
	n->name->accept(this);
	cout << endl;
	cout << "the arguments of procedure are " << endl;
	//for (int i = 0; i < n->arg->parameter_list->identifier_list->size(); i++)
	//{
	//	for (int j = 0; j < n->arg->parameter_list->identifier_list->at(i)->idents->size(); j++)
	//	{
	//		cout << n->arg->parameter_list->identifier_list->at(i)->idents->at(j)->name << ", ";
	//	}
	//	cout << " of type: " << n->arg->parameter_list->type->at(i)->type << endl;
	//}
	n->arg->accept(this);
	//n->accept(this);
	n->declarations->accept(this);
}


void
PrintVisitor::Visit(Identifier_list*n)
{
	cout << "names of idntifiers :";
	//for (int i = 0; i < n->idents->size(); i++) {
	//	cout << n->idents->at(i)->name << ", ";
	//}
	//for (int i = 0; i < n->idents->size(); i++) {
	//	n->idents->at(i)->accept(this);
	//}
	for (int i = 0; i < int(n->idents->size()); i++) {
		n->idents->at(i)->accept(this);
		cout << ", ";
	}
	//n->accept(this);
}
void
PrintVisitor::Visit(Type*n)
{
	cout << n->type;
	//n->accept(this);
}
void
PrintVisitor::Visit(Arguments*n)
{
	n->parameter_list->accept(this);
	//n->accept(this);
}
void
PrintVisitor::Visit(Parameter_list*n)
{
	for (int i = 0; i < int(n->identifier_list->size()); i++)
	{
		n->identifier_list->at(i)->accept(this);
		cout << "of type:" << n->type->at(i)->type << endl;
	}
	//n->accept(this);
}
void
PrintVisitor::Visit(Statement*n)
{
	//n->accept(this);
}
void
PrintVisitor::Visit(Statement_list*n)
{
	for (int i = 0; i < n->optional_statements->size(); i++)
	{
		n->optional_statements->at(i)->accept(this);
	}
	//n->accept(this);
}
void
PrintVisitor::Visit(Variable*n)
{
	cout << "the variable is ";
	n->name->accept(this);
	if (n->expression != NULL)
	{
		n->expression->accept(this);
	}
}
void
PrintVisitor::Visit(Expression*n)
{
	n->accept(this);
}
void
PrintVisitor::Visit(ExpIdent*n)
{
	n->name->accept(this);
}
void
PrintVisitor::Visit(ExpInt*n)
{
	cout << n->num << " ";
}
void
PrintVisitor::Visit(ExpReal*n)
{
	cout << n->num << " ";
}
void
PrintVisitor::Visit(ExpChar*n)
{
	cout << n->ch << " ";
}
void
PrintVisitor::Visit(ExpStr*n)
{
	cout << n->str << " ";
}
void
PrintVisitor::Visit(ExpTrue*n)
{
	cout << "true ";
}
void
PrintVisitor::Visit(ExpFalse*n)
{
	cout << "false ";
}
void
PrintVisitor::Visit(ExpInner*n)
{
	cout << "the name of expression is ";
	n->name->accept(this);
	n->expression_list->accept(this);
}
void
PrintVisitor::Visit(Expr*n)
{
	cout << "( ";
	n->expression->accept(this);
	cout << " )";
}
void
PrintVisitor::Visit(ExpOpt*n)
{
	n->left->accept(this);
	cout << " the unary operator is" << n->op << " ";
	n->right->accept(this);
}
void
PrintVisitor::Visit(ExpNot*n)
{
	cout << "not ";
	n->expression->accept(this);
}
void
PrintVisitor::Visit(Expression_list*n)
{
	cout << " ( ";
	for (int i = 0; i < int(n->expressions->size()); i++)
	{
		n->expressions->at(i)->accept(this);
		cout << ", ";
	}
}
void
PrintVisitor::Visit(Subprogram_declarations*n)
{
	for (int i = 0; i <int(n->subprogram_declarations->size()); i++)
	{
		n->subprogram_declarations->at(i)->accept(this);
	}
}
void
PrintVisitor::Visit(Subprogram_declaration*n)
{
	n->subprogram_head->accept(this);
	n->compound_statement->accept(this);
	if (n->return_stmt != NULL)
	{
		n->return_stmt->accept(this);
	}
}
void
PrintVisitor::Visit(Return_stmt*n)
{
	cout << "return ";
	n->variable->accept(this);
}
void
PrintVisitor::Visit(Subprogram_head*n)
{
}
void
PrintVisitor::Visit(Array*n)
{
	cout << "the beginning of array is " << n->beginning;
	cout << "the end of array is " << n->end;
	cout << "the type of elements in array is " << n->type;
	//n->accept(this);
}
void
PrintVisitor::Visit(Procedure_statement*n)
{
	cout << "the Procedure statement is ";
	n->ident->accept(this);
	if (n->expression_list != NULL)
	{
		n->expression_list->accept(this);
	}
}
void
PrintVisitor::Visit(StmtAssign*n)
{
	n->variable->accept(this);
	cout << " = (";
	n->expression->accept(this);
	cout << " )";
}
void
PrintVisitor::Visit(StmtProcedure*n)
{
	n->procedure_statement->accept(this);
}
void
PrintVisitor::Visit(StmtCompound*n)
{
	n->compound_statement->accept(this);
}
void
PrintVisitor::Visit(Compound_statement*n)
{

	n->statement_list->accept(this);
}
void
PrintVisitor::Visit(StmtIf*n)
{
	cout << "if ";
	n->expression->accept(this);
	cout << " then " << endl;
	n->statement_list->accept(this);
	cout << endl;
	cout << "end if";
}
void
PrintVisitor::Visit(StmtIfElse*n)
{
	cout << "if ";
	n->expression->accept(this);
	cout << " then " << endl;
	n->statement_list1->accept(this);
	cout << endl;
	cout << "end if" << endl;
	cout << "else" << endl;
	n->statement_list2->accept(this);
	cout << "end else " << endl;
}
void
PrintVisitor::Visit(StmtWhile*n)
{
	cout << "while ";
	n->expression->accept(this);
	cout << endl << "do ";
	n->statement_list->accept(this);
	cout << endl;
	cout << "end while" << endl;
}
void
PrintVisitor::Visit(StmtFor*n)
{
	cout << "for ";
	n->ident->accept(this);
	if (n->int1 != NULL)
	{
		cout << " =" << n->int1;
		cout << " to ";
		cout << n->int2 << " do";
	}
	else
	{
		cout << " =" << n->char1;
		cout << " to ";
		cout << n->char2 << " do";
	}

	n->statement_list->accept(this);
}
void
PrintVisitor::Visit(StmtWriteStr*n)
{
	cout << "write (";
	cout << n->str << " )";
}
void
PrintVisitor::Visit(StmtWriteId*n)
{
	cout << "write (";
	n->name->accept(this);
	cout << " )";
}
void
PrintVisitor::Visit(StmtWriteExp*n)
{
	cout << "write (";
	n->left->accept(this);
	cout << " " << n->op << " ";
	n->right->accept(this);
	cout << " )";
}


/////////////////////////////////////////// type visitor //////////////////////////////////////////

TypeVisitor::TypeVisitor()
{
	types[1] = "int";
	types[2] = "real";
	types[3] = "boolean";
	types[4] = "char";
	types[5] = "string";
	types[6] = "null";

	operators[1] = "+";
	operators[2] = "-";
	operators[3] = "*";
	operators[4] = "/";
	operators[5] = "div";
	operators[6] = "<";
	operators[7] = ">";
	operators[8] = "<=";
	operators[9] = ">=";
	operators[10] = "=";
	operators[11] = "<>";
	operators[12] = "and";
	operators[13] = "or";
}


void
TypeVisitor::Visit(Node*n)
{
}
void
TypeVisitor::Visit(Ident*n)
{

}
void
TypeVisitor::Visit(Program*n)
{
	n->name->accept(this);
	n->declarations->accept(this);
	n->subprogram_declarations->accept(this);
	n->compound_statement->accept(this);
	//n->accept(this);
}

void
TypeVisitor::Visit(Declarations*n)
{
	if (n->identifier_list != NULL)
	{
		for (int i = 0; i < int(n->identifier_list->size()); i++)
		{
			n->identifier_list->at(i)->accept(this);
			n->type->at(i)->accept(this);
		}
	}

}
void
TypeVisitor::Visit(Function*n)
{

	n->name->accept(this);
	n->arg->accept(this);
	//n->accept(this);
	n->declarations->accept(this);

}
void
TypeVisitor::Visit(Procedure*n)
{
	n->name->accept(this);
	n->arg->accept(this);
	n->declarations->accept(this);
}


void
TypeVisitor::Visit(Identifier_list*n)
{

	for (int i = 0; i < int(n->idents->size()); i++) {
		n->idents->at(i)->accept(this);
	}

	//n->accept(this);
}
void
TypeVisitor::Visit(Type*n)
{
	//n->accept(this);
}
void
TypeVisitor::Visit(Arguments*n)
{
	n->parameter_list->accept(this);
	//n->accept(this);
}
void
TypeVisitor::Visit(Parameter_list*n)
{

	for (int i = 0; i < int(n->identifier_list->size()); i++)
	{
	
		n->identifier_list->at(i)->accept(this);
		n->type->at(i)->accept(this);
	}

	//n->accept(this);
}
void
TypeVisitor::Visit(Statement*n)
{

}
void
TypeVisitor::Visit(Statement_list*n)
{

	if (n->optional_statements != NULL)
	{
		for (int i = 0; i < n->optional_statements->size(); i++)
		{
			n->optional_statements->at(i)->accept(this);
		}
	}
	//n->accept(this);
}
void
TypeVisitor::Visit(Variable*n)
{
	n->name->accept(this);
	
	if (n->expression != NULL&&n->name != NULL)
	{
		n->expression->accept(this);
		int type = n->expression->type;
		if (type != 1)
		{
			cout << "ERROR: index of array must be integer in line" << n->name->line << endl;
			error = 1;
		}
		else
		{
			int begin = n->name->symbol->begin;
			int end = n->name->symbol->end;
			if (n->expression->value <begin || n->expression->value >end)
			{
				cout << "ERROR: Array out of index: the index must be between " << begin << " and " << end << " in line " << n->name->line << endl;
				error = 1;
			}

		}
	}
}
void
TypeVisitor::Visit(Expression*n)
{

	n->accept(this);
}
void
TypeVisitor::Visit(ExpIdent*n)
{

	n->name->accept(this);
	n->type = n->name->symbol->type;///////////////////////////////////////////////////

}
void
TypeVisitor::Visit(ExpInt*n)
{
	n->type = 1;
	n->value = n->num;
}
void
TypeVisitor::Visit(ExpReal*n)
{

	n->type = 2;
}
void
TypeVisitor::Visit(ExpChar*n)
{

	n->type = 4;
}
void
TypeVisitor::Visit(ExpStr*n)
{

	n->type = 5;
}
void
TypeVisitor::Visit(ExpTrue*n)
{

	n->type = 3;
}
void
TypeVisitor::Visit(ExpFalse*n)
{

	n->type = 3;
}
void
TypeVisitor::Visit(ExpInner*n)
{
	n->name->accept(this);
	
	if (n->expression_list != NULL)
	{
		n->expression_list->accept(this);
		string key;
		Symbol *sym;
		key = "g" + n->name->name;
		for (int i = 0; i < (int)(n->expression_list->expressions->size()); i++)
		{
			int e = n->expression_list->expressions->at(i)->type;
			key += "@" + types[e];
		}
		sym = symbolTable->scopes->at(0)->hashTab->GetMember(key);
		if (sym != NULL && sym->type!=0)
		{
			
			n->name->symbol = sym;
			n->type = sym->type;
			n->func = sym->function; ////////////////////////////

		}
		else
		{
			cout << "no such function " << n->name->name << " in line: " << n->name->line << endl;
			error = 1;
			fErr = 1;

		}

	}
}
void
TypeVisitor::Visit(Expr*n)
{
	n->expression->accept(this);
	n->type = n->expression->type;
}
void
TypeVisitor::Visit(ExpOpt*n)
{
	n->left->accept(this);
	n->right->accept(this);

	// type int: 1, double:2, boolean:3
	int left = n->left->type;
	int right = n->right->type;

	if (n->op == 1||n->op==2)    //add and sub
	{
		if (left == 1 && right == 1)
			n->type = 1;
		else if (left == 2 && right == 2)
		{
			n->type = 2;
		}
		else if (left == 1 && right == 2
			|| left == 2 && right == 1)
		{
			n->type = 2;
			n->left->type = 2;
			n->right->type = 2;
		}
		else if (left == 4 && right == 5 || left == 5 && right == 4)
		{
			n->type = 5;
		}
		else if (((left == 1 || left == 2 || left == 3) && (right == 4 || right == 5)) || ((right == 1 || right == 2 || right == 3) && (left == 4 || left == 5)))
		{
			cout << "you can not add " << types[n->left->type] << " and " << types[n->right->type] <<" in line "<<n->left->line<< endl;
			error = 1;
		}
	}
	else if (n->op == 3 || n->op == 4 || n->op == 5)
	{
		if (left == 1 && right == 1)
		{
			n->type = 1;
		}
		else if (left == 2 && right == 2)
		{
			n->type = 2;
		}
		else if (left == 1 && right == 2 || left == 2 && right == 1)
		{
			n->type = 2;
		}
		else
		{
			if (n->op == 3)
			{
				cout << "you can not multiply " << types[n->left->type] << " and " << types[n->right->type] << " in line " << n->left->line << endl;
				error = 1;
			}
			else
			{
				cout << "you can not divide " << types[n->left->type] << " and " << types[n->right->type] << " in line " << n->left->line << endl;
				error = 1;

			}
		}
	}
	else if (n->op == 12 || n->op == 13) //and or
	{
		if (left == 3 && right == 3)
		{
			n->type == 3;
		}
		else
		{
			cout << "you can not make AND or OR between " << types[n->left->type] << " and " << types[n->right->type] << " in line " << n->left->line << endl;
			error = 1;

		}
	}
	else if (n->op >= 6 && n->op <= 9)
	{
		if (left == right)
		{
			n->type = 3;
		}
		else if ((left == 1 && right == 2) || (left == 2 && right == 1)||(left==4&&right==5)||(left == 5 && right == 4))
		{
			n->type = 3;
		}
		else
		{
			cout << "you can not compare " << types[n->left->type] << " and " << types[n->right->type] << " in line " << n->left->line << endl;
			error = 1;

		}

	}
	else if (n->op == 10 || n->op == 11)
	{
		if (left == right)
		{
			n->type = 3;
		}
		else
		{
			cout << "you can not compare " << types[n->left->type] << " and " << types[n->right->type] << " in line " << n->left->line << endl;
			error = 1;

		}
	}
      
}
void
TypeVisitor::Visit(ExpNot*n)
{ 
	n->expression->accept(this);
	if (n->expression->type != 3)
	{
		cout << "you can not negate " << types[n->expression->type]  << endl;
		error = 1;

	}
	else
	{
		n->type = 3;
	}
}
void
TypeVisitor::Visit(Expression_list*n)
{

	for (int i = 0; i < int(n->expressions->size()); i++)
	{
		n->expressions->at(i)->accept(this);
	}
}
void
TypeVisitor::Visit(Subprogram_declarations*n)
{
	for (int i = 0; i <int(n->subprogram_declarations->size()); i++)
	{
		n->subprogram_declarations->at(i)->accept(this);
	}
}
void
TypeVisitor::Visit(Subprogram_declaration*n)
{
	n->subprogram_head->accept(this);
	n->compound_statement->accept(this);
	n->return_stmt->accept(this);
	int typ = n->subprogram_head->name->symbol->type;
	if (typ == 0 && n->return_stmt->variable != NULL)
	{
		cout << "Error: procedure "<<n->subprogram_head->name->symbol->name<<" don't have to return value" << endl;
		error = 1;


	}
	else if (typ != 0 && n->return_stmt->variable == NULL)
	{
		cout << "Error: the function " << n->subprogram_head->name->symbol->name << " must return " << types[typ] << " value" <<endl;
		error = 1;
	}
	else if (typ != n->return_stmt->variable->name->symbol->type )
	{
		cout << "Error: the function " << n->subprogram_head->name->symbol->name << " must return " << types[typ] << " NOT " << types[n->return_stmt->variable->name->symbol->type] << endl;
		error = 1;

	}
}
void
TypeVisitor::Visit(Return_stmt *n)
{
	if (n->variable != NULL)
	{
		n->variable->accept(this);
		int type = n->variable->name->symbol->type;

	}
}
void
TypeVisitor::Visit(Subprogram_head*n)
{

	n->accept(this);
	//////////////////// function and procedure /////////////////// 
}
void
TypeVisitor::Visit(Array*n)
{

}

void
TypeVisitor::Visit(Procedure_statement*n)
{
	n->ident->accept(this);
	if (n->expression_list != NULL)
	{
		n->expression_list->accept(this);
//		cout << n->ident->symbol->function->name;
		//	cout << n->ident->symbol->function->arg->parameter_list->type->size();
	/*    for (int i = 0; i < (int)(n->ident->symbol->function->arg->parameter_list->type->size()); i++)
		   {
		     for (int j = 0; j < (int)(n->ident->symbol->function->arg->parameter_list->identifier_list->at(i)->idents->size()); j++)
		        {
		          if (n->ident->symbol->function->arg->parameter_list->type->at(i )->type != n->expression_list->expressions->at(i + j)->type)
		          cout << "no such function " << n->ident->name << " in line: " << n->ident->line << endl;
		        }
		   }*/
		//string key;
		////key = kindes[3] + id->name;
		//Symbol *sym;
		////cout << this->scopes-> <<endl;
		//key = "g" + n->ident->name;
		//for (int i = 0; i < (int)(n->expression_list->expressions->size()); i++)
		//{
		//	int e = n->expression_list->expressions->at(i)->type;
		//	key += "@" + types[e];
		//	cout << key << endl;
		//}
		//symbol* sym = this->current->hashTab->GetMember(key);
		//if (sym != NULL)
		//{
		//	ident->symbol = sym;
		//	return sym;
		//}
		//else
		//{
		//	cout << "no such function " << ident->name << " in line: " << ident->line << endl;

		//}

		string key;
		Symbol *sym;
		key = "g" + n->ident->name;
		for (int i = 0; i < (int)(n->expression_list->expressions->size()); i++)
		{
			int e = n->expression_list->expressions->at(i)->type;
			key += "@" + types[e];
		}
		sym = symbolTable->scopes->at(0)->hashTab->GetMember(key);
		if (sym != NULL)
		{
			if (sym->type != 0)
			{
				error = 1;
				cout << "ERROR: you must assign the return value of function " << n->ident->name << " to variable in line: " << n->ident->line << endl;
			}
			else
			{
				n->ident->symbol = sym;
			}
		}
		else
		{
			error = 1;
			cout << "no such procedure " << n->ident->name << " in line: " << n->ident->line << endl;

		}
		
	}
	
}
void
TypeVisitor::Visit(StmtAssign*n)
{
	n->variable->accept(this);
	n->expression->accept(this);
	if (n->variable->name->symbol != NULL&&n->expression->type!=0)
	{
		int left = n->variable->name->symbol->type;
		int right = n->expression->type;
		if ((left == 2 && (right == 3 || right == 4 || right == 5))
			|| (left == 1 && right != 1)
			|| (left == 3 && right != 3)
			|| (left == 4 && right != 4)
			|| (left == 5 && (right != 5 && right != 4)))
		{
			cout << "ERROR: Incompatible types: got " << types[right] << " expected " << types[left] <<" in line: "<< n->line << endl;
			error = 1;

		}
	}
	fErr = 0;

}
void
TypeVisitor::Visit(StmtProcedure*n)
{
	n->procedure_statement->accept(this);
}
void
TypeVisitor::Visit(StmtCompound*n)
{
	n->compound_statement->accept(this);
}
void
TypeVisitor::Visit(Compound_statement*n)
{

	n->statement_list->accept(this);
}
void
TypeVisitor::Visit(StmtIf*n)
{
	n->expression->accept(this);
	if (n->expression->type != 3)
	{
		cout << "ERROR: Incompatible types: got " << types[n->expression->type] << " expected boolean in if conndition in line: " << n->line << endl;
		error = 1;

	}
	n->statement_list->accept(this);

}
void
TypeVisitor::Visit(StmtIfElse*n)
{

	n->expression->accept(this);
	if (n->expression->type != 3)
	{
		cout << "ERROR: Incompatible types: got " << types[n->expression->type] << " expected boolean in if condition in line:"<<n->line << endl;
		error = 1;

	}
	n->statement_list1->accept(this);
	n->statement_list2->accept(this);
}
void
TypeVisitor::Visit(StmtWhile*n)
{
	n->expression->accept(this);
	if (n->expression->type != 3)
	{
		cout << "ERROR: Incompatible types: got " << types[n->expression->type] << " expected boolean in while condition" << endl;
		error = 1;

	}
	n->statement_list->accept(this);
}
void
TypeVisitor::Visit(StmtFor*n)
{
	n->ident->accept(this);
	if (n->int1 != NULL)
	{
		if (n->ident->symbol->type != 1)
		{
			cout << "ERROR: Incompatible types: got " << types[n->ident->symbol->type] << " expected integer in for statement in line: "<<n->line << endl;
			error = 1;

		}
	
	}
	else
	{
		if (n->ident->symbol->type != 4)
		{
			cout << "ERROR: Incompatible types: got " << types[n->ident->symbol->type] << " expected char in for statement in line: " << n->line << endl;
			error = 1;

		}
	}

	n->statement_list->accept(this);
}
void
TypeVisitor::Visit(StmtWriteStr*n)
{

}
void
TypeVisitor::Visit(StmtWriteId*n)
{

}
void
TypeVisitor::Visit(StmtWriteExp*n)
{
	n->left->accept(this);
	n->right->accept(this);
}



/////////////////////////////// symbol table /////////////////////////////////////////

Symbol::Symbol(string name, int kind, int type, int begin, int end) {
	this->name = name;
	this->type = type;
	this->kind = kind;
	this->begin = begin;
	this->end = end;
}

Symbol::Symbol(string name, int kind, int type, Subprogram_head * f) {
	this->name = name;
	this->kind = kind;
	this->type = type;
	this->function = f;
}

Scope::Scope()
{
	this->hashTab = new HashTab();
}


SymbolTable::SymbolTable() {

	this->scopes = new vector < Scope* >;
	this->scopes->push_back(new Scope());
	//this->errors = new Errors();
	this->current = this->scopes->at(0);
	kindes[1] = "l";
	kindes[2] = "p";
	kindes[3] = "g";
	kindes[4] = "C";

	types[0] = "null";
	types[1] = "int";
	types[2] = "real";
	types[3] = "boolean";
	types[4] = "char";
	types[5] = "string";
	types[6] = "null";
}

bool SymbolTable::AddSymbol(Ident * ident, int kind, int type, int begin, int end) {
	Symbol * sym = new Symbol(ident->name, kind, type, begin, end);
	string key = kindes[kind] + ident->name;
	//string key = "l" + ident->name;
	Symbol * temp = this->current->hashTab->GetMember(key);
	if (temp == NULL) {
		this->current->hashTab->AddKey(key, sym);
		ident->symbol = sym;
		return true;
	}
	else {
		cout << " redifined variable : " << ident->name << " in line: " << ident->line << endl;
		symErr = 1;
		//symbolTable->errors->AddError("redifined variable : " + id->name, id->line, 0);
		//symanticerror = true;
		return false;
	}
}

Symbol * SymbolTable::LookUpSymbol(Ident * ident)
{
	string key;
	//key = kindes[3] + id->name;
	Symbol *sym;
	//cout << this->scopes-> <<endl;
	key = "l" + ident->name;
	sym = this->current->hashTab->GetMember(key);
	if (sym != NULL) {
		ident->symbol = sym;
		return sym;
	}
	else {

		key = "g" + ident->name;
		if (this->scopes->size() > 1)
		{
			sym = this->scopes->at(this->scopes->size() - 2)->hashTab->GetMember(key);
			if (sym != NULL) {
				ident->symbol = sym;
				return sym;
			}
			else {
				cout << " undefined variable: " << ident->name << " in line: " << ident->line << endl;
				symErr = 1;

				//symbolTable->errors->AddError("undifined variable : " + id->name, id->line, 0);
				//symanticerror = true;
				return NULL;
			}
		}
		else
		{
			sym = this->scopes->at(this->scopes->size() - 1)->hashTab->GetMember(key);
			if (sym != NULL) {
				ident->symbol = sym;
				return sym;
			}
			else {
				cout << " undefined variable: " << ident->name << " in line: " << ident->line << endl;
				symErr = 1;

				//symbolTable->errors->AddError("undifined variable : " + id->name, id->line, 0);
				//symanticerror = true;
				return NULL;
			}
		}

	}


}

void SymbolTable::NewScope() {
	this->scopes->push_back(new Scope());
	this->current = this->scopes->at(this->scopes->size() - 1);

}

void SymbolTable::CloseScope() {
	this->scopes->pop_back();
	this->current = this->scopes->at(this->scopes->size() - 1);
}

bool SymbolTable::AddFunc(Ident * ident, int kind, Arguments * a, int type, Subprogram_head * f) {
	Symbol * sym = new Symbol(ident->name, kind, type, f);
	string key = kindes[kind] + ident->name;
	if (a) {
		for (int i = 0; i < (int)(a->parameter_list->type->size()); i++)
		{
			for (int j = 0; j < (int)(a->parameter_list->identifier_list->at(i)->idents->size()); j++)
			{
				int e = a->parameter_list->type->at(i)->type;
				key += "@" + types[e];
			}
		}
	}

	//cout << id->name << " in line: " << id->line<< "Key: " << key << endl;
	//Symbol * temp = this->current->hashTab->GetMember(key);
	Symbol * temp = this->scopes->at(0)->hashTab->GetMember(key);
	if (temp == NULL) {
		this->scopes->at(0)->hashTab->AddKey(key, sym);
		ident->symbol = sym;
		return true;
	}
	else {
		if (type == 0)
		{
			symErr = 1;
			cout << " redifined procedure : " << ident->name << " in line: " << ident->line << endl;

		}
		else
		{
			cout << " redifined function : " << ident->name << " in line: " << ident->line << endl;
			symErr = 1;

		}

		return false;
	}
}


Symbol * SymbolTable::LookUpFunc(Ident * ident, Expression_list * exp)
{
	string key;
	//key = kindes[3] + id->name;
	Symbol *sym;
	key = "g" + ident->name;
	for (int i = 0; i < (int)(exp->expressions->size()); i++)
	{
		int e = exp->expressions->at(i)->type;
		key += "@" + types[e];
		cout << key << endl;
	}
	sym = this->current->hashTab->GetMember(key);
	if (sym != NULL)
	{
		ident->symbol = sym;
		return sym;
	}
	else
	{
		cout << "no such function " << ident->name << " in line: " << ident->line << endl;
		symErr = 1;
	}


}


////////////////////////////code visitor/////////////////////////////////


void
CodeVisitor::Visit(Node*n)
{
}
void
CodeVisitor::Visit(Ident*n)
{

}
void
CodeVisitor::Visit(Program*n)
{
	vout << "start " << endl;
	n->declarations->accept(this);
	n->compound_statement->accept(this);
	vout << "stop " << endl;
	n->subprogram_declarations->accept(this);

}

void
CodeVisitor::Visit(Declarations*n)
{
	for (int i = 0; i < n->identifier_list->size(); i++)
	{
		n->identifier_list->at(i)->accept(this);
	}
}
void
CodeVisitor::Visit(Function*n)
{
	
	if (n->visited == 0)
	{
		n->visited == 1;
		string label_func = "";
		label_func += n->name->name;
		if (n->arg)
		{
			for (int i = 0; i < (int)(n->arg->parameter_list->type->size()); i++)
			{
				for (int j = 0; j < (int)(n->arg->parameter_list->identifier_list->at(i)->idents->size()); j++)
				{
					label_func += "_" + std::to_string(n->arg->parameter_list->type->at(i)->type);
				}
			}
		}
		vout << label_func << ":" << endl;		
		n->arg->accept(this);
		
		if (n->declarations != NULL)
		{
			n->declarations->accept(this);
		}

	}
}
void
CodeVisitor::Visit(Procedure*n)
{

}


void
CodeVisitor::Visit(Identifier_list*n)
{
	for (int i = 0; i < n->idents->size(); i++)
	{
		if (n->idents->at(i)->symbol->kind == 1)//local
		{
			if (n->idents->at(i)->symbol->type == 1)
			{
				fp++;
				n->idents->at(i)->symbol->location = fp;
				vout << "pushi 0" << endl;
				vout << "storel " << fp << endl;
				vout << "pushl " << fp << endl;
			}
			else if (n->idents->at(i)->symbol->type == 2)
			{
				fp++;
				n->idents->at(i)->symbol->location = fp;
				vout << "pushf 0.0" << endl;
				vout << "storel " << fp << endl;
				vout << "pushl " << fp << endl;
			}
		}
		else if (n->idents->at(i)->symbol->kind == 3)//global
		{
			if (n->idents->at(i)->symbol->type == 1)
			{
				
				n->idents->at(i)->symbol->location = gp;
				vout << "pushi 0" << endl;
				vout << "storeg " << gp << endl;
				vout << "pushg " << gp << endl;
				gp--;
			}
			else if (n->idents->at(i)->symbol->type == 2)
			{
				n->idents->at(i)->symbol->location = gp;
				vout << "pushf 0.0" << endl;
				vout << "storeg " << gp << endl;
				vout << "pushg " << gp << endl;
				gp--;
			}
		}
	}
}
void
CodeVisitor::Visit(Type*n)
{

}
void
CodeVisitor::Visit(Arguments*n)
{
	if (n->parameter_list!=NULL)
	{
		n->parameter_list->accept(this);

	}
}
void
CodeVisitor::Visit(Parameter_list*n)
{
	
	int size = 0;

	for (int i = 0; i < int(n->identifier_list->size()); i++)
	{
		for (int j = 0; j < n->identifier_list->at(i)->idents->size(); j++)
		{
			size++;
		}
	}

	for (int i = 0; i < int(n->identifier_list->size()); i++)
	{
		for (int j = 0; j < n->identifier_list->at(i)->idents->size(); j++)
		{
			n->identifier_list->at(i)->idents->at(j)->symbol->location = i + j - size;
		}
		//n->identifier_list->at(i)->accept(this);
		//n->type->at(i)->accept(this);
	}

	//n->accept(this);
}
void
CodeVisitor::Visit(Statement*n)
{

}
void
CodeVisitor::Visit(Statement_list*n)
{
	if (n->optional_statements->size() != 0)
	{
		for (int i = 0; i < n->optional_statements->size(); i++)
		{
			n->optional_statements->at(i)->accept(this);
		}
	}

}
void
CodeVisitor::Visit(Variable*n)
{
	///////////////////////////////////
}
void
CodeVisitor::Visit(Expression*n)
{

}
void
CodeVisitor::Visit(ExpIdent*n)
{
	int location=n->name->symbol->location;
	if (n->name->symbol->kind == 1)
	{
		vout << "pushl " << location << endl;

	}
	else
	{
		vout << "pushg " << location << endl;

	}
}
void
CodeVisitor::Visit(ExpInt*n)
{
	vout << "pushi " << n->num << endl;
}
void
CodeVisitor::Visit(ExpReal*n)
{
	vout << "pushf " << n->num << endl;
}
void
CodeVisitor::Visit(ExpChar*n)
{ 
	string c = "";
	c = n->value;
	vout<<"pushs \"" + c + "\"";
}
void
CodeVisitor::Visit(ExpStr*n)
{
	string s = "";
	s = n->value;
	vout << "pushs \"" + s + "\"";
}
void
CodeVisitor::Visit(ExpTrue*n)
{
	vout << "pushi 1" << endl;
}
void
CodeVisitor::Visit(ExpFalse*n)
{
	vout << "pushi 0" << endl;
}
void
CodeVisitor::Visit(ExpInner*n)
{ 
	int i, j;
	if (n->expression_list) {
		for ( i = 0; i < (int)(n->func->arg->parameter_list->type->size()); i++)
		{
			for ( j = 0; j < n->func->arg->parameter_list->identifier_list->at(i)->idents->size(); j++)
			{
				n->expression_list->expressions->at(i+j)->accept(this);
				if (n->expression_list->expressions->at(i+j)->type == 1 && n->func->arg->parameter_list->type->at(i)->type == 2)
					vout << "itof" << endl;
			}
		}

	}
	string label_func= "";
	label_func += n->name->name;
	for (i = 0; i < (int)(n->func->arg->parameter_list->type->size()); i++)
	{
		for (j = 0; j < (int)(n->func->arg->parameter_list->identifier_list->at(i)->idents->size()); j++)
		{
				label_func += "_" +std::to_string( n->func->arg->parameter_list->type->at(i)->type);
		}
	}

	vout << "pusha " << label_func << endl;
	vout << "call" << endl;

	Symbol* sym = n->func->name->symbol;
	if (sym)
	{
		//funcs->push_back(functionSymbol);
		if (n->expression_list != NULL  && n->expression_list->expressions->size() > 0)
		    vout << "pop " << n->expression_list->expressions->size() << endl;
			vout << "pushg " << gp << endl;
	}
	else
	{
		// Add errors
	}
}
void
CodeVisitor::Visit(Expr*n)
{

}
void
CodeVisitor::Visit(ExpOpt*n)
{
	
	if (n->op == 1)  // add
	{
		if ((n->left->type == 1 && n->right->type==1)||(n->left->type == 2 && n->right->type == 2))
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			if (n->left->type == 1)
			{
				vout << "add" << endl;
			}
			else
			{
				vout << "fadd" << endl;
			}
		}
		else if (n->left->type==1 && n->right->type==2)
		{
			//vout << "storel " << n->left << endl;
			//vout << "itof" << endl;
			//vout << "pushl" << n->left << endl; //location
			if (n->right != NULL) n->right->accept(this);
			if (n->left != NULL) n->left->accept(this);
			vout << "itof" << endl;
			vout << "fadd" << endl;
		}
		else if (n->left->type == 2 && n->right->type == 1)
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			vout << "itof" << endl;
			vout << "fadd" << endl;
		}
	}
	else if (n->op == 2) //subtract
	{
		if ((n->left->type == 1 && n->right->type == 1)||(n->left->type == 2 && n->right->type == 2))
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			if (n->left->type == 1)
			{
				vout << "sub" << endl;
			}
			else
			{
				vout << "fsub" << endl;
			}
		}
		else if (n->left->type == 1 && n->right->type == 2)
		{
			//vout << "storel " << n->left << endl;
			//vout << "itof" << endl;
			//vout << "pushl" << n->left << endl; //location
			if (n->right != NULL) n->right->accept(this);
			if (n->left != NULL) n->left->accept(this);
			vout << "itof" << endl;
			vout << "fsub" << endl;
		}
		else if (n->left->type == 2 && n->right->type == 1)
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			vout << "itof" << endl;
			vout << "fsub" << endl;
		}
	}
	else if (n->op == 3) //multiply
	{
		if ((n->left->type == 1 && n->right->type == 1)||(n->left->type == 2 && n->right->type == 2))
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			if (n->left->type == 1)
			{
				vout << "mul" << endl;
			}
			else
			{
				vout << "fmul" << endl;
			}
		}
		else if (n->left->type == 1 && n->right->type == 2)
		{
			//vout << "storel " << n->left << endl;
			//vout << "itof" << endl;
			//vout << "pushl" << n->left << endl; //location
			if (n->right != NULL) n->right->accept(this);
			if (n->left != NULL) n->left->accept(this);
			vout << "itof" << endl;
			vout << "fmul" << endl;
		}
		else if (n->left->type == 2 && n->right->type == 1)
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			vout << "itof" << endl;
			vout << "fmul" << endl;
		}

	}
	else if (n->op == 4||n->op==5) //division
	{
		if ((n->left->type == 1 && n->right->type == 1)||(n->left->type == 2 && n->right->type == 2))
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			if (n->left->type == 1)
			{
				vout << "div" << endl;
			}
			else
			{
				vout << "fdiv" << endl;
			}
		}
		else if (n->left->type == 1 && n->right->type == 2)
		{
			//vout << "storel " << n->left << endl;
			//vout << "itof" << endl;
			//vout << "pushl" << n->left << endl; //location
			if (n->right != NULL) n->right->accept(this);
			if (n->left != NULL) n->left->accept(this);
			vout << "itof" << endl;
			vout << "fdiv" << endl;
		}
		else if (n->left->type == 2 && n->right->type == 1)
		{
			if (n->left != NULL) n->left->accept(this);
			if (n->right != NULL) n->right->accept(this);
			vout << "itof" << endl;
			vout << "fdiv" << endl;
		}
	}
	else if (n->op == 12) //and
	{
		if (n->left != NULL) n->left->accept(this);
		if (n->right != NULL) n->right->accept(this);
		vout << "add" << endl;
		vout << "pushi 2" << endl;
		vout << "equal" << endl;
	}
	else if (n->op == 13) //or
	{
		if (n->left != NULL) n->left->accept(this);
		if (n->right != NULL) n->right->accept(this);
		vout << "add" << endl;
		vout << "pushi 0" << endl;
		vout << "equal" << endl;
		vout << "not" << endl;
	}
	else if (n->op == 6) //<
	{
		if (n->left != NULL) n->left->accept(this);
		if (n->right != NULL) n->right->accept(this);
		if ((n->left->type == 1 && n->right->type == 1) || (n->left->type == 2 && n->right->type == 2))
		{
			vout << "inf" << endl;
		}
		else if (n->left->type == 1)
		{
			vout << "storel " << n->left << endl;
			vout << "itof" << endl;
			vout << "pushl " << n->left << endl;
			vout << "inf" << endl;
		}
		else if (n->right->type == 1)
		{
			vout << "itof" << endl;
			vout << "inf" << endl;
		}
	}
	else if (n->op == 7) //>
	{
		if (n->left != NULL) n->left->accept(this);
		if (n->right != NULL) n->right->accept(this);
		if ((n->left->type == 1 && n->right->type == 1) || (n->left->type == 2 && n->right->type == 2))
		{
			vout << "sup" << endl;
		}
		else if (n->left->type == 1)
		{
			vout << "storel " << n->left << endl;
			vout << "itof" << endl;
			vout << "pushl " << n->left << endl;
			vout << "sup" << endl;
		}
		else if (n->right->type == 1)
		{
			vout << "itof" << endl;
			vout << "sup" << endl;
		}
	}
}
void
CodeVisitor::Visit(ExpNot*n)
{
	n->expression->accept(this);
	vout << "not" << endl;

}
void
CodeVisitor::Visit(Expression_list*n)
{
	for (int i = 0; i < n->expressions->size(); i++)
	{
		n->expressions->at(i)->accept(this);
	}
}
void
CodeVisitor::Visit(Subprogram_declarations*n)
{
	for (int i = 0; i < n->subprogram_declarations->size(); i++)
	{
		n->subprogram_declarations->at(i)->accept(this);
	}
}
void
CodeVisitor::Visit(Subprogram_declaration*n)
{
	n->subprogram_head->accept(this);
	if (n->compound_statement!=NULL)
	{
		n->compound_statement->accept(this);

	}
	if (n->subprogram_head->name->symbol->type != 0)
	{
		n->return_stmt->accept(this);
	}
}

void
CodeVisitor::Visit(Return_stmt*n)
{
	vout << "storeg " << gp << endl;
	vout << "pushg " << gp << endl;
	vout << "return " << endl;

}

void
CodeVisitor::Visit(Subprogram_head*n)
{

}
void
CodeVisitor::Visit(Array*n)
{

}
void
CodeVisitor::Visit(Procedure_statement*n)
{

}
void
CodeVisitor::Visit(StmtAssign*n)
{
	n->expression->accept(this);
	n->variable->accept(this);
	int location = n->variable->name->symbol->location;
	if (n->variable->name->symbol->kind == 1)
	{
		vout << "storel " << location << endl;
		vout << "pushl " << location << endl;
	}
	else if (n->variable->name->symbol->kind == 3)
	{
		vout << "storeg " << location << endl;
		vout << "pushg " << location << endl;
	}
}
void
CodeVisitor::Visit(StmtProcedure*n)
{

}
void
CodeVisitor::Visit(StmtCompound*n)
{

}
void
CodeVisitor::Visit(Compound_statement*n)
{
	if (n->statement_list!=NULL )
	{
		n->statement_list->accept(this);

	}
}
void
CodeVisitor::Visit(StmtIf*n)
{
	if (n->expression != NULL)
	{
		n->expression->accept(this);
	}
	label_if++;
	vout << "jz END_IF" << label_if << endl;
	n->statement_list->accept(this);
	vout << "END_IF" << label_if <<":"<< endl;
}
void
CodeVisitor::Visit(StmtIfElse*n)
{
	label_else++;
	if (n->expression != NULL)
	{
		n->expression->accept(this);
	}
	vout << "jz ELSE_BEGIN" << label_else << endl;
	if (n->statement_list1 != NULL)
	{
		n->statement_list1->accept(this);
	}
	vout << "jump ELSE_END" << label_else << endl;
	vout << "ELSE_BEGIN" << label_else <<":" <<endl;
	if (n->statement_list2 != NULL)
	{
		n->statement_list2->accept(this);
	}
	vout << "ELSE_END" << label_else << ":" << endl;
}
void
CodeVisitor::Visit(StmtWhile*n)
{
	label_while++;
	vout << "WHILE_BEGIN_" << label_while << ":" << endl;
	if (n->expression != NULL)
	{
		n->expression->accept(this);
	}
	vout << "jz WHILE_END_" << label_while << endl;
	if (n->statement_list != NULL)
	{
		n->statement_list->accept(this);
	}
	vout << "jump WHILE_BEGIN_" << label_while << endl;
	vout << "WHILE_END_" << label_while << ":" << endl;
}
void
CodeVisitor::Visit(StmtFor*n)
{
	label_for++;
	if (n->ident->symbol->kind == 3)
	{
		vout << "pushi " << n->int1->num << endl;
		vout << "storeg " << n->ident->symbol->location << endl;
		vout << "pushg " << n->ident->symbol->location << endl;
	}
	else
	{
		vout << "pushi " << n->int1->num << endl;
		vout << "storel " << n->ident->symbol->location << endl;
		vout << "pushl " << n->ident->symbol->location << endl;

	}
	vout << "FOR_BEGIN_" << label_for << ":" << endl;
	if (n->ident->symbol->kind == 3)
	{
		vout << "pushg " << n->ident->symbol->location << endl;

	}
	else
	{
		vout << "pushl " << n->ident->symbol->location << endl;

	}
	vout << "pushi " << n->int2->num << endl;
	vout << "inf" << endl;
	vout << "jz FOR_END_" << label_for << endl;
	if (n->statement_list != NULL)
	{
		n->statement_list->accept(this);
	}
	vout << "pushi 1"  << endl;
	vout << "pushg " << n->ident->symbol->location << endl;
	vout << "add " << endl;
	if (n->ident->symbol->kind == 3)
	{
		vout << "storeg " << n->ident->symbol->location << endl;
		vout << "pushg " << n->ident->symbol->location << endl;
	}
	else
	{
		vout << "storel " << n->ident->symbol->location << endl;
		vout << "pushl " << n->ident->symbol->location << endl;
	}
	vout << "jump FOR_BEGIN_" << label_for << endl;
	vout << "FOR_END_" << label_for << ":" << endl;
}
void
CodeVisitor::Visit(StmtWriteStr*n)
{

}
void
CodeVisitor::Visit(StmtWriteId*n)
{

}
void
CodeVisitor::Visit(StmtWriteExp*n)
{

}