//
//  queue.h
//  Datastructure and Algorithms
//
//  Created by zhou on 3/18/14.
//  Copyright (c) 2014 SecondDim. All rights reserved.
//

#ifndef Datastructure_and_Algorithms_queue_h
#define Datastructure_and_Algorithms_queue_h

template <class T>
class queue{
public:
    queue();
    queue(const queue&);
    ~queue();
    
    queue& operator=(const queue&);
    int size() const;      //return number of elements in this
    bool empty() const;    //return true if this is empty
    T& front();            //return the front elemnt.
    void push(const T&);
    void pop();
protected:
    T* _;
    int _size;
    int _cap;
    static const int _CAP = 4;
    void rebuild();        //move all queue elements to new array.
};

#endif
