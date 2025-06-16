#include <fstream>
#include "ast.h"

extern ASTNode* root; // Esto le dice a main.cpp que root está definida en otro archivo
extern int yyparse(); // Declaración de la función yyparse generada por Bison

int main() {
    yyparse();
    if (root) {
        std::ofstream out("programa_generado.cpp");
        out << "#include <iostream>\n";
        out << "int main() {\n";
        root->generarCodigo(out, 2);
        out << "  return 0;\n}\n";
        out.close();
        std::cout << "Código C++ generado en programa_generado.cpp\n";
        delete root;
    }
    return 0;
}