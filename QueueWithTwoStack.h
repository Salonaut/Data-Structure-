#ifndef QUEUEWITHTWOSTACK_H
#define QUEUEWITHTWOSTACK_H

const int SIZE = 10;

#include <iostream>

using namespace std;



void enQueue(int stack1[], int x, int &top);

void printQueue(int stack[], int top);

int deQueue(int stack1[], int stack2[], int &top1,int &top2);

int front(int stack1[], int stack2[], int &top1,int &top2);

#endif //QUEUEWITHTWOSTACK_H
