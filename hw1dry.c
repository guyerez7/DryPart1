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
Node finishTailEnd(Node list, Node mergedlist){
    while(list->next != NULL){
        mergedlist->x = list->x;
        mergedlist->next = list->next;
        
        mergedlist = mergedlist->next;
        list = list->next;
    }
    mergedlist->next = NULL;
    
    return mergedlist;
}

Node mergeSortedLists(Node list1, Node list2, ErrorCode* error_code)
{
    if(getListLength(list1) == 0 || getListLength(list2) == 0){    
        return error_code = NULL_ARGUMENT;
    }
    if(isListSorted(list1) == false || isListSorted(list2) == false){
        return error_code = UNSORTED_ERROR;
    }

    //(*ptrlist1)->next;
    Node *ptrlist1 = &list1, *ptrlist2 = &list2, *ptrnext = NULL;
    //Node mergedlist
    int xx = 0;

	while((*ptrlist1)->next != NULL && (*ptrlist2)->next != NULL) {
        
        Node merged_list = createNode(xx,error_code);
        if((*ptrlist1)->x <= (*ptrlist2)->x) {
            xx = (*ptrlist1)->x;
            merged_list->next = *ptrlist1;
            *ptrlist1 = (*ptrlist1)->next; 
        }
        else{
            xx = (*ptrlist2)->x;
            merged_list->next = *ptrlist2;
            *ptrlist2 = (*ptrlist2)->next;
        }
        
	} 
    
    finishTailEnd() // we must define and use (to fill merged tail)
}

Node createNode(int x, ErrorCode* error_code){
    Node merged_list = malloc(sizeof(Node));
    if(merged_list == NULL) {
        error_code = MEMORY_ERROR;
        return NULL;
    }
    merged_list->x = x;
    merged_list->next = NULL;
    error_code = SUCCESS;    //  check if really necessery
    return merged_list;
}

