cmake_minimum_required(VERSION 3.30)
project(Data_Structes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Data_Structes main.cpp
        LinkedList.h
        LinkedListLogic.cpp
        DoubleLinkedList.h
        DoubleListLogic.cpp
        QueueWithTwoStack.h
        QueueWithTwoStackLogic.cpp
        Deque.h
        DequeLogic.cpp
        BinaryTree.h
        BinaryTreeLogic.cpp
        GeneralTree.h
        GeneralTreeLogic.cpp
)
