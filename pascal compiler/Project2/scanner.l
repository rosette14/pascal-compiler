%{
	#include "ast.h"
	#include "parser.h"	
	extern int lin, col ;
%}

%x comment
%x string
%option noyywrap
%%
"/*"					BEGIN(comment); col += yyleng;
<comment>[^*\n]*		col += yyleng;
<comment>"*"+[^*/\n]*	col += yyleng;
<comment>\n				lin++; col = 1;
<comment>"*"+"/"		BEGIN(0); col += yyleng;

"//".*\n				lin++; col = 1;

"\'"                    BEGIN(string);
<string>[A-Za-z]	{
                       col+= yyleng;
					   yylval.tExpChar =new ExpChar(yytext[0],lin,col);
					   return CHAR;
					}
<string>([a-zA-Z]|[0-9]|_|[-(),{}=;?:!+*/<>\[\]\%]|\t|\n|[ ])* {
														      col+= yyleng;
															  yylval.tExpStr =new ExpStr(strdup(yytext),lin,col);
                                                              return STRING; 
															  }
<string>"\'"            BEGIN(0);                         

"program"			{
						col += yyleng;
						return PROGRAM;
					}
"function"			{
						col += yyleng;
						return FUNCTION;
					}
"procedure"			{
						col += yyleng;
						return PROCEDURE;
					}
"var"			    {
						col += yyleng;
						return VAR;
					}
"array"			    {
						col += yyleng;
						return ARRAY;
					}
"not"			    {
						col += yyleng;
						return NOT;
					}
"or"                {
                        col += yyleng;
						return OR;
					}
"and"               {
                        col += yyleng;
						return AND;
					}
"div"               {
                        col += yyleng;
						return DIV;
					}
"of"			    {
						col += yyleng;
						return OF;
					 }
"if"				{
						col += yyleng;
						return KW_IF;
					}
"else"				{
						col += yyleng;
						return KW_ELSE;
					}
"then"              {
                        col += yyleng;
						return KW_THEN;
                    }
"while"				{
						col += yyleng;
						return KW_WHILE;
					}
"return"            {
                        col += yyleng;
						return KW_RETURN;
					}
"do"                {
                     col+=yyleng;
					 return KW_DO;
                    }
"to"                {
                     col+=yyleng;
					 return KW_TO;
                    }
"for"                {
                     col+=yyleng;
					 return KW_FOR;
                    }
"begin"				{
						col += yyleng;
						return KW_BEGIN;
					}
"end"				{
						col += yyleng;
						return KW_END;
					}
"false"				{
						col += yyleng;
						return KW_FALSE;
					}
"true"				{
						col += yyleng;
						return KW_TRUE;
					}
"write"|"writeln"			{
						col += yyleng;
						return WRITE;
					}
"="                {
	                   col += yyleng;
	                   return EQ;
                    }
"<>"                {
	                   col += yyleng;
	                   return NEQ;
                    }
">="				{
						col += yyleng;
						return LE;
					}
"<="				{						
						col += yyleng;
						return SE;
					}
":="                {
                        col += yyleng;
						return ASSIGN;
                    }

"integer"           {
                        col += yyleng;
						return KW_INTEGER;
					}
"real"              {
                        col += yyleng;
						return KW_REAL;
					}
"boolean"           {
                        col += yyleng;
						return KW_BOOLEAN;
					}	
"char"           {
                        col += yyleng;
						return KW_CHAR;
					}
"string"           {
                        col += yyleng;
						return KW_STRING;
					}							
0|[1-9][0-9]*		{
						col += yyleng;
						yylval.tExpInt =new ExpInt(atoi(yytext),lin,col);
						return INTEGER;
					}
					
(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))? |
"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?				|
(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))			{
														col += yyleng;
														yylval.tExpReal =new ExpReal(atof(yytext),lin,col);
														return REAL;
													}
".."                {
                        col += yyleng;
						return KW_DOTS;
					 }	
([a-zA-Z]|_)([a-zA-Z]|[0-9]|_)*	{
									col += yyleng;
									yylval.tIdent = new Ident(strdup(yytext), lin, col);
									return IDENT;
								}
[\t]*				col += 4 * yyleng;
[ ]*				col += yyleng;
\n					lin++; col = 1;

[-(),{}=;?:!+*/<>\[\]\%\.]  {
				col+=yyleng;
				return *yytext;
				}

.					{
						col += yyleng;
					}
%%
