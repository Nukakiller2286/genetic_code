cmake_minimum_required(VERSION 4.2)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Node.cpp
        Node.h
        Sequence.cpp
        Sequence.h
        OperationIf.cpp
        OperationIf.h
        Condition.cpp
        Condition.h
        Math.cpp
        Math.h
        Term.cpp
        Term.h
        Factor.cpp
        Factor.h
        Variable.cpp
        Variable.h
        Constant.cpp
        Constant.h
        Return.cpp
        Return.h
        Assigment.cpp
        Assigment.h)
