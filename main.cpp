#include "interpreter.hpp"
#include <fstream>
#include <iostream>

extern ASTNode* root;
extern int yyparse();
extern FILE* yyin;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo.ms>" << std::endl;
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (!input) {
        std::cerr << "No se pudo abrir el archivo " << argv[1] << std::endl;
        return 1;
    }

    yyin = input;

    if (yyparse() == 0 && root != nullptr) {
        try {
            Interpreter interpreter;
            interpreter.execute(root);
            delete root;
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