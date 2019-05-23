#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <iostream>
using namespace std;

template <class T> class DSVector {
private:
    T* data;        //Pointer array to type T.
    int capacity;   //capacity >= size
    int size;       //index of the last element

    //private functions:
    void resize();
public:
    DSVector();                         //Empty. Size = 0; Capacity = 5;
    DSVector(const DSVector<T>&);
    ~DSVector();

    //Accessors:
    T* getData();                       //These getter functions may not
    int getSize();                      //be needed later in the program.
    int getCapacity();

    //Functionalities including resize:
                                        //Maybe move the condition outside
    void DS_push_back(const T&);        //Push_back should run in constant time
    //void DS_insert(const T&);                 //Inserts in linear time to sorted list.
    bool DS_remove(const T&);
    //T& DS_pop();

    //operator overloading
    //Need operator[](int index)
    //operator = (const vector<T> &vec)
    //Maybe overload ==?
    T& operator[](int);
    DSVector<T>& operator=(const DSVector<T>&);
};

//Constructors:
template <class T>
DSVector<T>::DSVector() {
    data = new T[5];
    size = 0;
    capacity = 5;
}

template <class T>
DSVector<T>::DSVector(const DSVector<T> &vec) {
    //copy constructor
    size = vec.size;
    capacity = vec.capacity;

    delete [] data;
    data = new T[capacity];
    for(int i = 0; i < capacity; i++) {
        data[i] = vec.data[i];
    }//end for
}

//Destructor:
template <class T>
DSVector<T>::~DSVector() {
    delete [] data;
}

//Accessors:
template <class T>
T* DSVector<T>::getData() {return data;}

template <class T>
int DSVector<T>::getSize() {
    int temp = size;
    return temp;
}

template <class T>
int DSVector<T>::getCapacity() {return capacity;}

//Operator overloading:
template <class T>
T& DSVector<T>::operator[](int index) {
    if(index > size) {
        cout << "Index out of bounds..." << endl;
    }
    return data[index];
}

template <class T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T> &vec) {
    size = vec.size;
    capacity = vec.capacity;
    delete [] data;

    data = new T[capacity];
    for(int i = 0; i < capacity; i++) {
        data[i] = vec.data[i];
    }//end for

    return *this;
}

//Functionalities
//void resize();
//void DS_push_back(T&);
//void insert(T&);

template <class T>
void DSVector<T>::resize() {
    if(size == capacity) {      //Maybe put the condition outside later.
        capacity *= 2;
        T *temp = new T[capacity];
        for(int i = 0; i < size; i++) {
            temp[i] = data[i];
        }//end for
        delete [] data;
        data = temp;
        return;
    }//end if
    else
        return;
}

template <class T>
void DSVector<T>::DS_push_back(const T& element) {
    resize();
    data[size++] = element;
}


template <class T>
bool DSVector<T>::DS_remove(const T& element) {
    int index;
    bool flag;
    for(int i = 0; i < size; i++) {
        if(data[i] == element) {
            index = i;
            flag = true;
        }//end if
    }
    if(!flag)   return false;
    for(int i = index; i < size; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return true;
}

//template <class T>
//T& DSVector<T>::DS_pop() {
//    static T temp = data[size];
//    size--;
//    return temp;
//}
#endif // DSVECTOR_H
