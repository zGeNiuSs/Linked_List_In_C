#include "linkedlist_ds.c"
#define SINGLE_LINKED_LIST   //COMMENTING TO DOUBLE_LINKED_LIST

node_s_t *Node1;

int main(){

    int SizeOfList=0;
    int num;
    int data;
    int position;
    int exit=1;
   
   
    #ifdef SINGLE_LINKED_LIST
    
    while (exit)
    {
        printf("\n////////////////////////////////\n");
        printf("// Menu of Single Linked List //");
        printf("\n////////////////////////////////\n");
        printf("1: insert_node_at_beginning.\n");
        printf("2: insert_node_at_end.\n");
        printf("3: insert_node_after.\n");
        printf("4: delete_node_at_beginning.\n");
        printf("5: delete_node.\n");
        printf("6: display_all_nodes.\n");
        printf("7: get_length.\n");
        printf("8: Exit program.\n");
        printf("\nEnter your choice : ");
        scanf("%i",&num);
        
        switch(num){
            
            case 1:
                printf("Enter the number you want to put in the node : ");
                scanf("%i",&data);
                insert_node_at_beginning(&Node1, data);
                printf("Insert a node at beginning successfully.\n");
                break;
            
            case 2:
                printf("Enter the number you want to put in the node : ");
                scanf("%i",&data);
                insert_node_at_end(&Node1, data);
                printf("Insert a node at end successfully.\n");
                break;
            
            case 3:
                printf("Enter the position of the node (from 1) : ");
                scanf("%i",&position);
                printf("Enter the number you want to put in the node : ");
                scanf("%i",&data);
                insert_node_after(Node1, data, position);
                break;
            
            case 4:
                delete_node_at_beginning(&Node1);
                printf("Delete a node at beginning successfully.\n");
                break;
            
            case 5:
                printf("Enter the position of the node (from 1) : ");
                scanf("%i",&position);
                if (position==1)
                    delete_node_at_beginning(&Node1);
                else
                    delete_node(Node1, position);     
                break;

            case 6:
                display_all_nodes(Node1);
                printf("Display all nodes successfully.\n");
                break;

            case 7:
                SizeOfList=get_length(Node1);
                printf("Length of List is %i elements.\n",SizeOfList);
                break;

            case 8:
                exit = 0;
                break;

            default :
                printf("\nInvalid Choice. Please enter again.");
        }
    }
    
    #else

    while (exit)
    {
        printf("\n////////////////////////////////\n");
        printf("\n// Menu of Double Linked List //\n");
        printf("\n////////////////////////////////\n");
        printf("1: insert_node_at_beginning.\n");
        printf("2: insert_node_at_end.\n");
        printf("3: insert_node_after.\n");
        printf("4: insert_node_before.\n");
        printf("5: delete_node_at_beginning.\n");
        printf("6: delete_node_at_end.\n");
        printf("7: delete_node_at_intermediate.\n");
        printf("8: display_all_nodes_forward.\n");
        printf("9: display_all_nodes_reverse.\n");
        printf("10: get_length.\n");
        printf("11: Exit program.\n");
        printf("\nEnter your choice : ");
        scanf("%i",&num);
        
        switch(num){
            
            case 1:
                printf("Enter the number you want to put in the node : ");
                scanf("%i",&data);
                insert_node_at_beginning(&Node1, data);
                printf("Insert a node at beginning successfully.\n");
                break;
            
            case 2:
                printf("Enter the number you want to put in the node : ");
                scanf("%i",&data);
                insert_node_at_end(&Node1, data);
                printf("Insert a node at end successfully.\n");
                break;
            
            case 3:
                printf("Enter the position of the node (from 1) : ");
                scanf("%i",&position);
                printf("Enter the number you want to put in the node : ");
                scanf("%i",&data);
                insert_node_after(Node1, data, position);
                break;
            
            case 4:
                delete_node_at_beginning(&Node1);
                printf("Delete a node at beginning successfully.\n");
                break;
            
            case 5:
                printf("Enter the position of the node (from 1) : ");
                scanf("%i",&position);
                if (position==1)
                    delete_node_at_beginning(&Node1);
                else
                    delete_node(Node1, position);     
                break;

            case 6:
                display_all_nodes(Node1);
                printf("Display all nodes successfully.\n");
                break;

            case 7:
                SizeOfList=get_length(Node1);
                printf("Length of List is %i elements.\n",SizeOfList);
                break;

            case 8:
                exit = 0;
                break;

            default :
                printf("\nInvalid Choice. Please enter again.");
        }
    }

    #endif //LINKEDLIST_MODE


    return 0; 
}