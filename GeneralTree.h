#ifndef GENERALTREE_H
#define GENERALTREE_H

#include <iostream>

struct Node4 {
    int data;
    Node4* child;
    Node4*  sibling;

    Node4(int value) {
        data = value;
        child = nullptr;
        sibling = nullptr;
    }
};


void addSubTree(Node4*parent, Node4*subtree);

void delSubTree(Node4* parent, int value);

void printGeneralTree(Node4*parent);

bool searchGeneralTree(Node4* parent, int value);

int height(Node4* parent);

int countGeneralRoot(Node4* parent);

#endif //GENERALTREE_H
