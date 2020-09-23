#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>();
    Node<T>(T pVal, Node<T> *pNext);

    T get_val();
    void set_val(T pVal);
    Node<T> *get_next();
    void set_next(Node<T> *pNext);
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    ~LinkedList();
    LinkedList();

    int length();
    void push(T pVal);
    void append(T pVal);
    int insert_item(T pVal, int index);
    int delete_item(int index);
    T get_nth(int index);

};

#endif