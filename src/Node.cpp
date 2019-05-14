#include "Node.h"
#include <cstddef>

template<class T>
Node<T>::Node(const T& anItem) : item(anItem), next(nullptr) {}

template <class T>
Node<T>::Node(const T &anItem, Node<T> *nextNodePtr) :
    item(anItem), next(nextNodePtr) {}

template<class T>
void Node<T>::setItem(const T& anItem)
{
    item = anItem;
}

template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
    next = nextNodePtr;
}

template<class T>
T Node<T>::getItem() const
{
    return item;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}
