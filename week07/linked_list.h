#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stddef.h>
#include <iostream>

template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext)
    {
        val = pVal;
        next = pNext;
    };

    T get_val() {return val;};
    void set_val(T pVal) {val = pVal;};
    Node<T> *get_next() {return next;};
    void set_next(Node<T> *pNext) {next = pNext;};
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;

public:
    ~LinkedList()
    {
        // to be implemented
    };
    LinkedList()
    {
        head = NULL;
    };

    int length()
    {
        int length = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->get_next();
        }
        return length;
    };

    void print()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            std::cout << ptr->get_val() << ", ";
            ptr = ptr->get_next();
        }
        std::cout << std::endl;
    }

    void push(T pVal)
    {
        Node<T> *node = new Node<T>(pVal, head);
        head = node;
    };

    void append(T pVal)
    {
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL)
        {
            ptr = ptr->get_next();
        }
        Node<T> *node = new Node<T>(pVal, NULL);
        ptr->set_next(node);
    };

    int insert_item(T pVal, int index)
    {
        if (index > length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            push(pVal);
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        Node<T> *node = new Node<T>(pVal, ptr);
        pre->set_next(node);
        return 1;
    };

    bool is_empty()
    {        
        return head == NULL;
    };

    int delete_item(int index)
    {
        if (is_empty())
            return -1;
        if (index >= length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->get_next();
            delete temp;
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr->get_next() != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        pre->set_next(ptr->get_next());
        delete ptr;
        return 1;
    };

    int get_nth(int index, T &item)
    {
        if (index < 0)
            return -1;
        if (index >= length())
            return -2;
            
        int i = 0;
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL && index > i)
        {
            ptr = ptr->get_next();
            i++;
        }
        item = ptr->get_val();
        return 1;
    };

    int count(T val)
    {
        int counter = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->get_val() == val)
                counter++;
            ptr = ptr->get_next();
        }
        return counter;
    }

    void delete_list()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            Node<T> *nextn = ptr->get_next();
            delete ptr;
            ptr = nextn;
        }
        head = NULL;        
    }

    // 1 2 5 7 7 8 14 25
    void sorted_insert(T val)
    {
        if (is_empty())
        {
            push(val);
            return;
        }

        int pos = 0;
        Node<T> *ptr = head;
        while (ptr != NULL && ptr->get_val() < val)
        {
            ptr = ptr->get_next();
            pos++;
        }
        insert_item(val, pos);
    }

    // 1 2 5 8 14 25 NULL
    void sorted_insert(Node<T> *node)
    {
        if (is_empty())
        {
            head = node;
            node->set_next(NULL);
            return;
        }

        Node<T> *ptr = head;
        while (ptr->get_next() != NULL && ptr->get_next()->get_val() < node->get_val())
        {
            ptr = ptr->get_next();
        }
        node->set_next(ptr->get_next());
        ptr->set_next(node);
    }

    // input: 1 2 2 2 2 2 4 4 5 6 7 7 7
    // output: 1 2 4 5 6 7 NULL
    void remove_duplicates()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->get_next() != NULL && ptr->get_val() == ptr->get_next()->get_val())
            {
                Node<T> * temp = ptr->get_next()->get_next();
                delete ptr->get_next();
                ptr->set_next(temp);
            }
            else
            {
                ptr = ptr->get_next();
            }            
        }
    }

    // 1 -> 2 -> 4 -> 2 -> 65 -> 3
    // 1 <- 2 <- 4
    void reverse()
    {
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL)
        {
            Node<T> *aux = ptr->get_next(); 
            ptr->set_next(pre);
            pre = ptr;
            ptr = aux;
        }
        head = pre;
    }
};

#endif