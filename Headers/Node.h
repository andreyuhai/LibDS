#ifndef LIBDS_NODE_H
#define LIBDS_NODE_H

#include "Base.h"

typedef struct Node         Node;
typedef struct NodeManager  NodeManager;

struct Node
{
    void *  data_ptr;
    Node *  next;
    Node *  previous;
};

struct NodeManager
{
    Node *  (* create)  ();
    void    (* destroy) (Node * node);

};

const NodeManager Node_Manager;


#endif //LIBDS_NODE_H
