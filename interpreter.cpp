#include "interpreter.hpp"
#include <iostream>
#include <sstream>

RuntimeValue Interpreter::evaluate(ASTNode* node) {
    switch (node->type) {
        case ASTNodeType::Programa:
            return evaluatePrograma(static_cast<ProgramaNode*>(node));
        case ASTNodeType::Declaracion:
            return evaluateDeclaracion(static_cast<DeclaracionNode*>(node));
        case ASTNodeType::Asignacion:
            return evaluateAsignacion(static_cast<AsignacionNode*>(node));
        case ASTNodeType::Expresion:
            return evaluateExpresion(static_cast<ExpresionNode*>(node));
        case ASTNodeType::Literal:
            return evaluateLiteral(static_cast<LiteralNode*>(node));
        case ASTNodeType::Identificador:
            return evaluateIdentificador(static_cast<IdentificadorNode*>(node));
        case ASTNodeType::Control:
            return evaluateControl(static_cast<ControlNode*>(node));
        case ASTNodeType::Impresion:
            return evaluateImpresion(static_cast<ImpresionNode*>(node));
        case ASTNodeType::Lectura:
            return evaluateLectura(static_cast<LecturaNode*>(node));
        case ASTNodeType::LlamadaFuncion:
            return evaluateLlamadaFuncion(static_cast<LlamadaFuncionNode*>(node));
        case ASTNodeType::Funcion:
            return evaluateFuncion(static_cast<FuncionNode*>(node));
        case ASTNodeType::Return:
            return evaluateReturn(static_cast<ReturnNode*>(node));
        default:
            throw std::runtime_error("Tipo de nodo no soportado");
    }
}

RuntimeValue Interpreter::evaluatePrograma(ProgramaNode* node) {
    RuntimeValue lastValue;
    for (const auto& sentencia : node->sentencias) {
        lastValue = evaluate(sentencia.get());
        if (isReturning) {
            isReturning = false;
            return returnValue;
        }
    }
    return lastValue;
}

RuntimeValue Interpreter::evaluateDeclaracion(DeclaracionNode* node) {
    RuntimeValue valor;
    if (node->valor) {
        valor = evaluate(node->valor.get());
    } else {
        // Valor por defecto según el tipo
        if (node->tipo == "senpai") valor = RuntimeValue(0);
        else if (node->tipo == "kohai") valor = RuntimeValue(0.0f);
        else if (node->tipo == "bool") valor = RuntimeValue(false);
        else valor = RuntimeValue();
    }
    globalEnv->define(node->nombre, valor);
    return valor;
}

RuntimeValue Interpreter::evaluateAsignacion(AsignacionNode* node) {
    RuntimeValue valor = evaluate(node->valor.get());
    auto* var = globalEnv->lookup(node->nombre);
    if (!var) {
        throw std::runtime_error("Variable no declarada: " + node->nombre);
    }
    *var = valor;
    return valor;
}

RuntimeValue Interpreter::evaluateExpresion(ExpresionNode* node) {
    if (node->operandos.size() == 1) {
        // Operador unario
        RuntimeValue operand = evaluate(node->operandos[0].get());
        if (node->operador == "!") {
            return RuntimeValue(!operand.boolValue);
        }
        throw std::runtime_error("Operador unario no soportado: " + node->operador);
    }
    
    // Operadores binarios
    RuntimeValue left = evaluate(node->operandos[0].get());
    RuntimeValue right = evaluate(node->operandos[1].get());

    if (node->operador == "+") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue + right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT || right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(static_cast<float>(left.floatValue) + static_cast<float>(right.floatValue));
    }

    // Agregar implementación de operadores faltantes
    else if (node->operador == "-") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue - right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT || right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(static_cast<float>(left.floatValue) - static_cast<float>(right.floatValue));
    }
    
    else if (node->operador == "*") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue * right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT || right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(static_cast<float>(left.floatValue) * static_cast<float>(right.floatValue));
    }
    else if (node->operador == "/") {
        if (right.type == RuntimeValue::Type::INTEGER && right.intValue == 0)
            throw std::runtime_error("División por cero");
        if (right.type == RuntimeValue::Type::FLOAT && right.floatValue == 0.0f)
            throw std::runtime_error("División por cero");
            
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue / right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT || right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(static_cast<float>(left.floatValue) / static_cast<float>(right.floatValue));
    }
    else if (node->operador == "==") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue == right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT && right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(left.floatValue == right.floatValue);
        if (left.type == RuntimeValue::Type::STRING && right.type == RuntimeValue::Type::STRING)
            return RuntimeValue(left.stringValue == right.stringValue);
        // Si los tipos son diferentes, convertir a float para comparar
        float leftVal = (left.type == RuntimeValue::Type::INTEGER) ? left.intValue : left.floatValue;
        float rightVal = (right.type == RuntimeValue::Type::INTEGER) ? right.intValue : right.floatValue;
        return RuntimeValue(leftVal == rightVal);
    }
    else if (node->operador == "!=") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue != right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT && right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(left.floatValue != right.floatValue);
        if (left.type == RuntimeValue::Type::STRING && right.type == RuntimeValue::Type::STRING)
            return RuntimeValue(left.stringValue != right.stringValue);
        float leftVal = (left.type == RuntimeValue::Type::INTEGER) ? left.intValue : left.floatValue;
        float rightVal = (right.type == RuntimeValue::Type::INTEGER) ? right.intValue : right.floatValue;
        return RuntimeValue(leftVal != rightVal);
    }
    else if (node->operador == ">") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue > right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT && right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(left.floatValue > right.floatValue);
        float leftVal = (left.type == RuntimeValue::Type::INTEGER) ? left.intValue : left.floatValue;
        float rightVal = (right.type == RuntimeValue::Type::INTEGER) ? right.intValue : right.floatValue;
        return RuntimeValue(leftVal > rightVal);
    }
    else if (node->operador == "<") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue < right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT && right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(left.floatValue < right.floatValue);
        float leftVal = (left.type == RuntimeValue::Type::INTEGER) ? left.intValue : left.floatValue;
        float rightVal = (right.type == RuntimeValue::Type::INTEGER) ? right.intValue : right.floatValue;
        return RuntimeValue(leftVal < rightVal);
    }
    else if (node->operador == ">=") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue >= right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT && right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(left.floatValue >= right.floatValue);
        float leftVal = (left.type == RuntimeValue::Type::INTEGER) ? left.intValue : left.floatValue;
        float rightVal = (right.type == RuntimeValue::Type::INTEGER) ? right.intValue : right.floatValue;
        return RuntimeValue(leftVal >= rightVal);
    }
    else if (node->operador == "<=") {
        if (left.type == RuntimeValue::Type::INTEGER && right.type == RuntimeValue::Type::INTEGER)
            return RuntimeValue(left.intValue <= right.intValue);
        if (left.type == RuntimeValue::Type::FLOAT && right.type == RuntimeValue::Type::FLOAT)
            return RuntimeValue(left.floatValue <= right.floatValue);
        float leftVal = (left.type == RuntimeValue::Type::INTEGER) ? left.intValue : left.floatValue;
        float rightVal = (right.type == RuntimeValue::Type::INTEGER) ? right.intValue : right.floatValue;
        return RuntimeValue(leftVal <= rightVal);
    }
    else if (node->operador == "!") {
        // Operador de negación lógica
        if (left.type == RuntimeValue::Type::BOOLEAN)
            return RuntimeValue(!left.boolValue);
        // Si no es booleano, convertir a booleano
        return RuntimeValue(!(left.type != RuntimeValue::Type::NULL_VALUE));
    }

    throw std::runtime_error("Operador no soportado: " + node->operador);
}

RuntimeValue Interpreter::evaluateLiteral(LiteralNode* node) {
    // Intenta convertir a entero
    try {
        return RuntimeValue(std::stoi(node->valor));
    } catch (...) {}

    // Intenta convertir a float
    try {
        return RuntimeValue(std::stof(node->valor));
    } catch (...) {}

    // Si no es número, devuelve como string
    return RuntimeValue(node->valor);
}

RuntimeValue Interpreter::evaluateIdentificador(IdentificadorNode* node) {
    auto* valor = globalEnv->lookup(node->nombre);
    if (!valor) {
        throw std::runtime_error("Variable no definida: " + node->nombre);
    }
    return *valor;
}

RuntimeValue Interpreter::evaluateControl(ControlNode* node) {
    if (node->tipo == "if") {
        RuntimeValue condicion = evaluate(node->condicion.get());
        if (condicion.boolValue) {
            // Ejecutar el cuerpo del if
            for (const auto& sentencia : node->cuerpo) {
                evaluate(sentencia.get());
                if (isReturning) return returnValue;
            }
        } 
        else if (node->elseCuerpo) {
            // Si hay un else o elif, ejecutarlo
            return evaluate(node->elseCuerpo.get());
        }
    }
    else if (node->tipo == "else") {
        // Ejecutar directamente el cuerpo del else
        for (const auto& sentencia : node->cuerpo) {
            evaluate(sentencia.get());
            if (isReturning) return returnValue;
        }
    }
    else if (node->tipo == "while") {
        while (evaluate(node->condicion.get()).boolValue) {
            for (const auto& sentencia : node->cuerpo) {
                evaluate(sentencia.get());
                if (isReturning) return returnValue;
            }
        }
    }
    else if (node->tipo == "for") {
        // El for necesita: inicialización, condición, incremento
        auto forNode = static_cast<ControlNode*>(node);
        
        // Ejecutar inicialización si existe
        if (!forNode->cuerpo.empty()) {
            evaluate(forNode->cuerpo[0].get());
        }

        // Evaluar condición y ejecutar cuerpo
        while (evaluate(forNode->condicion.get()).boolValue) {
            // Ejecutar el cuerpo del for
            for (size_t i = 2; i < forNode->cuerpo.size(); i++) {
                evaluate(forNode->cuerpo[i].get());
                if (isReturning) return returnValue;
            }

            // Ejecutar el incremento
            if (forNode->cuerpo.size() > 1) {
                evaluate(forNode->cuerpo[1].get());
            }
        }
    }

    return RuntimeValue(); // Retorna null para estructuras de control
}

RuntimeValue Interpreter::evaluateImpresion(ImpresionNode* node) {
    for (const auto& arg : node->argumentos) {
        RuntimeValue valor = evaluate(arg.get());
        std::cout << valor.toString();
    }
    std::cout << std::endl;
    return RuntimeValue();
}

RuntimeValue Interpreter::evaluateLectura(LecturaNode* node) {
    std::string input;
    std::getline(std::cin, input);
    
    // Obtener la variable para ver su tipo
    auto* var = globalEnv->lookup(node->nombre);
    if (!var) {
        throw std::runtime_error("Variable no declarada: " + node->nombre);
    }

    // Convertir según el tipo de la variable
    RuntimeValue valor;
    try {
        switch (var->type) {
            case RuntimeValue::Type::INTEGER:
                valor = RuntimeValue(std::stoi(input));
                break;
            case RuntimeValue::Type::FLOAT:
                valor = RuntimeValue(std::stof(input));
                break;
            case RuntimeValue::Type::BOOLEAN:
                valor = RuntimeValue(input == "true" || input == "1");
                break;
            default:
                valor = RuntimeValue(input); // String por defecto
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al convertir entrada: '" + input + 
            "' al tipo requerido. " + e.what());
    }

    *var = valor;
    return valor;
}

RuntimeValue Interpreter::evaluateReturn(ReturnNode* node) {
    returnValue = evaluate(node->valor.get());
    isReturning = true;
    return returnValue;
}

RuntimeValue Interpreter::evaluateFuncion(FuncionNode* node) {
    auto func = std::make_shared<Function>(
        node->parametros,
        std::unique_ptr<ASTNode>(node->cuerpo.release()),
        globalEnv  // Captura el ambiente actual como closure
    );
    globalEnv->defineFunction(node->nombre, func);
    return RuntimeValue();
}

RuntimeValue Interpreter::evaluateLlamadaFuncion(LlamadaFuncionNode* node) {
    auto func = globalEnv->lookupFunction(node->nombre);
    if (!func) {
        throw std::runtime_error("Función no definida: " + node->nombre);
    }

    // Crear nuevo ambiente para la función
    auto functionEnv = std::make_shared<Environment>(func->closure);
    
    // Evaluar argumentos y asignarlos a parámetros
    if (node->argumentos.size() != func->parametros.size()) {
        throw std::runtime_error("Número incorrecto de argumentos para: " + node->nombre);
    }

    for (size_t i = 0; i < node->argumentos.size(); i++) {
        RuntimeValue argValue = evaluate(node->argumentos[i].get());
        functionEnv->define(func->parametros[i], argValue);
    }

    // Guardar ambiente actual y cambiar al nuevo
    auto previousEnv = globalEnv;
    globalEnv = functionEnv;

    // Ejecutar el cuerpo de la función
    RuntimeValue result = evaluate(func->cuerpo.get());

    // Restaurar ambiente
    globalEnv = previousEnv;

    // Si hubo un return, limpiar la bandera y devolver el valor
    if (isReturning) {
        isReturning = false;
        return returnValue;
    }

    return result;
}

std::string RuntimeValue::toString() const {
    std::ostringstream oss;
    switch (type) {
        case Type::INTEGER:
            oss << intValue;
            break;
        case Type::FLOAT:
            oss << floatValue;
            break;
        case Type::STRING:
            oss << stringValue;
            break;
        case Type::BOOLEAN:
            oss << (boolValue ? "true" : "false");
            break;
        case Type::NULL_VALUE:
            oss << "null";
            break;
    }
    return oss.str();
}

void Interpreter::execute(ASTNode* root) {
    if (root) {
        evaluate(root);
    }
}