#ifndef DS_STACK_H
#define DS_STACK_H
#include "DS_Node.h"
#include "DS_Linklist.h"
using namespace std;

template <class T> class DS_Stack {
private:
    DS_Linklist<T> list;
    int size;
public:
    void push(T);
    void pop();
    T& peek();
    bool isEmpty();
    bool contains(T);
    DS_Linklist<T>& get_list();
};

template <class T>
DS_Linklist<T>& DS_Stack<T>::get_list() {
    return list;
}

template <class T>
void DS_Stack<T>::push(T val) {
    list.insert_back(val);
    size++;
}

template <class T>
void DS_Stack<T>::pop() {
    list.pop_back();
}

template <class T>
T& DS_Stack<T>::peek() {
   DS_Node<T>* temp = list.get_head();
    while(temp ->get_next() != nullptr) {
        temp = temp ->get_next();
    }
    return temp ->get_data();
}

template <class T>
bool DS_Stack<T>::isEmpty() {
    if(list.get_head() == nullptr)
        return true;
    return false;
}

template <class T>
bool DS_Stack<T>::contains(T val) {
    DS_Node<T>* curr = list.get_head();
    while(curr != nullptr) {
        if(curr -> get_data() == val)
            return true;
        curr = curr -> get_next();
    }
    return false;
}

#endif // DS_STACK_H
