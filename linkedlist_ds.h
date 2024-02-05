#ifndef LINKEDLIST_DS_H 
#define LINKEDLIST_DS_H 
#define SINGLE_LINKED_LIST //COMMENTING TO DOUBLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_types.h"

#ifdef SINGLE_LINKED_LIST
void insert_node_at_beginning(node_s_t **My_List, int data);
void insert_node_at_end(node_s_t **My_List, int data);
void insert_node_after(node_s_t *My_List, int data, int nodePosition);
void delete_node_at_beginning(node_s_t **My_List);
void delete_node(node_s_t *My_List, int nodePosition);
void display_all_nodes(node_s_t *My_List);
int get_length(node_s_t *My_List);

#else
void insert_node_at_beginning(node_d_t **My_List, int data);
void insert_node_at_end(node_d_t *My_List, int data);
void insert_node_after(node_d_t *My_List, int data, int nodePosition);
void insert_node_before(node_d_t **My_List, int data, int nodePosition);
void delete_node_at_beginning(node_s_t **My_List);
void delete_node_at_end(node_s_t *My_List);
void delete_node_at_intermediate(node_s_t *My_List, int nodePosition);
void display_all_nodes_forward(node_s_t *My_List);
void display_all_nodes_reverse(node_s_t *My_List);
int get_length(node_s_t *My_List);


#endif //LINKEDLIST_MODE

#endif //LINKEDLIST_DS_H