#pragma once
#include <unordered_map>
#include <any>
#include <memory>
#include "ast.hpp"

// Forward declaration
class Environment;

// Representa un valor en tiempo de ejecución
class RuntimeValue {
public:
    enum class Type {
        INTEGER,
        FLOAT,
        STRING,
        BOOLEAN,
        NULL_VALUE
    };

    RuntimeValue() : type(Type::NULL_VALUE) {}
    RuntimeValue(int v) : type(Type::INTEGER), intValue(v) {}
    RuntimeValue(float v) : type(Type::FLOAT), floatValue(v) {}
    RuntimeValue(const std::string& v) : type(Type::STRING), stringValue(v) {}
    RuntimeValue(bool v) : type(Type::BOOLEAN), boolValue(v) {}

    Type type;
    union {
        int intValue;
        float floatValue;
        bool boolValue;
    };
    std::string stringValue; // Fuera de la union porque tiene constructor

    std::string toString() const;
};

// Representa una función definida
struct Function {
    std::vector<std::string> parametros;
    std::unique_ptr<ASTNode> cuerpo;
    std::shared_ptr<Environment> closure;

    Function(const std::vector<std::string>& params, std::unique_ptr<ASTNode> body, std::shared_ptr<Environment> env)
        : parametros(params), cuerpo(std::move(body)), closure(env) {}
};

// Ambiente de ejecución (variables y funciones)
class Environment {
public:
    Environment(std::shared_ptr<Environment> parent = nullptr) : parent(parent) {}

    void define(const std::string& name, const RuntimeValue& value) {
        variables[name] = value;
    }

    RuntimeValue* lookup(const std::string& name) {
        auto it = variables.find(name);
        if (it != variables.end()) {
            return &it->second;
        }
        if (parent) {
            return parent->lookup(name);
        }
        return nullptr;
    }

    void defineFunction(const std::string& name, std::shared_ptr<Function> func) {
        functions[name] = func;
    }

    std::shared_ptr<Function> lookupFunction(const std::string& name) {
        auto it = functions.find(name);
        if (it != functions.end()) {
            return it->second;
        }
        if (parent) {
            return parent->lookupFunction(name);
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, RuntimeValue> variables;
    std::unordered_map<std::string, std::shared_ptr<Function>> functions;
    std::shared_ptr<Environment> parent;
};

// El intérprete principal
class Interpreter {
public:
    Interpreter() : globalEnv(std::make_shared<Environment>()) {}

    RuntimeValue evaluate(ASTNode* node);
    void execute(ASTNode* root);

private:
    std::shared_ptr<Environment> globalEnv;
    RuntimeValue evaluateReturn(ReturnNode* node);
    bool isReturning = false;
    RuntimeValue returnValue;
    
    // Métodos auxiliares para evaluar diferentes tipos de nodos
    RuntimeValue evaluatePrograma(ProgramaNode* node);
    RuntimeValue evaluateDeclaracion(DeclaracionNode* node);
    RuntimeValue evaluateAsignacion(AsignacionNode* node);
    RuntimeValue evaluateExpresion(ExpresionNode* node);
    RuntimeValue evaluateLiteral(LiteralNode* node);
    RuntimeValue evaluateIdentificador(IdentificadorNode* node);
    RuntimeValue evaluateControl(ControlNode* node);
    RuntimeValue evaluateImpresion(ImpresionNode* node);
    RuntimeValue evaluateLectura(LecturaNode* node);
    RuntimeValue evaluateLlamadaFuncion(LlamadaFuncionNode* node);
    RuntimeValue evaluateFuncion(FuncionNode* node);
};