#include "linkedlist_ds.h"
#define SINGLE_LINKED_LIST //COMMENTING TO DOUBLE_LINKED_LIST

#ifdef SINGLE_LINKED_LIST

void insert_node_at_beginning(node_s_t **My_List, int data){
    node_s_t *tempNode=NULL;
    
    tempNode = (node_s_t*)malloc(sizeof(node_s_t));
    if (tempNode==NULL)
    {
        printf("The TempNode not created.\n");
    }else{
            (tempNode->data)=data;

        if (*My_List==NULL)
        {
            tempNode->linker = NULL;     //point to the next element in the list
            (*My_List)=tempNode;         //set the new node as the first one of the list
        }
        else{
            tempNode->linker = *My_List;  //point to the next element in the list
            (*My_List)=tempNode;            //set the new node as the first one of the list
        }
    }
}

void insert_node_at_end(node_s_t **My_List, int data){
    node_s_t *tempNode=NULL;
    node_s_t *lastNode=NULL;
    
    tempNode = (node_s_t*)malloc(sizeof(node_s_t));
   
    if (tempNode==NULL)
    {
        printf("The Node not created.\n");
    }else{
        (tempNode->data) = data;
        (tempNode->linker) = NULL;

        if (*My_List==NULL)
        {
            (*My_List)=tempNode;         //set the new node as the first one of the list
        }else{
            lastNode = *My_List;
            while ((lastNode->linker) != NULL)
            {
                lastNode = (lastNode->linker);
            }
            lastNode->linker = tempNode;  //point to the next element in the list
        }
    }
}

void insert_node_after(node_s_t *My_List, int data, int nodePosition){
    node_s_t *tempNode=NULL;
    node_s_t *beforeNode=NULL;
 
    if(nodePosition > get_length(My_List)){
        printf("Wrong Number of position!\n");
    }
    else{
        beforeNode = My_List;
        while (nodePosition > 1)
        {
            beforeNode = beforeNode->linker;
            nodePosition--;
        }
        
        tempNode = (node_s_t*)malloc(sizeof(node_s_t));
    
        if (tempNode==NULL)
        {
            printf("The Node not created.\n");
        }else{
            tempNode->data = data;
            tempNode->linker = beforeNode->linker;
            beforeNode->linker = tempNode;
            printf("Insert a node after position successfully.\n");
        }
    }
}

void delete_node_at_beginning(node_s_t **My_List){
    node_s_t *tempNode=NULL;
    
    if (*My_List==NULL)
    {
        printf("The List is Empty.\n");
    }
    else{
        tempNode = (*My_List);
        (*My_List) = tempNode->linker;
        tempNode->linker = NULL;
        free(tempNode);
    }
}

void delete_node(node_s_t *My_List, int nodePosition){
    node_s_t *tempNode=NULL;
    node_s_t *beforeNode=NULL;
    
    if (My_List==NULL)
    {
        printf("The List is Empty.\n");
    }else{
        if(nodePosition > get_length(My_List)){
            printf("Wrong Number of position!\n");
        }
        else{
            beforeNode = My_List;
            while ((nodePosition-1) > 1)
            {
                beforeNode = beforeNode->linker;
                nodePosition--;
            }
            tempNode = beforeNode->linker;
            beforeNode->linker = tempNode->linker;
            tempNode->linker =  NULL;
            free(tempNode);
            printf("Delete a node in position successfully.\n");
        }
    }
}

void display_all_nodes(node_s_t *My_List){
    node_s_t *tempNode=NULL;
    if (My_List==NULL)
    {
        printf("The List is Empty.\n");
    }
    else{
        tempNode = My_List;
        while (tempNode != NULL)
        {
            printf("%i >> ",tempNode->data);
            tempNode = tempNode->linker;
        }
        printf("Null\n");
    }
}

int get_length(node_s_t *My_List){
    node_s_t *tempNode=NULL;
    int counter=1;
    if (My_List==NULL)
    {
        counter=0;
    }
    else{
        tempNode=My_List;
        while (tempNode->linker != NULL)
        {
            tempNode = tempNode->linker;
            counter++;
        }
    }
    return counter;
}

#else

void insert_node_at_beginning(node_d_t **My_List, int data){}
void insert_node_at_end(node_d_t *My_List, int data){}
void insert_node_after(node_d_t *My_List, int data, int nodePosition){}
void insert_node_before(node_d_t **My_List, int data, int nodePosition){}
void delete_node_at_beginning(node_s_t **My_List){}
void delete_node_at_end(node_s_t *My_List){}
void delete_node_at_intermediate(node_s_t *My_List, int nodePosition){}
void display_all_nodes_forward(node_s_t *My_List){}
void display_all_nodes_reverse(node_s_t *My_List){}
int get_length(node_s_t *My_List){}

#endif //LINKEDLIST_MODE




























// void stack_push_func(stack_t* MyStack, int *push_value, stack_status_t *ret)
// {
//     if (MyStack->my_stack == NULL || ret == NULL || push_value == NULL) {
//         /* Stack is not pushed */
//         printf("Error: The stack has not been pushed.\n");
//         *ret = STACK_NOK;
//     }
//     else{
//         if (isFull(MyStack))
//         {
//             *ret = STACK_FULL;
//         }
//         else{
//             /* Stack is pushed */
//             (MyStack->topIndex)++;
//             MyStack->my_stack[MyStack->topIndex] = *push_value;
//             (MyStack->stack_counter)++;
//             *ret = STACK_OK;
//         }
//         if (isFull(MyStack))
//         {
//             *ret = STACK_FULL;
//             printf("I'm Here\n");
//         }  
//     }
// }

// int stack_pop_func(stack_t* MyStack, stack_status_t *ret)
// {
//     int return_value=0;
//     if (MyStack->my_stack == NULL || ret == NULL) {
//         /* Stack is not poped */
//         printf("Error: The stack has not been poped.\n");
//         *ret = STACK_NOK;
//     }
//     else{  
//         if (isEmpty(MyStack))
//         {
//             *ret = STACK_EMPTY;
//         }
//         else{
//             /* Stack is poped */
//             return_value = MyStack->my_stack[MyStack->topIndex];
//             (MyStack->topIndex)--;
//             (MyStack->stack_counter)--;
//             if((MyStack->topIndex)==-1)
//                 *ret = STACK_EMPTY;
//             else
//                 *ret = STACK_OK;
//         }
//     }
//     return  return_value;
// }

// int stack_top_func(stack_t* MyStack, stack_status_t *ret)
// {
//     int return_value = 0;
//     if (MyStack->my_stack == NULL || ret == NULL) {
//         /* Stack is not top value */
//         printf("Error: The stack has not been poped.\n");
//         *ret = STACK_NOK;
//     }
//     else{
//         if (isEmpty(MyStack))
//         {
//             *ret = STACK_EMPTY;
//         }
//         else{
//             /* Stack is top value */
//             return_value = MyStack->my_stack[MyStack->topIndex];
//             *ret = STACK_OK;
//         }
//     }
//     return  return_value;
// }

// stack_t *stack_create_func(int stack_size, stack_status_t *ret)
// {
//     stack_t *MyStack = NULL;
//     MyStack->topIndex == -1;
    
//     if (ret == NULL) {
//         /* Stack is not initialized */
//         printf("Error: The stack has not been initialized.\n");
//         *ret = STACK_NOK;
//         MyStack = NULL;
//     }
//     else{
//         /* Stack is initialized */
//         MyStack = (stack_t *)malloc(sizeof(stack_t));
        
//         MyStack->stack_max = stack_size;
//         MyStack->topIndex = -1;
//         MyStack->stack_counter = 0;

//         MyStack->my_stack = (int *)calloc(MyStack->stack_max, sizeof(int));

//         if (!MyStack->my_stack) {
//             /* Stack is not initialized */
//             printf("Error: The stack has not been initialized.\n");
//             free(MyStack);
//             MyStack = NULL;
//             *ret = STACK_NOK;
//         }else
//         {
//             *ret = STACK_EMPTY;
//         }

//     }
//     return  MyStack;
// }

// void stack_display_func(stack_t* MyStack, stack_status_t *ret)
// {
//     if (MyStack->my_stack == NULL || ret == NULL) {
//         /* Stack is not displayed */
//         printf("Error: The stack has not been displayed.\n");
//         *ret = STACK_NOK;
//     }
//     else{
//         if(isEmpty(MyStack)){
//             printf("The stack is empty!\n");
//             *ret = STACK_EMPTY;
//         }
//         else{
//         /* Stack is displayed */
//         for (int i = 0; i < MyStack->stack_counter; i++)
//         {
//             printf("%d ", MyStack->my_stack[i]);
//         }
//         printf("\n");
//         *ret = STACK_OK;
//         }
//     }
// }

// void  stack_destroy_func(stack_t* MyStack, stack_status_t *ret)
// {
//     if (MyStack->my_stack == NULL || ret == NULL) {
//         /* Stack is not destroied */
//         printf("Error: The stack has not been destroied.\n");
//         *ret = STACK_NOK;
//     }
//     else{
//         /* Stack is destroied */
//         free(MyStack->my_stack);
//         MyStack->my_stack=NULL;
//         free(MyStack);
//         MyStack=NULL;
//         *ret = STACK_OK;
//     }
// }

// int isEmpty(stack_t* MyStack){
//     return (MyStack->topIndex == -1);
// }

// int isFull(stack_t* MyStack){
//     return ((MyStack->topIndex)+1 == MyStack->stack_max);
// }