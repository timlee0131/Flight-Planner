#ifndef DS_ADJLIST_H
#define DS_ADJLIST_H


#include "DS_String.h"
#include "DS_Node.h"
#include "DS_AdjNode.h"
#include "DS_Linklist.h"

#include <iostream>
using namespace std;

template <class T> class DS_AdjList {
private:
    DS_AdjNode<T>* head;
    DS_AdjNode<T>* tail;
    int size;
public:
    DS_AdjList();
    ~DS_AdjList();
    void insert_back(const T);
    void display();

    DS_AdjNode<T>*& get_head();
    DS_AdjNode<T>*& get_tail();

    DS_AdjNode<T>* find(T val);
};

template <class T>
DS_AdjList<T>::DS_AdjList() {
    head = tail = nullptr;
    size = 0;
}

template <class T>
DS_AdjList<T>::~DS_AdjList() {
    DS_AdjNode<T>* curr = head;
    while(curr != nullptr) {
        DS_AdjNode<T>* temp = curr;
        curr = curr -> next;
        delete temp;
    }//end while
}

//template <class T>
//void DS_AdjList<T>::insert(const T val, int pos) {
//    DS_AdjNode<T>* curr = head;
//    int count = 0;
//    while(count++ < pos && curr != nullptr) {
//        curr = curr -> next;
//    }
//    curr ->insert_AdjNode(val);
//}

template <class T>
void DS_AdjList<T>::insert_back(const T val) {
    DS_AdjNode<T>* temp = new DS_AdjNode<T>(val);

    if(tail != nullptr) {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    } else {
        head = temp;
        tail = temp;
    }
    size++;
}

template <class T>
void DS_AdjList<T>::display() {
    DS_AdjNode<T>* curr = head;
    while(curr != nullptr) {
        cout << curr ->data << ", ";

        DS_Node<T>* edge = curr ->get_edges().get_head();
        while(edge != nullptr) {
            cout << edge -> get_data() << " ";
            edge = edge -> get_next();
        }//end while
        cout << endl;

        curr = curr -> next;
    }
}

template <class T>
DS_AdjNode<T>* DS_AdjList<T>::find(T val) {
    DS_AdjNode<T>* curr = head;
    int pos = 0;
    while(curr != nullptr) {
        if(curr -> data == val)
            return curr;
        curr = curr -> next;
        pos++;
    }
    return curr;
}

template <class T>
DS_AdjNode<T>*& DS_AdjList<T>::get_head() {
    return head;
}

template <class T>
DS_AdjNode<T>*& DS_AdjList<T>::get_tail() {
    return tail;
}

#endif // DS_ADJLIST_H
