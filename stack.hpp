#include <iostream>

using namespace std;

struct element {
    string hari;
    element *next;
};

typedef element* pointerS;
typedef pointerS stack;
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

void createElementS(pointerS& newElement, string hari) {
    newElement = new element;
    newElement->hari = hari;
    newElement->next = nullptr;
}

void push(stack& top, pointerS newElement) {
    if(isEmpty(top)) {
        top = newElement;
    } else {
        newElement->next = top;
        top = newElement;
    }
}

string pop(stack& top, pointerS& pDel) {
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
    return pDel->hari;
}

void transversal(stack top) {
    pointerS pHelp = top;
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