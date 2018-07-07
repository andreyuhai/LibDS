#include "../Headers/Base.h"

void Test_Append()
{
    Node * node     = Node_Manager.create();
    Node * node1    = Node_Manager.create();

    node->data_ptr  = malloc(6*sizeof(char));
    node1->data_ptr = malloc(6*sizeof(char));

    strcpy(node->data_ptr,"Andre");
    strcpy(node1->data_ptr,"Yuhai");

    LinkedList_Manager.append(node,node1);

    printf("Surname : %s\n",(char*)node->next->data_ptr);

}

void Test_LinkedList_Create()
{
    /* Linked List of Size 0 (Basically returns a NULL pointer) */
    Node * root = LinkedList_Manager.create(0);
    printf("Size : %lu\n",LinkedList_Manager.size(root));


    if(!root)
        printf("NULL pointer was assigned to root.\n");


    /* Linked List of Size 1 */
    root = LinkedList_Manager.create(1);
    printf("Size : %lu\n",LinkedList_Manager.size(root));
    LinkedList_Manager.destroy(root);


    /* Linked List of Size 3 */
    root = LinkedList_Manager.create(3);
    printf("Size : %lu\n",LinkedList_Manager.size(root));
    LinkedList_Manager.destroy(root);
}

void Test_LinkedList_wData()
{
    Node * root = LinkedList_Manager.create(5);
    Node * temp = root;

    size_t i;

    for (i = 0; i < LinkedList_Manager.size(root); i++)
    {

        temp->data_ptr                  = (size_t *) malloc(sizeof(size_t));
        *((size_t *)(temp->data_ptr))   = i;

        temp = temp->next;
    }

    printf("Size of the linked list : %lu\n",LinkedList_Manager.size(root));

    temp = root;

    //Printing the linked list elements forwards
    for (i = 0; i < LinkedList_Manager.size(root); i++)
    {
        printf("Number : %lu\n",*((size_t *)temp->data_ptr));
        if(temp->next)
            temp = temp->next;
    }
    puts("");
    //Printing the linked list elements backwards
    for (i = 0; i < LinkedList_Manager.size(root); i++)
    {
        printf("Number : %lu\n",*((size_t *)temp->data_ptr));
        temp = temp->previous;
    }

    LinkedList_Manager.destroy(root);
}

void Test_LinkedList_Deletion()
{
    Node * root = LinkedList_Manager.create(5);
    Node * temp = root;

    size_t i;

    for (i = 0; i < LinkedList_Manager.size(root); i++)
    {

        temp->data_ptr                  = (size_t *) malloc(sizeof(size_t));
        *((size_t *)(temp->data_ptr))   = i;

        temp = temp->next;
    }

    LinkedList_Manager.delete(root,3);

}

