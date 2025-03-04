#include "GeneralTree.h"

void addSubTree(Node4*parent, Node4*subtree) {
    if (parent == nullptr && subtree == nullptr) return;

    if (parent->child == nullptr) {
        parent->child = subtree;
    }else {
        Node4* temp = parent->child;

        while (temp != nullptr) {
            temp = temp->sibling;
        }

        temp->sibling = subtree;
    }

}


void delSubTree(Node4* parent, int value);
