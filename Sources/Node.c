#include "../Headers/Foundation.h"


static Node * __create    ()
{
    Node * node   = malloc(sizeof(Node));

    node->previous  = nullptr;
    node->next      = nullptr;

    return node;
}

static void     __destroy   (Node * node)
{
    free(node->data_ptr);

    node->data_ptr  = nullptr;
    node->next      = nullptr;
    node->previous  = nullptr;

    free(node);
}

const NodeManager Node_Manager =
        {
                .create     = &__create,
                .destroy    = &__destroy,
        };
