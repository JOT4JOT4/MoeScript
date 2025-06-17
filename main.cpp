#include "interpreter.hpp"
#include <fstream>
#include <iostream>

extern ASTNode* root;
extern int yyparse();
extern FILE* yyin;

int main(int argc, char* argv[]) {
    // Abrir el archivo calculadora.ms
    FILE* input = fopen("nuevo.ms", "r");
    if (!input) {
        std::cerr << "No se pudo abrir el archivo calculadora.ms" << std::endl;
        return 1;
    }
    
    // Asignar el archivo como entrada para el lexer
    yyin = input;

    // Parsear y ejecutar
    if (yyparse() == 0 && root != nullptr) {
        try {
            Interpreter interpreter;
            interpreter.execute(root);
            delete root; // Liberar memoria del AST
        } catch (const std::exception& e) {
            std::cerr << "Error de ejecución: " << e.what() << std::endl;
            delete root;
            fclose(input);
            return 1;
        }
    }

    fclose(input);
    return 0;
}