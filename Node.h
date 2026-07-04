//
// Created by vlaso on 24.06.2026.
//

#ifndef UNTITLED_DEFAULTNODE_H
#define UNTITLED_DEFAULTNODE_H
#include <memory>
#include <string>
#include <vector>

enum class OpType {
    // арифметика
    ADD, SUB, MUL, DIV,
    // сравнения
    GT, LT, EQ,
    // логика
    AND, OR, NOT,
    // структуры
    IF, SEQ, ASSIGN, RETURN,
    // листья
    VAR, CONST
};

enum class Quantifier {
    ONE,
    OPT,
    UNL,
    UNL_OPT
};
struct Slot {
    OpType op;
    Quantifier q = Quantifier::ONE;
};

std::vector<Slot *> get_approved(OpType op) {
    s

};

class Node {
public:
    Node();

    std::vector<std::unique_ptr<Node>> children;
    float data;

};



#endif //UNTITLED_DEFAULTNODE_H
