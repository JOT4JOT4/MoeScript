%code requires {
    #include <vector>
    #include <memory>
    #include "ast.hpp"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"
void yyerror(const char *s);
int yylex(void);
ASTNode* root = nullptr; // Nodo raíz global
%}

%union {
    int ival;
    float fval;
    char* sval;
    ASTNode* node;
    std::vector<std::unique_ptr<ASTNode>>* vec;
    std::vector<std::string>* strvec;
}

%token IF WHILE FOR ELSE ELIF INTEGER FLOAT BOOLEAN PRINT READ NEW
%token FUNC RETURN
%token IDENTIFICADOR CONST_INTEGER CONST_FLOAT CONST_CADENA
%token OP_SUMA OP_RESTA OP_MULT OP_DIV OP_IGUAL OP_MAYOR OP_MENOR
%token OP_MAYORIGUAL OP_MENORIGUAL OP_COMP_IGUAL OP_NEGACION OP_DISTINTO
%token LLAVE_A LLAVE_C PARENTESIS_A PARENTESIS_C FIN_SENTENCIA
%token CHAR_COMA CHAR_PUNTO CHAR_PUNTOYCOMA CHAR_DOSPUNTOS
%token INI_COMENTARIO FIN_COMENTARIO

%left OP_SUMA OP_RESTA
%left OP_MULT OP_DIV
%nonassoc OP_IGUAL
%nonassoc OP_COMP_IGUAL OP_DISTINTO
%nonassoc OP_MAYOR OP_MENOR OP_MAYORIGUAL OP_MENORIGUAL

%type <node> programa sentencia sentencia_lista declaracion asignacion expresion estructura_control impresion lectura argumento comentario funcion llamada_funcion bloque_sentencias
%type <vec> argumentos
%type <strvec> parametros lista_parametros

%type <sval> tipo IDENTIFICADOR CONST_CADENA
%type <ival> CONST_INTEGER
%type <fval> CONST_FLOAT


%%

programa:
    sentencia_lista { root = $1; }
;

sentencia_lista:
    sentencia sentencia_lista {
        auto prog = new ProgramaNode();
        prog->sentencias.push_back(std::unique_ptr<ASTNode>($1));
        if ($2) {
            auto next = static_cast<ProgramaNode*>($2);
            for (auto& s : next->sentencias)
                prog->sentencias.push_back(std::move(s));
            delete next;
        }
        $$ = prog;
    }
    | /* vacío */ { $$ = new ProgramaNode(); }
;

sentencia:
    declaracion FIN_SENTENCIA { $$ = $1; }
    | asignacion FIN_SENTENCIA { $$ = $1; }
    | impresion FIN_SENTENCIA { $$ = $1; }
    | lectura FIN_SENTENCIA { $$ = $1; }
    | estructura_control { $$ = $1; }
    | comentario { $$ = $1; }
    | funcion { $$ = $1; }
    | RETURN expresion FIN_SENTENCIA { 
        $$ = new ReturnNode(std::unique_ptr<ASTNode>($2)); 
    }
;

funcion:
    FUNC IDENTIFICADOR PARENTESIS_A parametros PARENTESIS_C bloque_sentencias {
        printf(">>> Entró a FUNCION con nombre: %s\n", $2);
        $$ = new FuncionNode($2, *$4, std::unique_ptr<ASTNode>($6));
        free($2);
        delete $4;
    }
;

parametros:
    /* vacío */ { 
        $$ = new std::vector<std::string>(); 
    }
    | lista_parametros { $$ = $1; }
;

lista_parametros:
    IDENTIFICADOR { 
        auto v = new std::vector<std::string>(); 
        v->push_back($1); 
        free($1); 
        $$ = v; 
    }
    | lista_parametros CHAR_COMA IDENTIFICADOR { 
        $1->push_back($3); 
        free($3); 
        $$ = $1;
    }
;

llamada_funcion:
    IDENTIFICADOR PARENTESIS_A argumentos PARENTESIS_C {
        $$ = new LlamadaFuncionNode($1, std::move(*$3));
        free($1);
        delete $3;
    }
;

declaracion:
    tipo IDENTIFICADOR {
        $$ = new DeclaracionNode(std::string($1), std::string($2), nullptr);
        free($1); free($2);
    }
    | tipo IDENTIFICADOR OP_IGUAL expresion {
        $$ = new DeclaracionNode(std::string($1), std::string($2), std::unique_ptr<ASTNode>($4));
        free($1); free($2);
    }
;

tipo:
    INTEGER { $$ = strdup("senpai"); }
    | FLOAT { $$ = strdup("kohai"); }
    | BOOLEAN { $$ = strdup("bool"); }
;

asignacion:
    IDENTIFICADOR OP_IGUAL expresion {
        $$ = new AsignacionNode($1, std::unique_ptr<ASTNode>($3));
        free($1);
    }
;

expresion:
    expresion OP_SUMA expresion {
        auto node = new ExpresionNode("+");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_RESTA expresion {
        auto node = new ExpresionNode("-");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_MULT expresion {
        auto node = new ExpresionNode("*");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_DIV expresion {
        auto node = new ExpresionNode("/");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_COMP_IGUAL expresion {
        auto node = new ExpresionNode("==");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_DISTINTO expresion {
        auto node = new ExpresionNode("!=");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_MAYOR expresion {
        auto node = new ExpresionNode(">");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_MENOR expresion {
        auto node = new ExpresionNode("<");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_MAYORIGUAL expresion {
        auto node = new ExpresionNode(">=");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | expresion OP_MENORIGUAL expresion {
        auto node = new ExpresionNode("<=");
        node->operandos.push_back(std::unique_ptr<ASTNode>($1));
        node->operandos.push_back(std::unique_ptr<ASTNode>($3));
        $$ = node;
    }
    | OP_NEGACION expresion {
        auto node = new ExpresionNode("!");
        node->operandos.push_back(std::unique_ptr<ASTNode>($2));
        $$ = node;
    }
    | PARENTESIS_A expresion PARENTESIS_C { $$ = $2; }
    | CONST_INTEGER { $$ = new LiteralNode(std::to_string($1)); }
    | CONST_FLOAT { $$ = new LiteralNode(std::to_string($1)); }
    | CONST_CADENA { $$ = new LiteralNode($1); free($1); }
    | IDENTIFICADOR { $$ = new IdentificadorNode($1); free($1); }
    | llamada_funcion { $$ = $1; }
;

estructura_control:
    IF PARENTESIS_A expresion PARENTESIS_C bloque_sentencias {
        auto node = new ControlNode("if");
        node->condicion = std::unique_ptr<ASTNode>($3);
        auto cuerpo = static_cast<ProgramaNode*>($5);
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        $$ = node;
    }
    | IF PARENTESIS_A expresion PARENTESIS_C bloque_sentencias ELIF PARENTESIS_A expresion PARENTESIS_C bloque_sentencias {
        // Crear nodo if principal
        auto node = new ControlNode("if");
        node->condicion = std::unique_ptr<ASTNode>($3);
        auto cuerpoIf = static_cast<ProgramaNode*>($5);
        for (auto& s : cuerpoIf->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpoIf;

        // Crear nodo elif
        auto elifNode = new ControlNode("if");
        elifNode->condicion = std::unique_ptr<ASTNode>($8);
        auto cuerpoElif = static_cast<ProgramaNode*>($10);
        for (auto& s : cuerpoElif->sentencias)
            elifNode->cuerpo.push_back(std::move(s));
        delete cuerpoElif;

        // Conectar elif como elseCuerpo del if principal
        node->elseCuerpo = std::unique_ptr<ASTNode>(elifNode);
        $$ = node;
    }
    | IF PARENTESIS_A expresion PARENTESIS_C bloque_sentencias ELSE bloque_sentencias {
        auto node = new ControlNode("if");
        node->condicion = std::unique_ptr<ASTNode>($3);
        auto cuerpoIf = static_cast<ProgramaNode*>($5);
        for (auto& s : cuerpoIf->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpoIf;

        auto elseNode = new ControlNode("else");
        auto cuerpoElse = static_cast<ProgramaNode*>($7);
        for (auto& s : cuerpoElse->sentencias)
            elseNode->cuerpo.push_back(std::move(s));
        delete cuerpoElse;
        
        node->elseCuerpo = std::unique_ptr<ASTNode>(elseNode);
        $$ = node;
    }
    | WHILE PARENTESIS_A expresion PARENTESIS_C bloque_sentencias {
        auto node = new ControlNode("while");
        node->condicion = std::unique_ptr<ASTNode>($3);
        auto cuerpo = static_cast<ProgramaNode*>($5);
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        $$ = node;
    }
    | FOR PARENTESIS_A asignacion CHAR_PUNTOYCOMA expresion CHAR_PUNTOYCOMA asignacion PARENTESIS_C bloque_sentencias {
        auto node = new ControlNode("for");
        node->condicion = std::unique_ptr<ASTNode>($5);
        auto cuerpo = static_cast<ProgramaNode*>($9);
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        $$ = node;
    }
    | ELSE bloque_sentencias {
        auto node = new ControlNode("else");
        auto cuerpo = static_cast<ProgramaNode*>($2);
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        $$ = node;
    }
;

bloque_sentencias:
    LLAVE_A sentencia_lista LLAVE_C { $$ = $2; }
;

impresion:
    PRINT PARENTESIS_A argumentos PARENTESIS_C {
        auto node = new ImpresionNode();
        node->argumentos = std::move(*$3);
        delete $3;
        $$ = node;
    }
;

argumentos:
    argumento {
        auto vec = new std::vector<std::unique_ptr<ASTNode>>();
        vec->push_back(std::unique_ptr<ASTNode>($1));
        $$ = vec;
    }
    | argumento CHAR_COMA argumentos {
        auto vec = $3;
        vec->insert(vec->begin(), std::unique_ptr<ASTNode>($1));
        $$ = vec;
    }
;

argumento:
    CONST_CADENA { $$ = new LiteralNode($1); free($1); }
    | expresion { $$ = $1; }
;

lectura:
    READ PARENTESIS_A IDENTIFICADOR PARENTESIS_C {
        $$ = new LecturaNode($3);
        free($3);
    }
;

comentario:
    INI_COMENTARIO texto FIN_COMENTARIO { $$ = nullptr; }
;

texto:
    texto elemento_texto
    | elemento_texto
;

elemento_texto:
    CONST_CADENA
    | IDENTIFICADOR
    | CONST_INTEGER
    | CONST_FLOAT
    | OP_SUMA
    | OP_RESTA
    | OP_MULT
    | OP_DIV
    | OP_IGUAL
    | OP_MAYOR
    | OP_MENOR
    | OP_MAYORIGUAL
    | OP_MENORIGUAL
    | OP_COMP_IGUAL
    | OP_NEGACION
    | OP_DISTINTO
    | CHAR_COMA
    | CHAR_PUNTO
    | CHAR_PUNTOYCOMA
    | CHAR_DOSPUNTOS
    | FIN_SENTENCIA
;

%%

extern int yylineno;
extern char* yytext;

void yyerror(const char *s) {
    fprintf(stderr, "\nError de sintaxis en línea %d: %s\n", yylineno, s);
    fprintf(stderr, "Token actual: '%s'\n", yytext);
    fprintf(stderr, "Posibles causas:\n");
    fprintf(stderr, "- Token inesperado en esta posición\n");
    fprintf(stderr, "- Falta un token requerido antes de '%s'\n", yytext);
    fprintf(stderr, "- Error en la estructura de la sentencia\n");
    
    // Sugerencias específicas basadas en el token actual
    if (strcmp(yytext, "(") == 0) {
        fprintf(stderr, "Sugerencias:\n");
        fprintf(stderr, "- Verificar que la función esté correctamente declarada\n");
        fprintf(stderr, "- Asegurarse de que los parámetros estén separados por comas\n");
    }
    else if (strcmp(yytext, ")") == 0) {
        fprintf(stderr, "Sugerencias:\n");
        fprintf(stderr, "- Verificar que todos los paréntesis estén balanceados\n");
        fprintf(stderr, "- Revisar la lista de parámetros/argumentos\n");
    }
    else if (strcmp(yytext, "{") == 0 || strcmp(yytext, "}") == 0) {
        fprintf(stderr, "Sugerencias:\n");
        fprintf(stderr, "- Verificar que todas las llaves estén balanceadas\n");
        fprintf(stderr, "- Asegurarse de que el bloque de código esté completo\n");
    }
    else if (strcmp(yytext, "-chan") == 0) {
        fprintf(stderr, "Sugerencias:\n");
        fprintf(stderr, "- Verificar que la sentencia esté completa\n");
        fprintf(stderr, "- Asegurarse de que no falten operadores o expresiones\n");
    }
}

