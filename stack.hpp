#include <iostream>

using namespace std;

struct element {
    string hari;
    element *next;
};

typedef element* pointerL;
typedef pointerL stack;
stack top;

string peek(stack top) {
    return top->hari;
}

bool isEmpty(stack top) {
    if (top == nullptr) {
        return true;
    } else {
        return false;
    }
}

void createStack(stack& top) {
    top = nullptr;
}

void createElement(pointerL& newElement, string hari) {
    newElement = new element;
    newElement->hari = hari;
    newElement->next = nullptr;
}

void push(stack& top, pointerL newElement) {
    if(isEmpty(top)) {
        top = newElement;
    } else {
        newElement->next = top;
        top = newElement;
    }
}

void pop(stack& top, pointerL& pDel) {
    if (isEmpty(top)) {
        pDel = nullptr;
    } else if (top->next == nullptr) {
        pDel = top;
        top = nullptr;
    } else {
        pDel = top;
        top = top->next;
        pDel->next = nullptr;
    }
}

void transversal(stack top) {
    pointerL pHelp = top;
    if (isEmpty(top)) {
        std::cout << "Stack is empty.\n";
    } else {
        cout << "Top\n^\n|\n";
        do {
            cout << pHelp->hari << "\n";
            pHelp = pHelp->next;
        } while (pHelp != nullptr);
    }
}