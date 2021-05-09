#include <iostream>

using namespace std;

struct node {
    string data;
    int priority;
    node *next;
};
typedef node* pointerQ;

struct queue {
    pointerQ head;
    pointerQ tail;
};
queue q;

void createQueue(queue& q) {
    q.head = nullptr;
    q.tail = nullptr;
}

void createElementQ(pointerQ& newElement, string data, int priority) {
    newElement = new node;
    newElement->data = data;
    newElement->priority = priority;
    newElement->next = nullptr;
}

string front(queue q) {
    return q.head->data;
}

bool isEmpty(queue q) {
    if (q.head == nullptr && q.tail == nullptr) {
        return true;
    } else {
        return false;
    }
}

void enQueue(queue& q, pointerQ newElement) {
    pointerQ pPrev = nullptr;
    pointerQ pHelp = q.head;
    if (isEmpty(q)) {
        q.head = newElement;
        q.tail = newElement;
    } else {
        while (newElement->priority >= pHelp->priority) {
            if (pHelp->next == nullptr) {
                break;
            }
            pPrev = pHelp;
            pHelp = pHelp->next;
        }
        if (pHelp == q.head && newElement->priority < pHelp->priority) {
            newElement->next = pHelp;
            q.head = newElement;
        } else if (pHelp == q.tail && newElement->priority > pHelp->priority) {
            pHelp->next = newElement;
            q.tail = newElement;
        } else {
            pPrev->next = newElement;
            newElement->next = pHelp;
        }
    }
}

string dequeue(queue& q, pointerQ delElement) {
    if (isEmpty(q)) {
        delElement = nullptr;
    } else if (q.head->next == nullptr) {
        delElement = q.head;
        q.head = nullptr;
        q.tail = nullptr;
    } else {
        delElement = q.head;
        q.head = q.head->next;
        delElement->next = nullptr;
    }
    return delElement->data;
}

string headPenting(queue q) {
    string kepentingan;
    if (q.head->priority == 1) {
        kepentingan = "Medis/Kesehatan";
    } else if (q.head->priority == 2) {
        kepentingan = "Militer/Polisi";
    } else if (q.head->priority == 3) {
        kepentingan = "Pemerintahan/Pejabat";
    } else if (q.head->priority == 4) {
        kepentingan = "Bisnis/Pedagang";
    } else if (q.head->priority == 5) {
        kepentingan = "Warga/Turis";
    }
    return kepentingan;
}