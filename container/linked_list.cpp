#ifdef LINKED_LIST_H_INCLUDED

template <typename T>
void LinkedList<T>::add(T value){
    Node *n = new Node();
    n->value = value;
    n->next = head;

    head = n;
    _size++;
}

template <typename T>
T LinkedList<T>::pop(){
    {
        try{
            if ( _size == 0 ) throw _size;
        }

        catch(int){
            std::cerr << "Error: stack underflow" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    Node *n = head;
    T ret = n->value;

    head = head->next;
    _size--;
    delete n;
    return ret;
}

template <typename T>
T LinkedList<T>::peek(){
    return head->value;
}


#endif // LINKED_LIST_H_INCLUDED
