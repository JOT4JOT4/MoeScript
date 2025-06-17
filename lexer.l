%{
    #include "parser.tab.h"
    #include <stdio.h>
%}

%option yylineno

/* SECCION DE TOKENS */

DIGITO              [0-9]
LETRA               [a-zA-Z_]
ESPACIO             [ ]
INI_COMENTARIO      "/*"
FIN_COMENTARIO      "*/"
CHAR_COMA           ","
CHAR_PUNTO          "."
CHAR_PUNTOYCOMA     ";"
CHAR_DOSPUNTOS      ":"
FIN_SENTENCIA       "-chan"

/* ESTA MALDITA COSA no la cambien aveces el Copilot piensa que esta mal pero no sabe nadaaaaaa*/
CONST_CADENA        \"[^\n"]*\"
IDENTIFICADOR       {LETRA}({LETRA}|{DIGITO})*
CONST_INTEGER       (-?[1-9][0-9]{0,4})|0
CONST_FLOAT         {DIGITO}{0,8}{CHAR_PUNTO}{DIGITO}{1,8}

/* OPERADORES LOGICOS Y ARITMETICOS BÁSICOS */
OP_SUMA             [+]
OP_RESTA            [-]
OP_MULT             [*]
OP_DIV              [/]
OP_IGUAL            [=]
OP_MAYOR            [>]
OP_MENOR            [<]
OP_MAYORIGUAL       ">="
OP_MENORIGUAL       "<="
OP_COMP_IGUAL       "=="
OP_NEGACION         [!]
OP_DISTINTO         "!="  

/* CARACTERES DE APERTURA Y CIERRE */

LLAVE_A             [{]
LLAVE_C             [}]
PARENTESIS_A        [(]
PARENTESIS_C        [)]

/* PALABRAS RESERVADAS */

IF                  (moshi|MOSHI)
WHILE               (kawaii|KAWAII)
FOR                 (douka|DOUKA)
ELSE                (nani|NANI)
INTEGER             (senpai|SENPAI)
FLOAT               (kohai|KOHAI)
BOOLEAN             (tsundere|Tsundere|yandere|Yandere)
PRINT               (baka|BAKA)
READ                (yomu|YOMU)
NEW                 (doki|DOKI)
FUNC                (sugoi|SUGOI)
RETURN              (uwu|UWU)

%%

{CONST_CADENA}      { yylval.sval = strdup(yytext); return CONST_CADENA; }

{IF}                { return IF; }
{WHILE}             { return WHILE; }
{FOR}               { return FOR; }
{ELSE}              { return ELSE; }
{INTEGER}           { return INTEGER; }
{FLOAT}             { return FLOAT; }
{BOOLEAN}           { return BOOLEAN; }
{PRINT}             { return PRINT; }
{READ}              { return READ; }
{NEW}               { return NEW; }
{FUNC}              { return FUNC; }
{RETURN}            { return RETURN; }

{IDENTIFICADOR}     { yylval.sval = strdup(yytext); return IDENTIFICADOR; }
{CONST_INTEGER}     { yylval.ival = atoi(yytext); return CONST_INTEGER; }
{CONST_FLOAT}       { yylval.fval = atof(yytext); return CONST_FLOAT; }

{CHAR_COMA}         { return CHAR_COMA; }
{CHAR_PUNTO}        { return CHAR_PUNTO; }
{CHAR_PUNTOYCOMA}   { return CHAR_PUNTOYCOMA; }
{CHAR_DOSPUNTOS}    { return CHAR_DOSPUNTOS; }

{OP_SUMA}           { return OP_SUMA; }
{OP_RESTA}          { return OP_RESTA; }
{OP_MULT}           { return OP_MULT; }
{OP_DIV}            { return OP_DIV; }
{OP_COMP_IGUAL}     { return OP_COMP_IGUAL; }
{OP_MAYORIGUAL}     { return OP_MAYORIGUAL; }
{OP_MENORIGUAL}     { return OP_MENORIGUAL; }
{OP_DISTINTO}       { return OP_DISTINTO; }
{OP_IGUAL}          { return OP_IGUAL; }
{OP_MAYOR}          { return OP_MAYOR; }
{OP_MENOR}          { return OP_MENOR; }

{LLAVE_A}           { return LLAVE_A; }
{LLAVE_C}           { return LLAVE_C; }
{PARENTESIS_A}      { return PARENTESIS_A; }
{PARENTESIS_C}      { return PARENTESIS_C; }
{FIN_SENTENCIA}     { return FIN_SENTENCIA; }

"\n"                { yylineno++; }  // Actualizar el contador de líneas
"\t"
" "

[ \t\r\n]+          { /* Ignorar espacios en blanco */ }

. {
    fprintf(stderr, "\nLEX ERROR: carácter desconocido (%s)\n", yytext);
    exit(1);
}

%%

int yywrap() { return 1; }



