//
//  stack.cpp
//  Datastructure and algorithms
//
//  Created by Cliviazhou on 3/18/14.
//  Copyright (c) 2014 Dimen. All rights reserved.
//

#include "stack.h"

//  Default Constructor of stack.
template <class T>
stack<T>::stack() : _top(0), _size(0){}

//  Copy Constructor of stack.
template <class T>
stack<T>::stack(const stack& s) : _top(0), _size(s._size){
    if (_size == 0) return;
    
    Node* temp = 0;
    for (Node* p = s._top; p ; p = p ->_next){
        
        if (p == s._top) temp = _top = new Node(p->_data);
        else temp = temp -> _next = new Node(p->_data);
    }
}

//  Destructor of stack.
template <class T>
stack<T>::~stack(){
    while (_top){
        Node *p = _top;
        _top = _top -> _next;
        delete p;
    }
}

//  Member function size(), return the size of stack.
template <class T>
int stack<T>::size() const{
    return _size;
}

// Member function empty(), return true only if size equal to 0.
template <class T>
bool stack<T>::empty() const{
    return _size == 0;
}

// Member function top(), return the top element of the stack.
template <class T>
T& stack<T>::top(){
    return _top -> _data;
}

// Member function pop(), remove the top element of the stack.
template <class T>
void stack<T>::pop(){
    Node *p = _top;
    _top = _top -> _next;
    delete p;
    --_size;
}

// Member function push(), push a element to the top of stack.
template <class T>
void stack<T>::push(const T& data){
    if (_size == 0) _top = new Node(data);
    else _top = new Node(data, _top);
    ++_size;
}
