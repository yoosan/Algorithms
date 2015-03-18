//
//  queue.cpp
//  Datastructure and Algorithms
//
//  Created by zhou on 3/18/15.
//  Copyright (c) 2015 SecondDim. All rights reserved.
//

#include "queue.h"

template <class T>
queue<T>::queue() : _(new T[_CAP], size(0), _cap(_CAP)) {}

template <class T>
queue<T>::queue(const queue &q) : _(new T[_CAP]),_size(q._size),_cap(q._cap){
    for (int i = 0; i < q._size; i++)
        _[i] = q._[i];
}

template <class T>
queue<T> :: ~queue(){
    delete []_;
}

template <class T>
queue<T>& queue<T> :: operator=(const queue& q){
    _ = new T[q._size];
    _size = q._size;
    _cap = q._cap;
    
    for (int i = 0; i < _size; i++){
        _[i] = q._[i];
    }
}

template <class T>
int queue<T>::size() const{
    return _size;
}

template <class T>
bool queue<T> :: empty() const{
    return _size == 0;
}

template <class T>
T& queue<T>::front(){
    return _[_size - 1];
}

template <class T>
void queue<T>::pop(){
    --_size;
}

template <class T>
void queue<T>::push(const T &data){
    if(_size == _cap) rebuild();
    else _[++_size] = data;
}

template <class T>
void queue<T> :: rebuild(){
    _cap *= 2;
    T* temp = new T[_cap];
    for (int i = 0; i < _size; i++)
        temp[i] = _[i];
    delete [] _;
    _ = temp;
}


