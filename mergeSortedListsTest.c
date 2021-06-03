#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node_t {
    int x;
    struct node_t *next;
} *Node;

typedef enum {
    SUCCESS=0,
    MEMORY_ERROR,
    UNSORTED_LIST,
    NULL_ARGUMENT,
} ErrorCode;

int getListLength(Node list);
bool isListSorted(Node list);
Node mergeSortedLists(Node list1, Node list2, ErrorCode* error_code);
Node createNode(int x, ErrorCode* error_code);
void destroyMergedList(Node head);
// add necessary declarations here

int getListLength(Node list) {
    int len=0;
    Node i=list;
    while(i){
        len++;
        i=i->next;
    }
    return len;
}

bool isListSorted(Node list) {
    Node i=list;
    while(i && i->next){
        if ((i->x)>(i->next->x))
        {
            return false;
        }
        i=i->next;
    }
    return true;
}

// add necessary functions here (create_node_func, destroy_list_func...)
void destroyMergedList(Node head){
    if(head == NULL){
        return;
    }
    while(head != NULL){
       Node next_node = head->next;
       Node dummy = head;
       head = next_node;
       free(dummy);
    }
}

Node createNode(int x, ErrorCode* error_code){
    Node merged_list = malloc(sizeof(Node));
    if(merged_list == NULL) { // we must return NULL also in th main function
        *error_code = MEMORY_ERROR;
        return NULL;
    }
    merged_list->x = x;
    merged_list->next = NULL;
    return merged_list; //return full node
}

Node mergeSortedLists(Node list1, Node list2, ErrorCode* error_code){
     if(getListLength(list1) == 0 || getListLength(list2) == 0){    
        *error_code = NULL_ARGUMENT;
        return NULL;
    }
    if(isListSorted(list1) == false || isListSorted(list2) == false){
        *error_code = UNSORTED_LIST;
        return NULL;
    }

    Node head_merged_list = createNode(0 ,error_code);
    if(head_merged_list == NULL){
        *error_code = MEMORY_ERROR;
        return NULL;
    }
    Node old_merged_list = head_merged_list;
	while(list1 != NULL && list2 != NULL) {
        
        Node merged_list = createNode(0 ,error_code); // creating a new node
        if(merged_list == NULL){
            destroyMergedList(head_merged_list);
            *error_code = MEMORY_ERROR;
            return NULL;
        }
        old_merged_list->next = merged_list;          // updating previous node -> next
   
        if(list1->x <= list2->x) {                    // if list1->x is bigger than list2->x
            merged_list->x = list1->x;
            old_merged_list = merged_list;
            list1 = list1->next;
        }
        else{                                         // if list2->x is bigger than list1->x
            merged_list->x = list2->x;
            old_merged_list = merged_list;
            list2 = list2->next;
        }  
	} 
    
    while(list1 != NULL){
        Node merged_list = createNode(0 ,error_code);
        if(merged_list == NULL){
            destroyMergedList(merged_list);
            *error_code = MEMORY_ERROR;
            return NULL;
        }
        merged_list->x = list1->x;
        old_merged_list->next = merged_list;
        list1 = list1->next;
    }
    while(list2 != NULL){
        Node merged_list = createNode(0 ,error_code);
        if(merged_list == NULL){
            destroyMergedList(merged_list);
            *error_code = MEMORY_ERROR;
            return NULL;
        }
        merged_list->x = list1->x;
        old_merged_list->next = merged_list;
        list2 = list2->next;

    }
    *error_code = SUCCESS;
    return head_merged_list;
}

// use ctrl+f on "insert_create_node_function" and replace all with your create_node function name
// use ctrl+f on "insert_destroy_list_function" and replace all with your destroy_list function name

int main(){
    ErrorCode* error_code = malloc(sizeof(*error_code));
    *error_code = SUCCESS;
    Node list1 = createNode(2,error_code);
    list1->next = createNode(4,error_code);
    list1->next->next=createNode(9,error_code);
    Node list2 = createNode(2,error_code);
    list2->next = createNode(4,error_code);
    list2->next->next=createNode(8,error_code);
    Node merged_list = mergeSortedLists(list1,list2,error_code);
    printf("\n%d\n\n", *error_code);
    while(merged_list){
        printf("%d\n",merged_list->x);
        merged_list=merged_list->next;
    }
    destroyMergedList(list1);
    destroyMergedList(list2);
    destroyMergedList(merged_list);
    list1 = createNode(1,error_code);
    list1->next = createNode(4,error_code);
    list1->next->next=createNode(9,error_code);
    list2 = createNode(2,error_code);
    list2->next = createNode(5,error_code);
    list2->next->next=createNode(8,error_code);
    merged_list = mergeSortedLists(list1,list2,error_code);
    printf("\n%d\n\n", *error_code);
    while(merged_list){
        printf("%d\n",merged_list->x);
        merged_list=merged_list->next;
    }
    destroyMergedList(list1);
    destroyMergedList(list2);
    destroyMergedList(merged_list);
    list1 = createNode(5,error_code);
    list1->next = createNode(4,error_code);
    list1->next->next=createNode(9,error_code);
    list2 = createNode(2,error_code);
    list2->next = createNode(5,error_code);
    list2->next->next=createNode(8,error_code);
    merged_list = mergeSortedLists(list1,list2,error_code);
    printf("\n%d\n", *error_code);
    while(merged_list){
        printf("%d\n",merged_list->x);
        merged_list=merged_list->next;
    }
    destroyMergedList(list1);
    destroyMergedList(list2);
    destroyMergedList(merged_list);
    list1 = NULL;
    list2 = createNode(2,error_code);
    list2->next = createNode(5,error_code);
    list2->next->next=createNode(8,error_code);
    merged_list = mergeSortedLists(list1,list2,error_code);
    printf("\n%d\n", *error_code);
    while(merged_list){
        printf("%d\n",merged_list->x);
        merged_list=merged_list->next;
    }
    return 0;
}