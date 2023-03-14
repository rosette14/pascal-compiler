#include "ast.h"
#include <iostream>
using std::cout;
using std::int16_t;
using std::endl;
extern int yyparse();
extern int yydebug;
extern Program *root;
extern int error;
extern int symErr;

extern SymbolTable *symbolTable;
int main() {
	yydebug = 0;
	yyparse();
	cout << "parsing is done" << endl;
	root;
	symbolTable;
	/*Visitor *printVisitor = new PrintVisitor();
	root->accept(printVisitor);*/
	
	if (symErr == 0)
	{
		TypeVisitor * type = new TypeVisitor();
		root->accept(type);


		if (error == 0)
		{
			Visitor *codeViisitor = new CodeVisitor;
			root->accept(codeViisitor);
		}
		else
		{
			cout <<endl<< "please fix errors for generating code" << endl;
		}
	}
	else
	{
		cout <<endl<< "please fix errors for type checking" << endl;
	}



	return 0;
}