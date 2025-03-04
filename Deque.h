#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

 struct Node2 {
     int data;
     Node2 *next;
     Node2 *prev;

     Node2(int value) : data(value), next(nullptr), prev(nullptr) {}
 };



struct Deque {
    Node2 *front;
    Node2 *rear;

    Deque(){
        front = nullptr;
        rear = nullptr;
    }
};

int peekFront(const Deque &dq);

int peekRear(const Deque &dq);

bool isEmpty(Deque &dq);

void insertFront(Deque &dq, int value);

void insertRaer(Deque &dq, int value);

void printDeque(Deque &dq);

void delAtRearDeque(Deque &dq);

void delAtFrontDeque(Deque &dq);

#endif //DEQUE_H
