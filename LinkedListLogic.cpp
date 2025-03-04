#include "LinkedList.h"

void push_b(Node *& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    }else {
        Node*temp = head;
        while (head->next != nullptr) {
            head = head->next;
        }
        head->next = newNode;
    }
}

void pop_b(Node *&head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node*temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

}

void push_top(Node *& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void pop_top(Node *&head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node*temp = head;
    head = head->next;
    delete temp;
}

void printList(Node *head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void delByPos(Node *& head, int pos) {
    if (head == nullptr) {
        return;
    }
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        std::cout << "Out of range" << std::endl;
    }

        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;

}

void addByPos(Node *& head, int pos,int value) {
    Node* newNode = new Node(value);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node*temp = head;

    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp) {
        std::cout << "Out of range" << std::endl;
    }

    newNode->next= temp->next;
    temp->next = newNode;

}

bool isEmptyList(Node*head) {
    return head == nullptr;
}

void sortLinkedList(Node *& head) {
    if (head == nullptr) return;
    bool isSwapped;
    do{
        isSwapped = false;
        Node *temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data > temp->next->data) {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                isSwapped = true;
            }
        }
    }while (isSwapped);
}


Node* copyRecursionLinkedList(Node*head) {
    if (head == nullptr) return nullptr;
    Node * newNode = new Node(head->data);

    newNode->next = copyRecursionLinkedList(head->next);

    return newNode;
}

Node* copyList(Node* head) {
    if (head == nullptr) return nullptr;

    Node* newHead = new Node(head->data);

    Node*originalNode = head->next;
    Node*currNode = newHead;


    while (originalNode) {
        Node*newNode = new Node(originalNode->data);

        currNode->next = newNode;
        currNode = newNode;
        originalNode = originalNode->next;
    }

    return newHead;

}


Node* reverseLinkedList(Node*head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    Node * curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}