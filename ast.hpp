#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

// Tipos de nodos
enum class ASTNodeType {
    Programa,
    Sentencia,
    Declaracion,
    Asignacion,
    Expresion,
    Impresion,
    Lectura,
    Control,
    Literal,
    Identificador,
    Funcion,
    LlamadaFuncion,
    Return
};

// Nodo base
struct ASTNode {
    ASTNodeType type;
    virtual ~ASTNode() = default;
    // Hacemos print() virtual pero con implementación por defecto
    virtual void print(int indent = 0) const { }
};

// Nodo para el programa (lista de sentencias)
struct ProgramaNode : ASTNode {
    std::vector<std::unique_ptr<ASTNode>> sentencias;
    ProgramaNode(std::vector<std::unique_ptr<ASTNode>> s = {})
        : sentencias(std::move(s)) { type = ASTNodeType::Programa; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Programa\n";
        for (const auto& s : sentencias) s->print(indent + 2);
    }
};

// Declaración de variable
struct DeclaracionNode : ASTNode {
    std::string tipo;
    std::string nombre;
    std::unique_ptr<ASTNode> valor; // Puede ser nulo
    DeclaracionNode(const std::string& t, const std::string& n, std::unique_ptr<ASTNode> v)
        : tipo(t), nombre(n), valor(std::move(v)) { type = ASTNodeType::Declaracion; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Declaracion: " << tipo << " " << nombre << "\n";
        if (valor) valor->print(indent + 2);
    }
};

// Asignación
struct AsignacionNode : ASTNode {
    std::string nombre;
    std::unique_ptr<ASTNode> valor;
    AsignacionNode(const std::string& n, std::unique_ptr<ASTNode> v)
        : nombre(n), valor(std::move(v)) { type = ASTNodeType::Asignacion; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Asignacion: " << nombre << "\n";
        valor->print(indent + 2);
    }
};

// Expresión (operador y operandos)
struct ExpresionNode : ASTNode {
    std::string operador;
    std::vector<std::unique_ptr<ASTNode>> operandos;
    ExpresionNode(const std::string& op) : operador(op) { type = ASTNodeType::Expresion; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Expresion: " << operador << "\n";
        for (const auto& o : operandos) o->print(indent + 2);
    }
};

// Literal (número, cadena, etc.)
struct LiteralNode : ASTNode {
    std::string valor;
    LiteralNode(const std::string& v) : valor(v) { type = ASTNodeType::Literal; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Literal: " << valor << "\n";
    }
};

// Identificador (nombre de variable)
struct IdentificadorNode : ASTNode {
    std::string nombre;
    IdentificadorNode(const std::string& n) : nombre(n) { type = ASTNodeType::Identificador; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Identificador: " << nombre << "\n";
    }
};

// Impresión (print)
struct ImpresionNode : ASTNode {
    std::vector<std::unique_ptr<ASTNode>> argumentos;
    ImpresionNode(std::vector<std::unique_ptr<ASTNode>> args = {})
        : argumentos(std::move(args)) { type = ASTNodeType::Impresion; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Impresion\n";
        for (const auto& arg : argumentos) arg->print(indent + 2);
    }
};

// Lectura (input)
struct LecturaNode : ASTNode {
    std::string nombre;  // Nombre de la variable a leer

    LecturaNode(const std::string& n) 
        : nombre(n) { type = ASTNodeType::Lectura; }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Lectura: " << nombre << "\n";
    }
};

// Control de flujo (if, while, for, else)
struct ControlNode : ASTNode {
    std::string tipo;
    std::unique_ptr<ASTNode> condicion;
    std::vector<std::unique_ptr<ASTNode>> cuerpo;
    std::unique_ptr<ASTNode> elseCuerpo;  // Agregar este miembro

    ControlNode(const std::string& t) 
        : tipo(t) { type = ASTNodeType::Control; }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Control: " << tipo << "\n";
        if (condicion) {
            std::cout << std::string(indent + 2, ' ') << "Condicion:\n";
            condicion->print(indent + 4);
        }
        std::cout << std::string(indent + 2, ' ') << "Cuerpo:\n";
        for (const auto& s : cuerpo) s->print(indent + 4);
        if (elseCuerpo) {
            std::cout << std::string(indent + 2, ' ') << "Else:\n";
            elseCuerpo->print(indent + 4);
        }
    }
};

// Función
struct FuncionNode : ASTNode {
    std::string nombre;
    std::vector<std::string> parametros;
    std::unique_ptr<ASTNode> cuerpo;
    FuncionNode(const std::string& n, const std::vector<std::string>& p, std::unique_ptr<ASTNode> c)
        : nombre(n), parametros(p), cuerpo(std::move(c)) { type = ASTNodeType::Funcion; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Funcion: " << nombre << "\n";
        std::cout << std::string(indent + 2, ' ') << "Parametros:";
        for (const auto& param : parametros) std::cout << " " << param;
        std::cout << "\n";
        if (cuerpo) cuerpo->print(indent + 2);
    }
};

// Llamada a función
struct LlamadaFuncionNode : ASTNode {
    std::string nombre;
    std::vector<std::unique_ptr<ASTNode>> argumentos;
    LlamadaFuncionNode(const std::string& n, std::vector<std::unique_ptr<ASTNode>> args)
        : nombre(n), argumentos(std::move(args)) { type = ASTNodeType::LlamadaFuncion; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "LlamadaFuncion: " << nombre << "\n";
        for (const auto& arg : argumentos) arg->print(indent + 2);
    }
};

// Return
struct ReturnNode : ASTNode {
    std::unique_ptr<ASTNode> valor;
    ReturnNode(std::unique_ptr<ASTNode> v) : valor(std::move(v)) { type = ASTNodeType::Return; }
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Return\n";
        if (valor) valor->print(indent + 2);
    }
};