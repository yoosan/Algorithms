//
//  stack.h
//
//  Datastructure and algorithms
//  Created by Cliviazhou on 3/18/14.
//  Copyright (c) 2014 Dimen. All rights reserved.
//

#ifndef DSA_stack_h
#define DSA_stack_h

template <class T>

class stack{
public:
    //  Default constructor, copy constructor and destrustor.
    stack();
    stack(const stack&);
    ~stack();
    
    stack& operator=(const stack&);
    int size() const;
    bool empty() const;
    T& top();
    void push(const T&);
    void pop();
    
protected:
    //  The Node structure is a node of linkedlist.
    struct Node{
        Node(const T&data, Node* next = 0): _data(data),_next(next){}
        T _data;
        Node *_next;
    };
    Node *_top;
    int _size;
};

#endif
