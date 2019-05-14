#ifndef _NODE_H
#define _NODE_H

template<class T>
class Node
{
private:
    T        item;
    Node<T>* next;
public:
    Node() {}
    Node(const T& anItem);
    Node(const T &anItem, Node<T> *nextNodePtr);
    void setItem(const T& anItem);
    void setNext(Node<T>* nextNodePtr);
    T getItem() const;
    Node<T>* getNext() const;
};

#include "Node.cpp"
#endif // _NODE_H
