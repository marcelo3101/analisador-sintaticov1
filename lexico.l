%{
#include <stdio.h>
#include "y.tab.h"
%}

id          [a-zA-Z][a-zA-Z0-9]*
numero      [-+]?[0-9]+(\.[0-9]*)?|(\.[0-9]+)
comentario  "/*"([^*]|(\*+[^*/]))*\*+/
whitespace  [ \t\n]+

%%
"="           { printf("ATRIBUICAO: %s\n", yytext); return ATRIBUICAO; }
"+"           { printf("ADICAO: %s\n", yytext); return ADICAO; }
"-"           { printf("SUBTRACAO: %s\n", yytext); return SUBTRACAO; }
"*"           { printf("MULTIPLICACAO: %s\n", yytext); return MULTIPLICACAO; }
"/"           { printf("DIVISAO: %s\n", yytext); return DIVISAO; }
";"           { printf("PONTOVIRGULA: %s\n", yytext); return PONTOVIRGULA; }
","           { printf("VIRGULA: %s\n", yytext); return VIRGULA; }
"("           { printf("PARENTESESQUERDO: %s\n", yytext); return PARENTESESQUERDO; }
")"           { printf("PARENTESEDIREITO: %s\n", yytext); return PARENTESEDIREITO; }
"["           { printf("COLCHETESQUERDO: %s\n", yytext); return COLCHETESQUERDO; }
"]"           { printf("COLCHETEDIREITO: %s\n", yytext); return COLCHETEDIREITO; }
"{"           { printf("CHAVESQUERDA: %s\n", yytext); return CHAVESQUERDA; }
"}"           { printf("CHAVEDIREITA: %s\n", yytext); return CHAVEDIREITA; }
"<"           { printf("MENOR: %s\n", yytext); return MENOR; }
"<="          { printf("MENORIGUAL: %s\n", yytext); return MENORIGUAL; }
">"           { printf("MAIOR: %s\n", yytext); return MAIOR; }
">="          { printf("MAIORIGUAL: %s\n", yytext); return MAIORIGUAL; }
"=="          { printf("IGUAL: %s\n", yytext); return IGUAL; }
"!="          { printf("DIFERENTE: %s\n", yytext); return DIFERENTE; }
"if"          { printf("IF: %s\n", yytext); return IF; }
"else"        { printf("ELSE: %s\n", yytext); return ELSE; }
"while"       { printf("WHILE: %s\n", yytext); return WHILE; }  
"return"      { printf("RETURN: %s\n", yytext); return RETURN; }
"void"        { printf("VOID: %s\n", yytext); return VOID; }
"int"         { printf("INT: %s\n", yytext); return INT; }
{id}          { printf("IDENTIFICADOR: %s\n", yytext); return IDENTIFICADOR; }
{numero}      { printf("NUMERO: %s\n", yytext); return NUMERO; }
{whitespace}  { /* Ignora espacos em branco */ }
.             { printf("UNKNOWN: %s\n", yytext); }
%%
//{comentario}  { printf("COMENTARIO: %s\n", yytext); }

int yywrap() {
    return 1;
}
