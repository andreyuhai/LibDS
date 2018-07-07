#include "../Headers/Base.h"

static Node *   __create    (size_t number_of_nodes)
{
    if(!number_of_nodes)
        return NULL;

    Node * root = Node_Manager.create();

    size_t i;

    for (i = 1; i < number_of_nodes; i++) {
        Node * tail = Node_Manager.create();
        LinkedList_Manager.append(root,tail);
    }

    return root;
}

static void     __append    (Node * root, Node * tail)
{
    Node * temp = root;

    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = tail;
    tail->previous = temp;
}

static size_t   __size      (Node * root)
{
    Node * temp = root;
    size_t size = 0;

    while(temp)
    {
        size++;
        temp = temp->next;
    }

    return size;
}

static void     __destroy   (Node * root)
{
    Node * temp = root;
    while(temp)
    {
        if(temp->next)
        {
            temp = temp->next;
            Node_Manager.destroy(temp->previous);
        }
        else
        {
            Node_Manager.destroy(temp);
            return;
        }
    }
}

const LinkedListManager LinkedList_Manager =
        {
                .append     = &__append,
                .create     = &__create,
                .size       = &__size,
                .destroy    = &__destroy,
        };