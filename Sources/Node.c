#include "../Headers/Base.h"


static Node *   __create    ()
{
    Node * node   = calloc(1, sizeof(Node));

    node->previous  = NULL;
    node->next      = NULL;

    return node;
}

static void     __destroy   (Node * node)
{
    free(node->data_ptr);

    node->data_ptr  = NULL;
    node->next      = NULL;
    node->previous  = NULL;

    free(node);
}

const NodeManager Node_Manager =
        {
                .create     = &__create,
                .destroy    = &__destroy,
        };
