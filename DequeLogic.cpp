#include "Deque.h"

int peekFront(const Deque &dq) {
    if (dq.front == nullptr) return -1;
    return dq.front->data;
}

int peekRear(const Deque &dq) {
    if (dq.rear == nullptr) return -1;
    return dq.rear->data;
}

bool isEmpty(Deque &dq) {
    return dq.front == nullptr;
}

void insertFront(Deque &dq, int value) {
    Node2*newNode = new Node2(value);
    if (isEmpty(dq)) {
        dq.front = dq.rear = newNode;
    }else {
        dq.front->prev = newNode;
        newNode->next = dq.front;
        dq.front = newNode;
    }
}

void insertRaer(Deque &dq, int value) {
    Node2*newNode = new Node2(value);

    if (isEmpty(dq)) {
        dq.front = dq.rear = newNode;
    }else {
        dq.rear->next = newNode;
        newNode->prev = dq.rear;
        dq.rear = newNode;
    }
}

void printDeque(Deque &dq) {
    if (isEmpty(dq)) {
        std::cout << "Deque is empty" << '\n';
    }
    Deque temp = dq;
    while (temp.front != temp.rear->next) {
        std::cout << temp.front->data << " ";
        temp.front = temp.front->next;
    }

    std::cout << '\n';
}


void delAtRearDeque(Deque &dq) {
    if (isEmpty(dq)) return;

    Node2 *temp = dq.rear;

    if (dq.front == dq.rear) {
        dq.front = dq.rear = nullptr;
        delete temp;
        return;
     }
    else {
         dq.rear = dq.rear->prev;
         dq.rear->next = nullptr;
         delete temp;
         return;
     }

}

void delAtFrontDeque(Deque &dq) {
    if (dq.front == nullptr) return;
    if (dq.front->next == nullptr) {
        dq.front = dq.rear = nullptr;
        return;
    }else {
        Node2* temp = dq.front;
        dq.front = dq.front->next;
        dq.front->prev = nullptr;
        delete temp;
    }
}
