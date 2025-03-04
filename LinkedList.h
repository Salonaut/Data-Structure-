#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


void push_b(Node *& head, int value);
void pop_b(Node *&head);

void push_top(Node *& head, int value);
void pop_top(Node *&head);

void printList(Node *head);

void delByPos(Node *& head, int pos);
void addByPos(Node *& head, int pos, int value);

void sortLinkedList(Node *& head);

bool isEmptyList(Node*head); // done


Node* copyRecursionLinkedList(Node*head);

Node* reverseLinkedList(Node*head);



#endif //LINKEDLIST_H
