%{
	#include "ast.h"
	#include <iostream>
	using std::cout;
	using std::endl;
	extern int yylex();
	extern int yyerror(const char *);
	Program *root;
	SymbolTable *symbolTable=new SymbolTable();
	int lin = 1, col =1;
	int i=0;
	int ifScope=0;
	int current_type;
	int current_kind=3;
	int error=0;
	int symErr=0;
    int fErr=0;



%}

%union
{
		Program *tProgram;
		Identifier_list *tIdentifier_list;
		Declarations *tDeclarations;
		Type *tType;
		int tStandard_type;
		Subprogram_declarations *tSubprogram_declarations;
		Subprogram_declaration *tSubprogram_declaration;
		Subprogram_head *tSubprogram_head;
		Arguments *tArguments;
		Parameter_list *tParameter_list;
		Compound_statement *tCompound_statement;
		Statement_list *tStatement_list;
		Statement *tStatement;
		Variable *tVariable;
		Procedure_statement *tProcedure_statement;
		Expression_list *tExpression_list;
		Expression *tExpression;
		int tUnary_operator ;
		Ident *tIdent ;
		ExpInt *tExpInt;
		ExpReal *tExpReal;
		ExpStr *tExpStr;
		ExpChar *tExpChar;
		Return_stmt *tReturn_stmt;
}

%type <tProgram> program
%type <tIdentifier_list> identifier_list
%type <tDeclarations> declarations
%type <tDeclarations> declarations_e
%type <tType> type
%type <tStandard_type> standard_type
%type <tSubprogram_declarations> subprogram_declarations 
%type <tSubprogram_declarations> subprogram_declarations_e
%type <tSubprogram_declaration> subprogram_declaration
%type <tSubprogram_head> subprogram_head
%type <tArguments> arguments
%type <tParameter_list> parameter_list
%type <tCompound_statement> compound_statement
%type <tStatement_list> statement_list statement_list_e
%type <tStatement> statement
%type <tVariable> variable
%type <tProcedure_statement> procedure_statement
%type <tExpression_list> expression_list
%type <tExpression> expression
%type <tUnary_operator> unary_operator
%type <tReturn_stmt> return_stmt

%token PROGRAM
%token <tIdent> IDENT
%token <tExpInt> INTEGER
%token <tExpReal> REAL
%token <tStandard_type> BOOLEAN
%token <tExpStr> STRING
%token <tExpChar> CHAR
%token KW_INTEGER
%token KW_REAL
%token KW_BOOLEAN
%token KW_CHAR
%token KW_STRING
%token WRITE
%token KW_IF KW_ELSE KW_THEN KW_WHILE KW_DO KW_END KW_BEGIN KW_TRUE KW_FALSE KW_TO KW_FOR
%token FUNCTION 
%token KW_RETURN
%token PROCEDURE 
%token VAR ARRAY NOT OF AND OR DIV
%token EQ NEQ LE SE ASSIGN
%token KW_DOTS

%nonassoc dec_e
%left KW_BEGIN
%left KW_END
%left OPP1
%left ASSIGN
%left OP
%left '>' '<' EQ LE SE NEQ
%left '(' '[' ']' ')'
%left '-' '+'
%left '*' DIV '/' 
%nonassoc AND OR NOT ','
%nonassoc KW_ELSE
%nonassoc IFPREC
%nonassoc prog

%start program

%%
program:                 PROGRAM IDENT                  
		             	';' declarations_e
                         subprogram_declarations_e
                         compound_statement '.' %prec prog
						 {
						  root=new Program($2,$4,$5,$6,lin,col);
						 }
;
identifier_list:         IDENT
							{
								$$= new Identifier_list($1,lin,col);
											  
							}
                       | identifier_list ',' IDENT
							{
								$$ = $1;
								$$->AddIdent($3);
							}
;
declarations_e:        declarations
					   {
					   $$=$1;
					   }
					   |   /* empty */ %prec dec_e
					   {
					   $$=new Declarations(lin,col);
					   }
;
declarations:            declarations VAR identifier_list ':' type ';'
                           {
						    $$=$1;
						    $$->AddDeclarations($3,$5);
							for(int k=0;k<$3->idents->size();k++)
						       {
							     if($5->isArray==0)
							       symbolTable->AddSymbol($3->idents->at(k), current_kind  ,  $5->type,0,0 );
								 else
				                   symbolTable->AddSymbol($3->idents->at(k), current_kind  ,  $5->type,$5->beginning->num,$5->end->num );
								   

							   }
						    }  
						| VAR identifier_list ':' type ';'  
						   {
						     $$=new Declarations($2,$4,lin,col);
							 for(int k=0;k<$2->idents->size();k++)
							   {
							     if($4->isArray==0)
							        symbolTable->AddSymbol($2->idents->at(k), current_kind  ,  $4->type,0,0 );
								 else
								    symbolTable->AddSymbol($2->idents->at(k), current_kind  ,  $4->type,$4->beginning->num,$4->end->num );
									
							   }
						   }               
;
type:                    standard_type
							{
								$$=new Type($1,lin,col);
							}
                       |  ARRAY '[' INTEGER ';' INTEGER ']' OF standard_type
							{
								$$=new Array($3,$5,$8,lin,col);
							}
;
standard_type:           KW_INTEGER
							{
								$$=1;
							}
                       | KW_REAL
							{
								$$=2;
							}
                       | KW_BOOLEAN
							{
								$$=3;
							}
					   | KW_CHAR
							{
								$$=4;
							}
					   | KW_STRING
							{
								$$=5;
							}
;
subprogram_declarations_e:    subprogram_declarations
								{
									$$=$1;
								}
							 | /* empty */ 
								{
									$$=new Subprogram_declarations(lin,col);
								}
;							
subprogram_declarations:      subprogram_declarations
                              subprogram_declaration 
							    {
								  $$=$1;
								  $$->AddSubprogram_declaration($2);
							    }
					       | subprogram_declaration 
					         {
								$$=new Subprogram_declarations($1,lin,col);
					          }
;
subprogram_declaration:  subprogram_head compound_statement return_stmt ';'
                         {
						  $$=new Subprogram_declaration($1,$2,$3,lin,col);
						 }
;
return_stmt: KW_RETURN variable 
             {
			   $$=new Return_stmt($2,lin,col);
			    if (ifScope==1)
						     {
						     symbolTable->CloseScope(); 
							  current_kind=3;
						      ifScope=0;
						     }
			 }
			 |/*empty*/
			 {
			   $$=new Return_stmt(lin,col);
			    if (ifScope==1)
						     {
						     symbolTable->CloseScope(); 
							  current_kind=3;
						      ifScope=0;
						     }
			 }
;
subprogram_head:         FUNCTION IDENT{	
                                        symbolTable->NewScope(); 
										 ifScope=1;
								        current_kind=1;
										} arguments ':' standard_type ';' declarations_e
                                                                                    {
						                                                           $$=new Function($6,$2,$4,$8,lin,col);
																				   symbolTable->AddFunc($2,3,$4,$6,$$);

							                                                      // symbolTable->CloseScope(); 
																				  //   current_kind=3;
				
                                                                                    }
                       | PROCEDURE IDENT{
					                     symbolTable->NewScope(); 
										 ifScope=0; 
										 current_kind=1;
										 } arguments ';' declarations_e
					                                                  {
						                                              $$=new Procedure($2,$4,$6,lin,col);
																	  symbolTable->AddFunc($2,3,$4,0,$$);
						                                             // symbolTable->CloseScope(); 
																	  // current_kind=3;
					                                                  }
;
arguments:               '(' parameter_list ')'
                            {
							$$=new Arguments($2,lin,col);
							}
                       | /* empty */
					        {
						   $$=new Arguments(lin,col);
						    }
;
parameter_list:          identifier_list ':' type
                           {
						   $$=new Parameter_list($1,$3,lin,col);
						   for(int l=0;l<$1->idents->size();l++)
						    {
							   if($3->isArray==0)
							     symbolTable->AddSymbol($1->idents->at(l), 1  ,  $3->type,0,0 );
							   else
							     symbolTable->AddSymbol($1->idents->at(l), 1  ,  $3->type,$3->beginning->num,$3->end->num );
							}

						   }
                       | parameter_list ';' identifier_list ':' type
					       {
						   $$=$1;
						   $$->AddParameter_list($3,$5);
						   for(int l=0;l<$3->idents->size();l++)
						   {
						    if($5->isArray==0)
						       symbolTable->AddSymbol($3->idents->at(l), 1  ,  $5->type,0,0 );
							else
			                   symbolTable->AddSymbol($3->idents->at(l), 1  ,  $5->type,$5->beginning->num,$5->end->num );

						   }

						   }
;
compound_statement:      KW_BEGIN statement_list_e KW_END 
                           {
						   $$=new Compound_statement ($2,lin,col);
						//   if (ifScope==1)
						  //   {
						//     symbolTable->CloseScope(); 
							//  current_kind=3;
						   //   ifScope=0;
						    // }
						   }
;
statement_list_e:       statement_list %prec OPP1
                          {
						  $$=$1;
						  }
					   | /* empty */ %prec OPP1
						   {
						   $$=new Statement_list(lin,col);
						   }
;
statement_list:			statement_list statement 
                         {
						 $$=$1;
						 $$->AddStatement_list($2);
						 }
					   | statement 
						 {
						 $$=new Statement_list($1,lin,col);
						 }
;
statement:               variable ASSIGN expression ';' %prec OPP1
						 {
						  $$=new StmtAssign($1, $3,lin,col);
						 }
                       | procedure_statement ';' %prec OPP1
					     {
						  $$=new StmtProcedure($1,lin,col);
					     }
                       | compound_statement ';'
					     {
						  $$=new StmtCompound($1,lin,col);
					     }
                       | KW_IF expression KW_THEN compound_statement ';' %prec IFPREC
					     {
						  $$=new StmtIf($2,$4,lin,col);
					     }
					   | KW_IF expression KW_THEN compound_statement ';' KW_ELSE compound_statement ';'
					     {
						  $$=new StmtIfElse($2,$4,$7,lin,col);
					     }
                       | KW_WHILE expression KW_DO compound_statement ';' %prec OPP1
					     {
						  $$=new StmtWhile($2,$4,lin,col);
					     }
					   | KW_FOR IDENT ASSIGN CHAR KW_TO CHAR KW_DO compound_statement ';'
					     {
						  $$=new StmtFor($2,$4,$6,$8,lin,col);
						   symbolTable->LookUpSymbol($2);
					     }
					   | KW_FOR IDENT ASSIGN INTEGER KW_TO INTEGER KW_DO compound_statement ';'
					      {
						  $$=new StmtFor($2,$4,$6,$8,lin,col);
						  symbolTable->LookUpSymbol($2);
					      }
					   | WRITE '(' STRING ')' ';' %prec OPP1
					      {
						   $$=new StmtWriteStr($3,lin,col);
						  }
					   | WRITE '(' IDENT ')' ';' %prec OPP1
					     {
						  $$=new StmtWriteId($3,lin,col);
						  symbolTable->LookUpSymbol($3);
						 }
					   | WRITE '(' expression unary_operator expression ')' ';' %prec OPP1
					     {
						  $$=new StmtWriteExp($3,$4,$5,lin,col);
					     }
;
variable:                IDENT 
                         {
						 $$=new Variable($1,lin,col);
						 symbolTable->LookUpSymbol($1);
						 }
                       | IDENT '[' expression ']' 
					     {
						 $$=new Variable($1,$3,lin,col); 
						 symbolTable->LookUpSymbol($1);
						 }
;
procedure_statement:     IDENT 
							{
								$$=new Procedure_statement($1,lin,col);
								symbolTable->LookUpSymbol($1);
							}
                       | IDENT '(' expression_list ')'
					   {
								$$=new Procedure_statement($1,$3,lin,col);
								//symbolTable->LookUpFunc($1,$3);
					   }
;
expression_list:         expression
						{
							$$=new Expression_list($1,lin,col);
						}
                       | expression_list ',' expression
					   {
							$$=$1;
							$$->AddExpression($3);
					   }
;
expression:              IDENT   
                         {
						 $$=new ExpIdent($1,lin,col);
						 symbolTable->LookUpSymbol($1);
						 }                     
                       | INTEGER
					     {
						 $$=$1;
						 }
                       | REAL
					     {
						 $$=$1;
						 }
					   | CHAR
					     {
						  $$=$1;
						 }
					   | STRING
					     {
						 $$=$1;
					     }
                       | KW_TRUE
					     {
						 $$=new ExpTrue(lin,col);
						 }
                       | KW_FALSE
					     {
						 $$=new ExpFalse(lin,col);
						 }
                       | IDENT '(' expression_list ')'
					     {
						 $$=new ExpInner ($1,$3,lin,col);
						 //symbolTable->LookUpSymbol($1);
						 }
                       | '(' expression ')'
					     {
						 $$=new Expr($2,lin,col);
						 }
                       | expression unary_operator expression %prec OP
					     {
						 $$=new ExpOpt($1,$2,$3,lin,col);
						 }
                       | NOT expression
					     {
						 $$=new ExpNot($2,lin,col);
						 }
;
unary_operator:          '+'
						{
							$$=1;
						}
                       | '-'
					    {
							$$=2;
						}
                       | '*'
					    {
							$$=3;
						}
                       | '/'
					    {
							$$=4;
						}
                       | DIV
					    {
							$$=5;
						}
                       | '<'
					    {
							$$=6;
						}
                       | '>'
					    {
							$$=7;
						}
                       | SE
					    {
							$$=8;
						}
                       | LE
					    {
							$$=9;
						}
                       | EQ
					    {
							$$=10;
						}
                       | NEQ
					    {
							$$=11;
						}
                       | AND
					    {
							$$=12;
						}
                       | OR
					    {
							$$=13;
						}
;
%%
int yyerror(const char* s){
cout<<"something went wrong"<<endl;
return 1;
}