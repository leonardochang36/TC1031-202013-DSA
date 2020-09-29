#ifndef _QUEUE_H
#define _QUEUE_H

#include "linked_list.h"

template <class T>
class Queue : public LinkedList<T>
{
public:
    ~Queue() {};
    Queue() {};

    void enqueue(T val)
    {
        this->push(val);
    };

    T dequeue()
    {
        // devolver el elemento del inicio
        Node<T> *ptr = this->head;

        if (ptr == NULL)
        {
            throw "Queue is empty";
            // throw 20;
        }

        if (ptr->get_next() == NULL)
        {
            T res = ptr->get_val();
            delete ptr;
            this->head = NULL;
            return res;
        }

        Node<T> *pre = NULL;
        while (ptr->get_next() != NULL)
        {
            pre = ptr;
            ptr = ptr->get_next();        
        }
        T res = ptr->get_val();

        // eliminar el elemento del inicio
        delete ptr;
        pre->set_next(NULL);

        return res;
    };

protected:
    using LinkedList<T>::push;
    using LinkedList<T>::insert_item;
    using LinkedList<T>::delete_item;
    using LinkedList<T>::append;
    using LinkedList<T>::get_nth;
};


#endif