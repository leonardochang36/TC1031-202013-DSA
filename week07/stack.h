#ifndef _STACKS_H
#define _STACKS_H

#include "linked_list.h"

template <class T>
class Stack : public LinkedList<T>
{
public: 
    ~Stack() {};
    Stack() {};

    T pop()
    {
        if (this->is_empty())
        {
            throw "Stack is empty";
        }
        
        T res = this->head->get_val();
        this->delete_item(0);
        return res;
    };

    T peek()
    {
        if (this->is_empty()) {
            throw "Stack is empty";
        }
        return this->head->get_val();
    }

protected:
    using LinkedList<T>::insert_item;
    using LinkedList<T>::delete_item;
    using LinkedList<T>::append;
    using LinkedList<T>::get_nth;
};

#endif