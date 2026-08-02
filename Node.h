//
// Created by vlaso on 24.06.2026.
//

#ifndef UNTITLED_DEFAULTNODE_H
#define UNTITLED_DEFAULTNODE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum class OpType {
    SEQ, OPER,
    COND, MATH, TERM, FACTOR,
    FLT,
    ADD, MULT, COMP
};

enum class Spec {
    IF, WHILE, RETURN, ASSIGN, NONE, VAR, CONST
};

enum class Quantifier {
    ONE,
    OPT,
    UNL,
    UNL_OPT,
    UNL_OPT_START,
    UNL_OPT_END,
    ONE_OPT
};
struct Slot {
    OpType type;
    Quantifier quantifier = Quantifier::ONE;
    Spec spec = Spec::NONE;
};

inline std::vector<std::unique_ptr<Slot>> get_approved(OpType op, Spec s = Spec::NONE) {
    std::vector<std::unique_ptr<Slot>> v;
    switch (op) {
        case OpType::SEQ: {

            v.push_back(std::make_unique<Slot>(Slot{OpType::OPER, Quantifier::UNL_OPT}));
            return v;
        }
        case OpType::OPER:
        {
            switch (s) {
                case Spec::ASSIGN: {

                        v.push_back(std::make_unique<Slot>(Slot{OpType::FLT, Quantifier::ONE, Spec::VAR}));
                        v.push_back(std::make_unique<Slot>(Slot{OpType::MATH, Quantifier::ONE}));
                        return v;
                }
                    case Spec::IF: {

                        v.push_back(std::make_unique<Slot>(Slot{OpType::COND, Quantifier::ONE}));
                        v.push_back(std::make_unique<Slot>(Slot{OpType::SEQ, Quantifier::ONE}));
                        v.push_back(std::make_unique<Slot>(Slot{OpType::OPER, Quantifier::UNL_OPT, Spec::IF}));
                        v.push_back(std::make_unique<Slot>(Slot{OpType::SEQ, Quantifier::ONE_OPT}));
                        return v;
                }
                    case Spec::WHILE: {

                        v.push_back(std::make_unique<Slot>(Slot{OpType::COND, Quantifier::ONE}));
                        v.push_back(std::make_unique<Slot>(Slot{OpType::SEQ, Quantifier::ONE}));
                        return v;
                }
                    case Spec::RETURN: {

                        v.push_back(std::make_unique<Slot>(Slot{OpType::FLT, Quantifier::UNL, Spec::VAR}));
                        return v;
                }


                default:std::cerr << "ERROR: Unknown specification type." << std::endl; ;
            }
        }
        case OpType::COND:
        {

            v.push_back(std::make_unique<Slot>(Slot{OpType::MATH, Quantifier::ONE}));
            v.push_back(std::make_unique<Slot>(Slot{OpType::COND, Quantifier::ONE}));
            v.push_back(std::make_unique<Slot>(Slot{OpType::MATH, Quantifier::ONE}));
            return v;
        }
        case OpType::MATH:
        {

            v.push_back(std::make_unique<Slot>(Slot{OpType::TERM, Quantifier::ONE}));
            v.push_back(std::make_unique<Slot>(Slot{OpType::ADD, Quantifier::UNL_OPT_START}));
            v.push_back(std::make_unique<Slot>(Slot{OpType::TERM, Quantifier::UNL_OPT_END}));
            return v;
        }
        case OpType::TERM:
        {

            v.push_back(std::make_unique<Slot>(Slot{OpType::FACTOR, Quantifier::ONE}));
            v.push_back(std::make_unique<Slot>(Slot{OpType::MULT, Quantifier::UNL_OPT_START}));
            v.push_back(std::make_unique<Slot>(Slot{OpType::FACTOR, Quantifier::UNL_OPT_END}));
            return v;
        }
        case OpType::FACTOR:
        {

            v.push_back(std::make_unique<Slot>(Slot{OpType::FLT, Quantifier::ONE_OPT}));
            v.push_back(std::make_unique<Slot>(Slot{OpType::MATH, Quantifier::ONE_OPT}));
            return v;
        }
            default: {
            std::cerr << "ERROR: Unknown operation type." << std::endl;
        }
        return v;
    }


};

class Node {
public:
    Node();
    std::vector<float>  evaluate(std::vector<float> input);
    bool check();
    
    OpType type;
    Spec spec;
    std::vector<std::unique_ptr<Node>> children;
    std::string name;

};



#endif //UNTITLED_DEFAULTNODE_H
