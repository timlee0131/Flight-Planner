#ifndef DS_ADJNODE_H
#define DS_ADJNODE_H

#include "DS_Node.h"
#include "DS_Linklist.h"

template <class T> class DS_AdjNode {
template <class U> friend class DS_AdjList;
private:
    T data;
    DS_Linklist<T> edges;
    DS_AdjNode<T>* next;
    DS_AdjNode<T>* prev;
public:
    DS_AdjNode();
    DS_AdjNode(T);
    void insert_AdjNode(const T);
    DS_Linklist<T>& get_edges();
    DS_AdjNode<T>*& get_next();
    DS_AdjNode<T>*& get_prev();
    T& get_data();
};

template <class T>
DS_AdjNode<T>::DS_AdjNode() {
    next = prev = nullptr;
}

template <class T>
DS_AdjNode<T>::DS_AdjNode(T val) {
    data = val;
    next = nullptr;
    prev = nullptr;
}

template <class T>
void DS_AdjNode<T>::insert_AdjNode(const T val) {
    edges.insert_back(val);
}

template <class T>
T& DS_AdjNode<T>::get_data() {
    return data;
}

//Getters:-----
template <class T>
DS_Linklist<T>& DS_AdjNode<T>::get_edges() {
    return edges;
}

template <class T>
DS_AdjNode<T>*& DS_AdjNode<T>::get_next() {
    return next;
}

template <class T>
DS_AdjNode<T>*& DS_AdjNode<T>::get_prev() {
    return prev;
}

#endif
