#ifndef LINKEDLIST_TYPES_H 
#define LINKEDLIST_TYPES_H 

//For single Linked List
typedef struct nodeS
{
    int data;
    struct nodeS *linker;
}node_s_t;

//For double Linked List
typedef struct nodeD
{
    int data;
    struct nodeD *left_linker;
    struct nodeD_t *right_linker;
}node_d_t;


#endif //LINKEDLIST_TYPES_H