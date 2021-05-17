#include <iostream>

using namespace std;

struct node {
    string nama;
    string prioritas;
    string kode;
    int jumlah;
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

void createElementQ(pointerQ& newElement, string nama, string prioritas, string kode, int jumlah) {
    newElement = new node;
    newElement->nama = nama;
    newElement->prioritas = prioritas;
    newElement->kode = kode;
    newElement->jumlah = jumlah;
    newElement->next = nullptr;
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
        while (newElement->prioritas >= pHelp->prioritas) {
            if (pHelp->next == nullptr) {
                break;
            }
            pPrev = pHelp;
            pHelp = pHelp->next;
        }
        if (pHelp == q.head && newElement->prioritas < pHelp->prioritas) {
            newElement->next = pHelp;
            q.head = newElement;
        } else if (pHelp == q.tail && newElement->prioritas >= pHelp->prioritas) {
            pHelp->next = newElement;
            q.tail = newElement;
        } else {
            pPrev->next = newElement;
            newElement->next = pHelp;
        }
    }
}

void deQueue(queue& q, pointerQ delElement) {
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
}

string headKepentingan(pointerQ pHelpQ) {
    string kepentingan;
    if (pHelpQ->prioritas == "1") {
        kepentingan = "Medis/Kesehatan";
    } else if (pHelpQ->prioritas == "2") {
        kepentingan = "Militer/Polisi";
    } else if (pHelpQ->prioritas == "3") {
        kepentingan = "Pemerintahan/Pejabat";
    } else if (pHelpQ->prioritas == "4") {
        kepentingan = "Bisnis/Pedagang";
    } else if (pHelpQ->prioritas == "5") {
        kepentingan = "Warga/Turis";
    }
    return kepentingan;
}

string headNama(pointerQ pHelpQ) {
    return pHelpQ->nama;
}

string headKode(pointerQ pHelpQ) {
    return pHelpQ->kode;
}

int headJumlah(pointerQ pHelpQ) {
    return pHelpQ->jumlah;
}