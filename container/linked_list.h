#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include <iostream>
#include <stdlib.h>

class POD{
    int _size;

public:
    POD(){ _size = 0; }
    virtual ~POD(){}

    int size(){return _size;}
    bool empty(){return _size == 0 ? true : false;}
};


template <typename T> class LinkedList : public POD{
    struct Node
    {
        T value;
        Node *next;
    };

    Node *head;
    int _size;

public:
    LinkedList()
    {
        head = NULL;
        _size = 0;
    }

    virtual ~LinkedList(){}

    void add(T value);
    T pop();
    T peek();
};


template <typename T> class DoublyLinkedList : public POD{
    struct Node
    {
        T value;
        Node *next;
        Node *prev;
    };

    Node *head;

public:
    DoublyLinkedList():head(NULL)
    {}

    void push_back(T value)
    {
        Node n = new Node();
        n->value = value;

        if (head == NULL){
            head = n;
            head->next = NULL;
        }
        else{
            n->next = head;
            head->prev = n;
            head = n;
        }

        _size++;
    }

    void push_front(T value){
        Node n = new Node();
        n->value = value;

        if (head == NULL){
            head = n;
            head->next = NULL;
        }
        else{
            n->next = head;
            while (head != NULL)
                n = n->next;
            Node node = new Node();
            node->value = value;
            n->next = node;
            node->prev = n;
            node->next = NULL;
        }

        _size++;
    }

    T pop_back(){
        try{
            if ( _size == 0 ) throw _size;
        }

        catch(int){
            std::cerr << "Error: stack underflow" << std::endl;
            exit(EXIT_FAILURE);
        }
        Node *n = head;
        T ret = n->value;
        head = head->next;

        _size--;
        delete n;
        return ret;
    }

    T pop_front(){
        try{
            if ( _size == 0 ) throw _size;
        }

        catch(int){
            std::cerr << "Error: stack underflow" << std::endl;
            exit(EXIT_FAILURE);
        }
        _size--;
    }

    T peek_bask(){
        return head->value;
    }
};

#include "linked_list.cpp"
#endif // LINKED_LIST_H_INCLUDED
