//
// Created by vlaso on 24.06.2026.
//

#include "Node.h"

bool Node::check() {
    std::vector<std::unique_ptr<Slot>> approved=get_approved(type,spec);
    unsigned int child_i=0;
    unsigned int app_i=0;

    while (app_i<approved.size()) {
        switch (approved[app_i]->quantifier) {
            case Quantifier::ONE: {
                if (not(children[child_i]->spec==approved[app_i]->spec && children[child_i]->type==approved[app_i]->type)){
                    return false;}
                ++child_i;
                break;
            case Quantifier::ONE_OPT:
            ++child_i;
            break;
            }
            case Quantifier::UNL:{
                unsigned int c=0;
                while (children[child_i]->spec==approved[app_i]->spec && children[child_i]->type==approved[app_i]->type) {
                    ++child_i;
                    ++c;
                    }
                if (c==0) {
                    return false;
                }
                break;
            }
            case Quantifier::UNL_OPT: {
                while (children[child_i]->spec==approved[app_i]->spec && children[child_i]->type==approved[app_i]->type) {
                    ++child_i;
                }
                break;
            }
            case Quantifier::UNL_OPT_START: {
                unsigned int size_app_i;
                for (size_app_i=1 ; app_i+size_app_i<approved.size(); ++size_app_i) {
                    if (approved[app_i+size_app_i]->quantifier==Quantifier::UNL_OPT_END) {
                        break;
                    }
                }
                unsigned int end_app_i=app_i+size_app_i;
                child_i+=size_app_i;
                size_app_i+=1;
                while (children[child_i]->spec==approved[end_app_i]->spec && children[child_i]->type==approved[end_app_i]->type) {
                    for (int i = 0; i <= size_app_i; ++i) {
                        if (not(children[child_i-i]->spec==approved[end_app_i-i]->spec && children[child_i-i]->type==approved[end_app_i-i]->type)){
                            return false;}
                    }
                    child_i+=size_app_i;
                }
                app_i=end_app_i;
                break;
            }
            case Quantifier::ONLY_ONE: {
                unsigned int size_app_i;
                for (size_app_i=1 ; app_i+size_app_i<approved.size(); ++size_app_i) {
                    if (approved[app_i+size_app_i]->quantifier==Quantifier::ONLY_ONE) {
                        break;
                    }
                }
                int c=0;
                for (unsigned int i = 0; i <= size_app_i; ++i) {
                    if ((children[child_i-i]->spec==approved[app_i-i]->spec && children[child_i-i]->type==approved[app_i-i]->type)) {
                        ++c;
                    }
                }
                if (c!=1) {
                    return false;
                }

                ++child_i;
                app_i+=size_app_i;
                break;
            }

            ++app_i;

        }
    }
    if (children.empty()) {
        return true;
    }
    for (const auto& chld : children) {
        return chld->check();
    }
}

std::vector<float> Node::run(std::unordered_map<int,float>& input) {
    switch (type) {
        case OpType::SEQ: {
            break;
        }
        case OpType::OPER: {
            switch (spec) {
                case Spec::IF: {
                    break;
                }
                case Spec::WHILE: {
                    break;
                }
                case Spec::RETURN: {
                    break;
                }
                case Spec::ASSIGN: {
                    break;
                }


            }
            break;
        }
        case OpType::COND: {
            break;
        }
        case OpType::MATH: {
            break;
        }
        case OpType::TERM: {
            break;
        }
        case OpType::FACTOR: {
            break;
        }
        case OpType::FLT: {
            break;
        }
        case OpType::ADD: {
            break;
        }
        case OpType::MULT: {
            break;
        }
        case OpType::COMP: {
            break;
        }
    }
}
