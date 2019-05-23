#ifndef DS_NODE_H
#define DS_NODE_H

template <class T> class DS_Node {
template <class U> friend class DS_Linklist;
private:
    T data;
    DS_Node<T>* next;
    DS_Node<T>* prev;
public:
    DS_Node();
    DS_Node(T);
    DS_Node(DS_Node<T>*);

    DS_Node<T>*& get_next();
    DS_Node<T>*& get_prev();
    T& get_data();
};

template <class T>
DS_Node<T>::DS_Node() {
    next = prev = nullptr;
}

template <class T>
DS_Node<T>::DS_Node(DS_Node<T>* copy_node) {
    this -> data = copy_node -> data;
    this -> next = nullptr;
    this -> prev = nullptr;
}

template <class T>
DS_Node<T>::DS_Node(T val) {
    next = prev = nullptr;
    data = val;
}

template <class T>
DS_Node<T>*& DS_Node<T>::get_next() {
    return next;
}

template <class T>
DS_Node<T>*& DS_Node<T>::get_prev() {
    return prev;
}

template <class T>
T& DS_Node<T>::get_data() {
    return data;
}

#endif
