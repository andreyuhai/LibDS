#ifndef LIBDS_LINKEDLIST_H
#define LIBDS_LINKEDLIST_H

#include "Base.h"

typedef struct LinkedListManager LinkedListManager;

struct LinkedListManager
{
    Node *  (* create)      (size_t number_of_nodes);
    void    (* append)      (Node * root, Node * tail);
    size_t  (* size)        (Node * root);
    void    (* destroy)     (Node * root);
    void    (* delete)      (Node * root, size_t node_number);

};

const LinkedListManager LinkedList_Manager;

#endif //LIBDS_LINKEDLIST_H
