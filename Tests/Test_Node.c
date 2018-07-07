#include "../Headers/Base.h"

void Test_Node()
{
    Node * node     = Node_Manager.create();
    Node * node1    = Node_Manager.create();

    node->data_ptr  = malloc(6*sizeof(char));
    node1->data_ptr = malloc(6*sizeof(char));

    strcpy(node->data_ptr,"Andre");
    strcpy(node1->data_ptr,"Yuhai");

    printf("Name\t: %s\n",(char *)node->data_ptr);
    printf("Surname\t: %s\n",(char *)node1->data_ptr);

    Node_Manager.destroy(node);
    Node_Manager.destroy(node1);

}