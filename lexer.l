%{
    #include "parser.tab.h"
    #include <stdio.h>
    int yylineno = 1;  // Agregar esta línea
%}

%option yylineno  // Agregar esta opción

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
ELIF                (moshimoshi|MOSHIMOSHI)
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

{CONST_CADENA}      { yylval.sval = strdup(yytext); printf("\nCONST_CADENA (%s)", yytext); return CONST_CADENA; }

{ELIF}              { printf("\nPALABRA RESERVADA ELIF : (%s)", yytext); return ELIF; }
{IF}                { printf("\nPALABRA RESERVADA IF : (%s)", yytext); return IF; }
{WHILE}             { printf("\nPALABRA RESERVADA WHILE : (%s)", yytext); return WHILE; }
{FOR}               { printf("\nPALABRA RESERVADA FOR : (%s)", yytext); return FOR; }
{ELSE}              { printf("\nPALABRA RESERVADA ELSE : (%s)", yytext); return ELSE; }
{INTEGER}           { printf("\nPALABRA RESERVADA INTEGER : (%s)", yytext); return INTEGER; }
{FLOAT}             { printf("\nPALABRA RESERVADA FLOAT : (%s)", yytext); return FLOAT; }
{BOOLEAN}           { printf("\nPALABRA RESERVADA BOOLEAN : (%s)", yytext); return BOOLEAN; }
{PRINT}             { printf("\nPALABRA RESERVADA PRINT : (%s)", yytext); return PRINT; }
{READ}              { printf("\nPALABRA RESERVADA READ : (%s)", yytext); return READ; }
{NEW}               { printf("\nPALABRA RESERVADA NEW : (%s)", yytext); return NEW; }
{FUNC}              { printf("\nPALABRA RESERVADA FUNC : (%s)", yytext); return FUNC; }
{RETURN}            { printf("\nPALABRA RESERVADA RETURN : (%s)", yytext); return RETURN; }

{IDENTIFICADOR}     { yylval.sval = strdup(yytext); printf("\nIDENTIFICADOR (%s)", yytext); return IDENTIFICADOR; }
{CONST_INTEGER}     { yylval.ival = atoi(yytext); printf("\nCONST_INTEGER (%s)", yytext); return CONST_INTEGER; }
{CONST_FLOAT}       { yylval.fval = atof(yytext); printf("\nCONST_FLOAT (%s)", yytext); return CONST_FLOAT; }

{CHAR_COMA}         { printf("\nCHAR_COMA (%s)", yytext); return CHAR_COMA; }
{CHAR_PUNTO}        { printf("TOKEN: CHAR_PUNTO\n"); return CHAR_PUNTO; }
{CHAR_PUNTOYCOMA}   { printf("TOKEN: CHAR_PUNTOYCOMA\n"); return CHAR_PUNTOYCOMA; }
{CHAR_DOSPUNTOS}    { printf("TOKEN: CHAR_DOSPUNTOS\n"); return CHAR_DOSPUNTOS; }

{OP_SUMA}           { printf("\nOP_SUMA (%s)", yytext); return OP_SUMA; }
{OP_RESTA}          { printf("\nOP_RESTA (%s)", yytext); return OP_RESTA; }
{OP_MULT}           { printf("\nOP_MULT (%s)", yytext); return OP_MULT; }
{OP_DIV}            { printf("\nOP_DIV (%s)", yytext); return OP_DIV; }
{OP_COMP_IGUAL}     { printf("\nOP_COMP_IGUAL (%s)", yytext); return OP_COMP_IGUAL; }
{OP_MAYORIGUAL}     { printf("\nOP_MAYORIGUAL (%s)", yytext); return OP_MAYORIGUAL; }
{OP_MENORIGUAL}     { printf("\nOP_MENORIGUAL (%s)", yytext); return OP_MENORIGUAL; }
{OP_DISTINTO}       { printf("\nOP_DISTINTO (%s)", yytext); return OP_DISTINTO; }
{OP_IGUAL}          { printf("\nOP_IGUAL (%s)", yytext); return OP_IGUAL; }
{OP_MAYOR}          { printf("\nOP_MAYOR (%s)", yytext); return OP_MAYOR; }
{OP_MENOR}          { printf("\nOP_MENOR (%s)", yytext); return OP_MENOR; }

{LLAVE_A}           { printf("\nLLAVE_A (%s)", yytext); return LLAVE_A; }
{LLAVE_C}           { printf("\nLLAVE_C (%s)", yytext); return LLAVE_C; }
{PARENTESIS_A}      { printf("\nPARENTESIS_A (%s)", yytext); return PARENTESIS_A; }
{PARENTESIS_C}      { printf("\nPARENTESIS_C (%s)", yytext); return PARENTESIS_C; }
{FIN_SENTENCIA}     { printf("\nFIN_SENTENCIA (%s)", yytext); return FIN_SENTENCIA; }

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



