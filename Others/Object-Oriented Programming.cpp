#include <iostream>
#include <vector>
using namespace std;


//Defination and simple implement of DataStructure Stack
template <class T>
class Stack
{
private:
    int size;
    int top;
    T * space;
public:
    Stack(int = 10);
    virtual ~Stack()
    {
        delete []space;
    }
    bool push(const T &);
    T pop();
    bool isEmpty() const
    {
        return top == size;
    }
    bool isFull() const
    {
        return top == 0;
    }
    int Size() const
    {
        if (!isEmpty())
            return size - top;
        else
            return 0;
    }
};
template<class T>

Stack<T>::Stack(int size)
{
    this -> size = size;
    space = new T[size];
    top = size;
}

template <class T>
bool Stack<T>::push(const T &element)
{
    if (!isFull())
    {
        space[--top] = element;
        return true;
    }
    return false;
}

template <class T>
T Stack<T>::pop()
{
    if (!isEmpty())
    {
        return space[top++];
    }
    return 0;
}
//End of Satck

//Defination and simple implement of List
template <class TYPE>
class List {
private:
    TYPE data;
    List * next;
    int count;
    static List * CurNode;
    static List * head;
public:
    List()
    {
        next = NULL;
        head = CurNode = this;
    }
    List(TYPE newdata)
    {
        data = newdata;
        next = NULL;
    }
    virtual ~List()
    {
    }
    
    void append(TYPE newnode);
    void DisplayList() ;
    void DelList();
};

template <class TYPE>
List<TYPE> * List<TYPE>::CurNode;
template <class TYPE>
List<TYPE> * List<TYPE>::head;

template <class TYPE>
void List<TYPE>::append(TYPE newdata)
{
    CurNode->next = new List(newdata);
    CurNode = CurNode ->next;
}

template <class TYPE>
void List<TYPE>::DisplayList()
{
    CurNode = head ->next;
    while (CurNode != NULL)
    {
        cout << CurNode ->data <<endl;
        CurNode = CurNode ->next;
    }
}

template <class TYPE>
void List<TYPE>::DelList()
{
    List *q;
    CurNode = head ->next;
    while (CurNode != NULL)
    {
        q = CurNode ->next;
        delete CurNode;
        CurNode = q;
    }
    head ->next = NULL;
}
//End of List


class A
{
public:
    explicit A(){ cout << "Constructor A" << endl;}
    virtual ~A() { cout << "Destrcutior A" << endl;}
    virtual void fun() { cout << "fun AAA" <<endl;}
    virtual void vr() = 0;
};

class B : public A
{
public:
    B() {cout << "Constructor B" <<endl;}
    ~B() {cout << "Destructor B"<<endl;}
    void fun(){cout <<"fun BBB" <<endl;}
    void vr(){cout << "vrrr" <<endl;}
};

int main()
{
    /*Stack<char> s(5);
    s.push('x');
    s.push('y');
    s.push('z');
    cout << s.Size()<<endl;
    cout << s.pop()<<endl;
    cout << s.Size()<<endl;
    
    List<int> l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.DisplayList();
     */
    
    A *a = new B;
    a->fun();
    a->vr();
    delete a;
    return 0;
}