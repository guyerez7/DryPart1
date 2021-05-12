#include <stdio.h>
#include <stdbool.h>

typedef struct node_t {
        int x;
        struct node_t *next;
    } *Node;

typedef enum {
    SUCCESS=0,
    MEMORY_ERROR,
    UNSORTED_ERROR,
    NULL_ARGUMENT,
} ErrorCode;
    
int getListLength(Node list);
bool isListSorted(Node list);
Node createNode(int x, ErrorCode* error_code);
int placeAndPromote(int xx, Node* ptr_list, Node merged_list);


Node mergeSortedLists(Node list1, Node list2, ErrorCode* error_code)
{
    if(getListLength(list1) == 0 || getListLength(list2) == 0){    
        error_code = NULL_ARGUMENT;
        return NULL;
    }
    if(isListSorted(list1) == false || isListSorted(list2) == false){
        error_code = UNSORTED_ERROR;
        return NULL;
    }

    Node *ptr_list1 = &list1, *ptr_list2 = &list2;
    Node *ptr_start = getMin((*ptr_list1)->x, (*ptr_list2)->x);
   
    int xx = 0;
	while((*ptr_list1)->next != NULL && (*ptr_list2)->next != NULL) {
        
        Node merged_list = createNode(xx,error_code);
        if(merged_list == NULL){
            return NULL;
        }

        if((*ptr_list1)->x <= (*ptr_list2)->x) { 
            xx = placeAndPromote(xx, ptr_list1, merged_list);
        }
        else{
            xx = placeAndPromote(xx, ptr_list2, merged_list);
        }
        
	} 
    // filling the tail
    if((*ptr_list1)->next == NULL){
        while((*ptr_list1)->next != NULL){
            Node merged_list = createNode(xx,error_code);
            if(merged_list == NULL){
                return NULL;
            }
            xx = placeAndPromote(xx, ptr_list1, merged_list);
        }
    }
    else{
         while((*ptr_list2)->next != NULL){
            Node merged_list = createNode(xx,error_code);
            if(merged_list == NULL){
                return NULL;
            }
            xx = placeAndPromote(xx, ptr_list2, merged_list); 
        }
    }
    error_code = SUCCESS;
    return *ptr_start;
}

Node createNode(int x, ErrorCode* error_code){
    Node merged_list = malloc(sizeof(Node));
    if(merged_list == NULL) { // we must return NULL also in th main function
        error_code = MEMORY_ERROR;
        return NULL;
    }
    merged_list->x = x;
    merged_list->next = NULL;
    return merged_list;
}

int placeAndPromote(int xx, Node* ptr_list, Node merged_list){
    xx = (*ptr_list)->x;
    merged_list->next = *ptr_list;
    *ptr_list = (*ptr_list)->next; 
    return xx;
}


int getMin(int num1, int num2)
{
    return (num1<=num2) ? num1 : num2;
}