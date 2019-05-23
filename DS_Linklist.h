#ifndef DS_LINKLIST_H
#define DS_LINKLIST_H
#include <iostream>
#include "DS_Node.h"
using namespace std;

template <class T> class DS_Linklist {
private:
    DS_Node<T>* head;
    DS_Node<T>* tail;
    DS_Node<T>* iter;
    int size;
public:
    DS_Linklist();
    DS_Linklist(T val);
    DS_Linklist(const DS_Linklist<T>&);
    DS_Linklist<T> operator=(const DS_Linklist<T>);
    ~DS_Linklist();
    void insert_back(const T val);
    void pop_back();
    int find(T val);
    void display();
    T& operator[](int);

    //iter management
    void resetIter();
    bool isIterValid();
    T& getIter();
    void stepIter();

    DS_Node<T>*& get_head();
    DS_Node<T>*& get_tail();

    //Testing functions:
    void is_null();
};

template <class T>
DS_Linklist<T>::DS_Linklist() {
    head = nullptr;
    tail = nullptr;
    iter = nullptr;
    size = 0;
}

template <class T>
DS_Linklist<T>::DS_Linklist(const DS_Linklist<T>& copy_list) {
    head = nullptr;
    tail = nullptr;
    iter = nullptr;
    size = 0;

    DS_Node<T>* curr = copy_list.head;
    while(curr != nullptr) {
        insert_back(curr ->data);
        curr = curr ->next;
    }
}

template <class T>
DS_Linklist<T> DS_Linklist<T>::operator=(DS_Linklist<T> copy_list) {
    head = nullptr;
    tail = nullptr;
    iter = nullptr;
    size = 0;

    DS_Node<T>* curr = copy_list.head;
    while(curr != nullptr) {
        insert_back(curr -> data);
        curr = curr ->next;
    }
    return *this;
}

template <class T>
DS_Linklist<T>::~DS_Linklist() {
    DS_Node<T>* curr = head;
    while(curr != nullptr) {
        DS_Node<T>* temp = curr;
        curr = curr -> next;
        delete temp;
    }//end while
}

template <class T>
DS_Linklist<T>::DS_Linklist(T val) {
    head = tail = new DS_Node<T>(val);
    iter = head;
    size = 1;
}

template <class T>
void DS_Linklist<T>::insert_back(const T val) {
    DS_Node<T>* temp = new DS_Node<T>(val);

    if(tail != nullptr) {
        tail ->next = temp;
        temp -> prev = tail; //tail -> next -> prev = tail;
        tail = temp;
    } else {
        head = temp;
        tail = temp;
        iter = head;
    }
    size++;
}

template <class T>
void DS_Linklist<T>::pop_back() {

    if(head == nullptr || tail == nullptr) {
        return;
    } else if(head == tail) {
        DS_Node<T>* temp = head;
        head = head -> next;
        delete temp;
    } else {
        DS_Node<T>* temp = tail;
        temp -> prev -> next = temp -> next;
        tail = temp -> prev;
        delete temp;
    }//end else
}

template <class T>
int DS_Linklist<T>::find(T val) {
    DS_Node<T>* curr = head;
    int pos = 0;
    while(curr != nullptr) {
        if(curr->data == val)
            return pos;
        curr = curr->next;
        pos++;
    }
    if(curr == nullptr) 
        return -1;
}

template <class T>
void DS_Linklist<T>::display() {
    DS_Node<T>* curr = head;
    while(curr != nullptr) {
        cout << curr -> data << endl;
        curr = curr -> next;
    }//end while
}

template <class T>
T& DS_Linklist<T>::operator[](int position) {
    DS_Node<T>* curr = head;
    while(curr != nullptr && position > 0) {
        curr = curr -> next;
        position--;
    }
    if(curr != nullptr)
        return curr -> data;
    if(curr == nullptr) 
        cout << "Index out of bounds" << endl;
}

//Iter management
template <class T>
void DS_Linklist<T>::resetIter() {
    iter = head;
}

template <class T>
bool DS_Linklist<T>::isIterValid() {
    if(iter == nullptr)     return false;
    else                    return true;
}

template <class T>
void DS_Linklist<T>::stepIter() {
    iter = iter -> next;
}

template <class T>
T& DS_Linklist<T>::getIter() {
    return iter -> data;
}

template <class T>
DS_Node<T>*& DS_Linklist<T>::get_head() {
    return head;
}

template <class T>
DS_Node<T>*& DS_Linklist<T>::get_tail() {
    return tail;
}

//Testing functions

template <class T>
void DS_Linklist<T>::is_null() {
    DS_Node<T>* curr = head;
    while(true) {
        if(curr == nullptr) {
            cout << "Null" << endl;
            return;
        } else {
            curr = curr -> next;
            cout << "not null" << endl;
        }
    }//end while
}

#endif
