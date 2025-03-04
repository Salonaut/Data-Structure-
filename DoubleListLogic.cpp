#include "DoubleLinkedList.h"


void add_in_end(Node1*&head, Node1*&tail, int value) {
    Node1 *newNode = new Node1(value);
    if (head == nullptr) {
        head=tail=newNode;
        return;
    }else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void doubleListPrint(Node1*head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


void addAtFront(Node1 *&head, Node1 *& tail, int value) {
    Node1 *newNode = new Node1(value);
    if (head == nullptr) {
        head = tail = nullptr;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


void deleteAtPosition(Node1 *& head, Node1 *& tail, int pos) {
    if (head == nullptr) return;
    if (pos == 1) {
        Node1*temp = head;
        head=head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        return;
    }

    Node1 *temp = head;

    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp  = temp->next;
    }

    if (temp->next == nullptr) return;



    Node1 *del = temp->next;
    temp->next = del->next;

    if (del->next != nullptr) {
        del->next->prev = temp;
    }else {
        tail = temp;
    }


}

void addAtPosition(Node1 *&head, Node1 *& tail, int value, int pos) {
    if (head == nullptr) {
        std::cout << "The list is empty" << '\n';
        return;
    }
    if (pos == 1) {
        Node1 *newNode = new Node1(value);
        newNode->next = head;
        if (head->next == nullptr) {
            tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node1*temp = head;

    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        std::cout << "Out of range" << '\n';
        return;
    }

    Node1* newNode = new Node1(value);

    Node1 *noden = temp->next; // temp -> ourEl -> noden
    temp->next = newNode; // temp <-> newNode <-> noden
    newNode->prev = temp;
    newNode->next = noden;
    noden->prev = newNode;
}


Node1* sortDoubleList(Node1*head) {

    /*Node1 *temp;*/
    bool isSorted = false;

    do {
        Node1 *temp = head;

        isSorted = false;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data > temp->next->data) {
                auto change = temp->data;
                temp->data = temp->next->data;
                temp->next->data = change;
                isSorted = true;
            }

            temp = temp->next;
        }

    }while (isSorted);

    return head;
}

Node1* recursionCopyDoubleLinkedList(Node1 *head,Node1 *tail) {
    if (head==nullptr) {
        return nullptr;
    }
    Node1*newNode = new Node1(head->data);
    newNode->next = recursionCopyDoubleLinkedList(head->next, tail);

    return newNode;
}


Node1* copyDoubleLinkedList(Node1 *head) {
    if (head == nullptr) return nullptr;

    Node1*newHead = new Node1(head->data);

    Node1*temp = head->next;
    Node1*newTail = newHead;


    while (temp != nullptr) {
        Node1*newNode = new Node1(temp->data);
        newNode->prev = newTail;
        newTail->next = newNode;
        newTail = newNode;
        temp = temp->next;
    }


    return newHead;
}

bool isEmpty(Node1*head) {
    return head == nullptr;
}

Node1* createDoubleLinkedList(int N) {
    int value;
    std::cout << "Enter value: ";
    std::cin >> value;

    Node1* newHead = new Node1(value);

    Node1*newTail = newHead;

    while (N != 1) {
        std::cout << "Enter value: ";
        std::cin >> value;
        Node1* newNode = new Node1(value);
        newTail->next = newNode;
        newNode->prev = newTail;
        newTail = newNode;
        N--;
    }

    return newHead;
}


Node1* createDoubleLinkedListRandom(int N, int range4rand) {
    srand(static_cast<unsigned>(time(NULL)));

    int value = rand() & range4rand;;


    Node1 *newHead = new Node1(value);
    Node1 *newTail = newHead;
    while (N != 1) {
        value = rand() & range4rand;
        Node1* newNode = new Node1(value);
        newTail->next = newNode;
        newNode->prev = newTail;
        newTail = newNode;
        N--;
    }

    return newHead;
}


int sizeOfDoubleLinkedList(Node1 *head) {
    if (head == nullptr) return 0;

    int size = 0;

    while (head) {
        size++;
        head = head->next;
    }

    return size;
}


