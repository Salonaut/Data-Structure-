#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <algorithm>
#include <ctime>

struct Node1 {
    int data;
    Node1* next;
    Node1* prev;

    Node1 (int value) : data(value), next(nullptr), prev(nullptr) {}
};


void add_in_end(Node1*&head, Node1*&tail, int value); // done

void doubleListPrint(Node1*head); // done

void addAtFront(Node1 *&head, Node1 *& tail, int value); // done

void addAtPosition(Node1 *&head, Node1 *& tail, int value, int pos); // done

void deleteAtPosition(Node1 *& head, Node1 *& tail, int pos); // done

bool isEmpty(Node1*head);

Node1* sortDoubleList(Node1*head);

Node1* copyDoubleLinkedList(Node1 *head);

Node1* recursionCopyDoubleLinkedList(Node1 *head,Node1 *tail);


Node1* createDoubleLinkedList(int N);

Node1* createDoubleLinkedListRandom(int N, int range4rand);

int sizeOfDoubleLinkedList(Node1 *head);

#endif