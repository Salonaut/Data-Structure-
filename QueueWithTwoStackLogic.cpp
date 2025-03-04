#include "QueueWithTwoStack.h"



void enQueue(int stack1[], int x, int &top) {
    if (top == SIZE - 1) {
        cout << "The stack is full" <<endl;
        return;
    }
    stack1[++top] = x;
}


void printQueue(int stack[], int top) {
    for (int i = 0; i <=top ; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;

}


int deQueue(int stack1[], int stack2[], int &top1,int &top2) {
    if (top1 == -1 && top2 == -1) {
        cout << " The stack is empty!" << endl;
        return -1;
    }
    if (top2 == -1) {
        while (top1 >= 0){
            stack2[++top2] = stack1[top1--];
        }
    }


    return stack2[--top2];
}


int front(int stack1[], int stack2[], int &top1,int &top2) {
    if (top1 == -1 && top2 == -1) {
        cout << "The queue is empty" << endl;
    }
    if (top2 == -1) {
        while (top1 >= 0) {
            stack2[++top2] = stack1[top1--];
        }
    }

    return stack2[top2];
}



